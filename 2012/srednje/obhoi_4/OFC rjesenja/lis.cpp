#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

inline int find_pos(int A[], int right, int val)
{
	int left=0,mid;
	while (left<=right){
		mid=(left+right)/2;
		if (A[mid]<val) left=mid+1;
		else right=mid-1;
	}
	return left;
}

int main()
{
	freopen("lis.in", "r", stdin);
	freopen("lis.out", "w", stdout);
	int n, A[200000], lis[200000], count=0, i, p;
	scanf("%d", &n);
	for (i=0;i<n;i++)
		scanf("%d", &A[i]);
	for (i=0;i<n;i++){
		p=find_pos(lis, count-1, A[i]);
		if (p==count) count++;
		lis[p]=A[i];
	}
	for (i=0;i<count;i++)
		printf("%d\n", lis[i]);
	return 0;
}
