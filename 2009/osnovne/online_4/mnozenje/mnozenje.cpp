#include <iostream>
using namespace std;

int a[50][50], b[50][50];

int main (void)
{
	int m, n, p;
	cin >> m >> n >> p;
	
	for (int i = 0; i < m; i++) for (int j = 0; j < n; j++)
		cin >> a[i][j];
	for (int i = 0; i < n; i++) for (int j = 0; j < p; j++)
		cin >> b[i][j];
		
	printf ("%d %d\n", m, p);
	for (int i = 0; i < m; i++)  {
		for (int j = 0; j < p; j++)
		{
			int c = 0;
			for (int k = 0; k < n; k++)
				c += a[i][k] * b[k][j];
			printf ("%d ", c);
		}
		printf ("\n");
	}
	
	return 0;
}
