#include "grader.h"
#include <bits/stdc++.h>

using namespace std;

void solve(int n)
{
    for (int u = 0; u < n; ++u)
    {
        for (int v = u + 1; v < n; ++v)
        {
            bool edge = true;

            for (int w = 0; w < n; ++w)
            {
                if (w == u || w == v)
                    continue;

                int x = meetingPlace(u, v, w);
                if (x != u && x != v)
                {
                    edge = false;
                    break;
                }
            }

            if (edge)
                mapPath(u, v);
        }
    }
}
