#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct point {
	int x;
	int y;
};

struct prava{
	double k;
	double n;
};

bool compare(prava a, prava b)
{
	if (a.k<b.k) return 1;
	else if (fabs(a.k-b.k)<1e-8){
		if (a.n<b.n) return 1;
		else return 0;
	}
	else return 0;
}

int main()
{
	freopen("prava.in", "r", stdin);
	freopen("prava.out", "w", stdout);
	point points[1000];
	prava prave[1000], result;
	int size=0;
	int n,count,maxnum=0;
	int i,j;
	cin>>n;
	for (i=0;i<n;i++)
		cin>>points[i].x>>points[i].y;
	for (i=0;i<n-1;i++){
		size=0;
		for (j=i+1;j<n;j++){
			if (points[j].x-points[i].x!=0 && double(points[j].y-points[i].y)/(points[j].x-points[i].x)!=0){
				prave[size].k=double(points[j].y-points[i].y)/(points[j].x-points[i].x);
				prave[size++].n=points[i].y-(double(points[j].y-points[i].y)/(points[j].x-points[i].x))*points[i].x;
			}
		}
		sort(prave, prave+size, compare);
		for (j=0;j<size;j++){
			count=2;
			while (fabs(prave[j].k-prave[j+1].k)<1e-8 && fabs(prave[j].n-prave[j+1].n)<1e-8 && j+1<size) count++, j++;
			if (count>maxnum){
				maxnum=count;
				result.k=prave[j].k;
				result.n=prave[j].n;
			}
			else if (count==maxnum){
				if (fabs(prave[j].k)<fabs(result.k)){
					result.k=prave[j].k;
					result.n=prave[j].n;
				}
				else if (fabs(fabs(prave[j].k)-fabs(result.k))<1e-8 && fabs(prave[j].n)<fabs(result.n)){
					result.k=prave[j].k;
					result.n=prave[j].n;
				}
			}
		}
	}
	printf("%.3f %.3f\n", result.k, result.n);
	return 0;
}
