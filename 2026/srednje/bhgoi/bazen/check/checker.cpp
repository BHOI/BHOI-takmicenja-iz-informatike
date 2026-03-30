#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define VERDICT(isCorrect, text) { cerr << text << "\n"; cout << ((isCorrect) ? "1.0\n" : "0.0\n"); return 0; }

int main(int argc, char **argv)
{
    ifstream input(argv[1]), correct_out(argv[2]), contestant_out(argv[3]);

    int n, m;
    input >> n >> m;

    vector<vector<int>> d(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            input >> d[i][j];

    long long official_sum;
    correct_out >> official_sum;

    long long claimed_sum;
    if (!(contestant_out >> claimed_sum))
        VERDICT(false, "Ne moze se procitati suma iz izlaza.");

    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        if (!(contestant_out >> grid[i]))
            VERDICT(false, "Nedostaje red " << i + 1 << " matrice.");

        if ((int)grid[i].size() != m)
            VERDICT(false, "Red " << i + 1 << " ima " << grid[i].size() << " znakova, a treba " << m << ".");

        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] != '*' && grid[i][j] != '.')
                VERDICT(false, "Nedozvoljen znak '" << grid[i][j] << "' na poziciji (" << i + 1 << "," << j + 1 << ").");
        }
    }

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    long long actual_sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '*')
            {
                actual_sum += d[i][j];

                for (int dir = 0; dir < 4; dir++)
                {
                    int ni = i + dx[dir], nj = j + dy[dir];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == '*')
                        VERDICT(false, "Susjedne plocice (" << i + 1 << "," << j + 1 << ") i (" << ni + 1 << "," << nj + 1 << ") su obje usisane.");
                }
            }
        }
    }

    if (claimed_sum != actual_sum)
        VERDICT(false, "Ispisana suma " << claimed_sum << " ne odgovara stvarnoj sumi odabranih plocica.");

    if (actual_sum < official_sum)
        VERDICT(false, "Suma " << actual_sum << " je manja od optimalne.");

    VERDICT(true, "Tacno!");
    return 0;
}
