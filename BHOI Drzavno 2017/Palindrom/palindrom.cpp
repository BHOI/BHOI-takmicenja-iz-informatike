#include <random>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <utility>

#define MAX_N 200


int n, dp [MAX_N] [MAX_N];
char matrix[MAX_N][MAX_N];
std::string str [MAX_N] [MAX_N];

void reset()
{
    n = 0;
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < MAX_N; i++)
        for (int j = 0; j < MAX_N; j++)
            str[i][j] = "";
}

std::string palindrom(const std::vector<std::pair<std::pair<int, int>, char>> &g)
{
    reset();
    for (const auto &x : g)
    {
        matrix [x.first.first] [x.first.second] = x.second;
        dp [x.first.first] [x.first.second] = 1;
        str [x.first.first] [x.first.second] = "";
        str [x.first.first] [x.first.second] += x.second;
        n = std::max(n, x.first.first + 1);
        n = std::max(n, x.first.second + 1);
    }

    for (int k = 1; k < n; k++)
    {
        for (int i = 0; i < n && i + k < n; i++)
        {
            int j = i + k;
            for (int l = i + 1; l < j; l++)
            {
                for (int m = l; m < j; m++)
                {
                    if (matrix [i] [l] == matrix [m] [j])
                    {
                        std::string ret = matrix [i] [l] + str [l] [m] + matrix [m] [j];
                        if (ret.length() > str [i] [j].length() ||
                            ret.length() == str [i] [j].length() && ret < str [i] [j])
                                str [i] [j] = ret;
                    }
                }
            }
        }
    }

    return str [0] [n - 1];
}