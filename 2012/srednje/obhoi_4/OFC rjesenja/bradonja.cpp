#include <cstdio>
#include <iostream>
using namespace std;

struct point{
	int x;
	int y;
	point(){}
	point(int dotx, int doty)
	{
		x=dotx;
		y=doty;
	}
};

point poly[500000];
int n;

inline bool LeftAngle(point p1, point p2, point q)
{
	return (((long long)(q.x-p1.x))*(p2.y-p1.y)<=((long long)(p2.x-p1.x))*(q.y-p1.y));
}

inline bool InPolygon(point q)
{
	int first=0, last=n-1;
	int p1, p3, p2;
	while ((first+1)%n!=last){
		p1=first;
		p2=(last+first)/2;
		p3=last;
		int num=0;
		if (!LeftAngle(poly[p1], poly[p2], q))
			num=1;
		if (!LeftAngle(poly[p2], poly[p3], q)){
			if (num>0) return 0;
			else num=2;
		}
		if (!LeftAngle(poly[p3], poly[p1], q)){
			if (num>0) return 0;
			else num=3;
		}
		if (num==0) return 1;
		else if (num==1) first=p1, last=p2;
		else if (num==2) first=p2, last=p3;
		else first=p3, last=p1;
	}
	return 0;
}

int main()
{
	freopen("bradonja.in", "r", stdin);
	freopen("bradonja.out", "w", stdout);
	int k,dotx,doty;
	scanf("%d %d", &n, &k);
	for (int i=0;i<n;i++)
		scanf("%d %d", &poly[i].x, &poly[i].y);
	while(k-->0){
		scanf("%d %d", &dotx, &doty);
		printf("%d\n", InPolygon(point(dotx, doty)));
	}
	return 0;
}

