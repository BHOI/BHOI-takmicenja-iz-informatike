#include <cstdio>
#include <algorithm>
#include <cmath>
#include <climits>
#define maxn INT_MAX
#define right 1
#define left -1
#define colinear 0
using namespace std;
struct point{
	long x;
	long y;
	point() {}
	point(long ptx, long pty)
	{
		x=ptx;
		y=pty;
	}
	bool operator < (point pt2)
	{
		if (y<pt2.y) return true;
		else if (y==pt2.y && x<pt2.x) return true;
		else return false;
	}
	point operator = (point pt2) { x=pt2.x; y=pt2.y; }
};
point P;
long turn (point pt1, point pt2, point pt3)
{
	long long det;
	det=(long long)(pt2.x-pt1.x)*(pt3.y-pt1.y) - (long long)(pt2.y-pt1.y)*(pt3.x-pt1.x);
	if (det>0) return left;
	else if (det == 0) return colinear;
	else return right;
}
void swap_points(point& pt1, point& pt2)
{
	long tmp;
	tmp=pt1.x;
	pt1.x=pt2.x;
	pt2.x=tmp;
	tmp=pt1.y;
	pt1.y=pt2.y;
	pt2.y=tmp;
}
float dist(point p) { return (sqrt((long long)(p.x-P.x)*(p.x-P.x) + (long long)(p.y-P.y)*(p.y-P.y))); }
bool compare (point pt1, point pt2)
{
	if ((long long)(pt1.x-P.x)*(pt2.y-P.y) > (long long)(pt2.x - P.x)*(pt1.y - P.y)) return true;
	else if (((long long)(pt1.x-P.x)*(pt2.y-P.y) == (long long)(pt2.x - P.x)*(pt1.y - P.y)) && (dist(pt1)<dist(pt2))) return true;
	else return false;
}
int main()
{
	point pt[100005];
	point start;
	long i,j,tmp1,tmp2,n,index,m;

	start=point(maxn,maxn); index=0;

	freopen("omotac.in","r",stdin);
	freopen("omotac.out","w",stdout);

	scanf("%ld",&n);
	for (i=1; i<=n; i++)
	{
		scanf("%ld%ld",&tmp1,&tmp2);
		pt[i]=point(tmp1,tmp2);
		if (pt[i] < start){ start=pt[i]; index=i; }
	}

	swap_points(pt[index],pt[1]);
	P=pt[1];
	sort(pt+2,pt+n+1,compare);
	pt[0]=pt[n];

	m=2;
	for (i=3; i<=n; i++)
	{
		while (turn(pt[m-1],pt[m],pt[i])!=left)
		{
			if (m==2) { swap_points(pt[m],pt[i]); i++; }
			else m--;
		}
		m++;
		swap_points(pt[m],pt[i]);
	}

	printf("%ld\n",m);
	for (i=1; i<=m; i++) printf("%ld %ld\n",pt[i].x,pt[i].y);

	return 0;
}
