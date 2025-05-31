#include <iostream>
#include <vector>
#include <string>

int main()
{
    int h, w;
    std::cin >> h >> w;
    std::vector<std::string> mat;

    for (int i = 0; i < h; i++)
    {
        std::string s;
        std::cin >> s;
        mat.push_back(s);
    }

    int x1 = -1, y1, x2 = -1, y2;

    for (int i = 0; i < h && x2 == -1; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (mat[i][j] == '#' && (!i || mat[i - 1][j] == '.') && (!j || mat[i][j - 1] == '.'))
            {
                if (x1 == -1)
                {
                    x1 = j;
                    y1 = i;
                }
                else
                {
                    x2 = j;
                    y2 = i;
                    break;
                }
            }
        }
    }

    int w1, h1, w2, h2;
    w1 = h1 = w2 = h2 = 0;
    int i;

    //for (int i = x1; ; i++)
        i = x1;
        while (i < w && mat[y1][i] == '#')
            w1++, i++;


    //for (int i = y1; ; i++)
    {
        i = y1;
        while (i < h && mat[i][x1] == '#')
            h1++, i++;
    }

    //for (int i = x2; ; i++)
    {
        i = x2;
        while (i < w && mat[y2][i] == '#')
            w2++, i++;
    }

    //for (int i = y2; ; i++)
    {
        i = y2;
        while (i < h && mat[i][x2] == '#')
            h2++, i++;
    }

    std::cout << w1 * h1 + w2 * h2;
}
