#include "grader.h"
#include <bits/stdc++.h>

using namespace std;

namespace {

int expectedMedian[8][8][8];

void reportEdge(int u, int v)
{
    if (u > v)
        swap(u, v);
    mapPath(u, v);
}

vector<pair<int, int>> treeFromPrufer(const vector<int>& prufer, int n)
{
    vector<int> degree(n, 1);
    for (int x : prufer)
        ++degree[x];

    set<int> leaves;
    for (int i = 0; i < n; ++i)
        if (degree[i] == 1)
            leaves.insert(i);

    vector<pair<int, int>> edges;
    for (int x : prufer)
    {
        int leaf = *leaves.begin();
        leaves.erase(leaves.begin());

        edges.push_back({leaf, x});
        --degree[leaf];
        if (--degree[x] == 1)
            leaves.insert(x);
    }

    int a = *leaves.begin();
    int b = *next(leaves.begin());
    edges.push_back({a, b});
    return edges;
}

vector<int> findPath(int src, int dst, const vector<vector<int>>& graph)
{
    int n = graph.size();
    vector<int> parent(n, -1);
    queue<int> q;

    parent[src] = src;
    q.push(src);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (u == dst)
            break;

        for (int v : graph[u])
        {
            if (parent[v] == -1)
            {
                parent[v] = u;
                q.push(v);
            }
        }
    }

    vector<int> path;
    for (int u = dst; u != src; u = parent[u])
        path.push_back(u);
    path.push_back(src);
    return path;
}

int candidateMedian(int a, int b, int c, const vector<vector<int>>& graph)
{
    vector<int> ab = findPath(a, b, graph);
    vector<int> ac = findPath(a, c, graph);
    vector<int> bc = findPath(b, c, graph);

    int n = graph.size();
    vector<int> cnt(n, 0);
    for (int x : ab)
        ++cnt[x];
    for (int x : ac)
        ++cnt[x];
    for (int x : bc)
        ++cnt[x];

    for (int i = 0; i < n; ++i)
        if (cnt[i] == 3)
            return i;

    return -1;
}

bool matchesOracle(const vector<pair<int, int>>& edges, int n)
{
    vector<vector<int>> graph(n);
    for (auto [u, v] : edges)
    {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int a = 0; a < n; ++a)
        for (int b = a + 1; b < n; ++b)
            for (int c = b + 1; c < n; ++c)
                if (candidateMedian(a, b, c, graph) != expectedMedian[a][b][c])
                    return false;

    return true;
}

bool searchPrufer(int pos, vector<int>& prufer, int n)
{
    if (pos == n - 2)
    {
        vector<pair<int, int>> edges = treeFromPrufer(prufer, n);
        if (!matchesOracle(edges, n))
            return false;

        for (auto [u, v] : edges)
            reportEdge(u, v);
        return true;
    }

    for (int x = 0; x < n; ++x)
    {
        prufer[pos] = x;
        if (searchPrufer(pos + 1, prufer, n))
            return true;
    }

    return false;
}

} // namespace

void solve(int n)
{
    for (int a = 0; a < n; ++a)
        for (int b = a + 1; b < n; ++b)
            for (int c = b + 1; c < n; ++c)
                expectedMedian[a][b][c] = meetingPlace(a, b, c);

    vector<int> prufer(max(0, n - 2));
    searchPrufer(0, prufer, n);
}
