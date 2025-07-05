#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MID (left + right)/2

int A[1000005];
int temp[1000005], size;
unsigned long long cnt = 0;

void MergeSort(int left, int right)
{
	if (left < right){
		MergeSort(left, MID);
		MergeSort(MID + 1, right);
		int i = left;
		int j = MID + 1;
		size = 0;
		while (i <= MID && j <= right){
			if (A[i] <= A[j]) temp[size++] = A[i++];
			else {
				cnt += MID - i + 1;
				temp[size++] = A[j++];
			}
		}
		if (i > MID) memcpy(temp + size, A + j, sizeof(int)*(right - j + 1));
		if (j > right) memcpy(temp + size, A + i, sizeof(int)*(MID - i + 1));
		memcpy(A + left, temp, sizeof(int)*(right - left + 1));
	}
}

int main()
{
	freopen("rode.in", "r", stdin);
	freopen("rode.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", &A[i]);
	MergeSort(0, n-1);
	printf("%llu KM\n", cnt);
	return 0;
}
