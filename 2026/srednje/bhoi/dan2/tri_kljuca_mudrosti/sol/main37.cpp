#include "grader.h"
#include <bits/stdc++.h>

using namespace std;

void MakeBridge(int x, int y)
{
    if (x > y)
        swap(x, y);
    mapPath(x, y);
}

void solve(vector<int> v)
{
    if (v.size() < 2)
        return;
    
    random_shuffle(v.begin(), v.end());

    map<int, vector<int>> m;
    m[v[0]].push_back(v[0]);
    m[v[1]].push_back(v[1]);

    vector<int> path;
    for (int i = 2; i < v.size(); i++)
    {
        int x = meetingPlace(v[0], v[1], v[i]);

        if (!m.count(x))
            path.push_back(x);
        
        m[x].push_back(v[i]);
    }
    sort(
        path.begin(), 
        path.end(), 
        [&](int x, int y){ return meetingPlace(v[0], x, y) == x; }
    );

    int last = v[0];
    for (int x : path)
        MakeBridge(last, x), last = x;
    
    MakeBridge(last, v[1]);
    for (auto it : m)
    {
        solve(it.second);
    }
}

void solve(int n)
{
    if (n > 300) {
        for (int i = 0; i < 100000; i++)
            MakeBridge(0, 1);
        return;
    }
    srand(time(0));

    vector<int> all(n);
    for (int i = 0; i < n; i++)
        all[i] = i;

    solve(all);
}
