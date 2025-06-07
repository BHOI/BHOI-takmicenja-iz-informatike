#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;

int M, N;
int niz[1000][1000];


bool checkB(int i, int j)
{
	if ( i + 4 >= M) return false;
	if ( j + 2 >= N) return false;

	if (niz[i][j] == 0) return false;
	if (niz[i][j+1] == 0) return false;
	if (niz[i][j+2] == 1) return false;

	if (niz[i+1][j] == 0) return false;
	if (niz[i+1][j+1] == 1) return false;
	if (niz[i+1][j+2] == 0) return false;


	if (niz[i+2][j] == 0) return false;
	if (niz[i+2][j+1] == 0) return false;
	if (niz[i+2][j+2] == 1) return false;

	if (niz[i+3][j] == 0) return false;
	if (niz[i+3][j+1] == 1) return false;
	if (niz[i+3][j+2] == 0) return false;

	if (niz[i+4][j] == 0) return false;
	if (niz[i+4][j+1] == 0) return false;
	if (niz[i+4][j+2] == 1) return false;

	return true;
}

bool checkH(int i, int j)
{
	if ( i + 4 >= M) return false;
	if ( j + 2 >= N) return false;

	if (niz[i][j] == 0) return false;
	if (niz[i][j+1] == 1) return false;
	if (niz[i][j+2] == 0) return false;

	if (niz[i+1][j] == 0) return false;
	if (niz[i+1][j+1] == 1) return false;
	if (niz[i+1][j+2] == 0) return false;


	if (niz[i+2][j] == 0) return false;
	if (niz[i+2][j+1] == 0) return false;
	if (niz[i+2][j+2] == 0) return false;

	if (niz[i+3][j] == 0) return false;
	if (niz[i+3][j+1] == 1) return false;
	if (niz[i+3][j+2] == 0) return false;

	if (niz[i+4][j] == 0) return false;
	if (niz[i+4][j+1] == 1) return false;
	if (niz[i+4][j+2] == 0) return false;

	return true;
}




int main() {
	freopen("bih.in","r",stdin);
	freopen("bih.out","w",stdout);
	cin>>M>>N;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin>>niz[i][j];
		}
	}

	int rez = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (checkB(i,j)) rez++;
			if (checkH(i,j)) rez++;
		}

	}

	cout << rez << endl;

	return 0;
}
