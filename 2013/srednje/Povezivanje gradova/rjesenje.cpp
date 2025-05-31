#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <cstring>
#include <ctime>

using namespace std;

struct Point
{
	int x;
	int y;
	int id;
};

int N;
vector<Point> *P;
int max_id;

void Inicijalizacija(int n, int m[])
{
  N = n;
  P = new vector<Point>[n];
  for (int i = 0; i < n; i++)
    P[i].reserve(m[i]);
  max_id = -1;
}

void PostaviKucu(int i, int x, int y) {
  if (P[i].size() == 0)
    P[i].push_back(Point({x, y, 0}));
  else
    P[i].push_back(Point({x, y, P[i].back().id+1}));
  max_id = max(max_id, P[i].back().id);
}

double dist(Point a, Point b)
{
	return sqrt( ( a.x - b.x )*( a.x - b.x ) + ( a.y - b.y )*( a.y - b.y ) );
}

bool predicateSortByX(struct Point a, struct Point b)
{
	return a.x < b.x;
}

bool predicateSortByY(struct Point a, struct Point b)
{
	return a.y < b.y;
}

//O(n^2)
double closestPointsSimple(const vector<Point> &P)
{
	double d = numeric_limits<double>::max();
	for(unsigned i = 0; i < P.size(); ++i)
		for(unsigned j = 0; j < P.size(); ++j)
			if( j != i )
        d = min(dist(P[i], P[j]), d);
	return d;
}

void partitionX(const vector<Point> &X, vector<Point> &XL, vector<Point> &XR, bool XL_ids[])
{
  unsigned i;
	for(i = 0; i < X.size()/2; ++i) {
    XL.push_back(X[i]);
    XL_ids[X[i].id] = true;
	}
  for (i = X.size()/2; i < X.size(); ++i)
    XR.push_back(X[i]);
}

void partitionY(const vector<Point> &Y, vector<Point> &YL, vector<Point> &YR, bool XL_ids[])
{
	for(unsigned i = 0; i < Y.size(); ++i)
	  if (XL_ids[Y[i].id])
      YL.push_back(Y[i]);
    else
      YR.push_back(Y[i]);
}

//O(nlogn)
double ClosestPoints(const vector<Point> &X, const vector<Point> &Y)
{
  double d = numeric_limits<double>::max();
  if(X.size() <= 3)
    return closestPointsSimple(X);
  else
  {
    int l = X[X.size()/2].x;
    bool XL_ids[max_id+1];
    memset(XL_ids, 0, max_id+1);
    vector<Point> XL, XR, YL, YR, Y1;
    XL.reserve(X.size()/2); XR.reserve(X.size()-X.size()/2);
    partitionX(X, XL, XR, XL_ids);
    YL.reserve(X.size()/2); YR.reserve(X.size()-X.size()/2);
    partitionY(Y, YL, YR, XL_ids);
    d = min(d, ClosestPoints(XL, YL));
    d = min(d, ClosestPoints(XR, YR));
    for(unsigned i = 0; i < Y.size(); ++i)
      if(Y[i].x >= l-d && Y[i].x <= l+d)
        Y1.push_back(Y[i]);
    for(unsigned i = 0; i < Y1.size(); ++i)
      for(unsigned j = i+1; j < i+8 && j < Y1.size(); ++j)
        d = min(d, dist(Y1[i], Y1[j]));
  }
  return d;
}

//O(m^2)
int LongestIncreasingSubsequenceSimple(const vector<double> &arr)
{
	int n = arr.size();
  int i, j, max = 0;
  int *lis = new int[n];

  for ( i = 0; i < n; i++ )
    lis[i] = 1;

  for ( i = 1; i < n; i++ )
    for ( j = 0; j < i; j++ )
      if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
        lis[i] = lis[j] + 1;

  for ( i = 0; i < n; i++ )
    if ( max < lis[i] )
      max = lis[i];

  delete[] lis;

  return max;
}

//O(mlogm)
int ceilIndex(double A[], int l, int r, double key);
int LongestIncreasingSubsequence(const vector<double> &A) {

  int size = A.size();
  double *tailTable = new double[size];
  memset(tailTable, 0, size*sizeof(double));
  int len;

  tailTable[0] = A[0];
  len = 1;
  for( int i = 1; i < size; i++ ) {
    if( A[i] < tailTable[0] )
      tailTable[0] = A[i];
    else if( A[i] > tailTable[len-1] )
      tailTable[len++] = A[i];
    else
      tailTable[ceilIndex(tailTable, -1, len-1, A[i])] = A[i];
  }

  delete[] tailTable;

  return len;
}

int ceilIndex(double A[], int l, int r, double key) {
  int m;
  while( r - l > 1 ) {
    m = l + (r - l)/2;
    (A[m] >= key ? r : l) = m;
  }
  return r;
}

int Povezi()
{
	vector<double> arr;
	for (int i=0;i<N;++i)
	{
	  vector<Point> X(P[i]), Y(P[i]);
	  sort( X.begin(), X.end(), predicateSortByX );
    sort( Y.begin(), Y.end(), predicateSortByY );
		arr.push_back(ClosestPoints(X, Y));
		//arr.push_back(closestPointsSimple(P[i]));
	}
	delete[] P;
	return LongestIncreasingSubsequence(arr);
	//return LongestIncreasingSubsequenceSimple(arr);
}
