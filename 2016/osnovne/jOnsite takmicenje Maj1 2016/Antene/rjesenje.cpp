#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <cmath>
#include <array>

typedef std::array<int, 3> Antena;

bool file_input;
std::ifstream fin;

int read_next()
{
    int val;
    if (file_input)
    {
        fin >> val;
        return val;
    }
    else
    {
        std::cin >> val;
        return val;
    }
}

bool collision(const Antena &first, const Antena &second)
{
    return (std::abs(second[0] - first[0]) + std::abs(second[1] - first[1])) <= (first[2] + second[2]);
}

void test(const std::vector<Antena> &locs)
{
    for (int i = 1; i < locs.size(); i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (locs[j][0] < locs[i - 1][0] - 4)
                break;

            if (collision(locs[i], locs[j]))
            {
                std::cout << "DA\n";
                return;
            }
        }
    }

    std::cout << "NE\n";
}

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        file_input = true;
        fin.open(argv[1]);
    }
    else
    {
        file_input = false;
    }

    int t = read_next();

    while (t--)
    {
        int cnt = read_next();
        std::vector<Antena> locs(cnt);

        for (int i = 0; i < cnt; i++)
        {
            locs[i][0] = read_next();
            locs[i][1] = read_next();
            locs[i][2] = read_next();
        }

        test(locs);
    }
}
