#include <vector>

using namespace std;

int MaksimalnaVrijednost(int N, int M, int *T)
{
    int maxio = -1;
    vector<int> row, col;
    row.resize(N);
    col.resize(M);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
        {
            row[i] += T[M * i + j];
            col[j] += T[M * i + j];
        }
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            maxio = max(row[i] + col[j] - T[M * i + j], maxio);
    return maxio;
}
