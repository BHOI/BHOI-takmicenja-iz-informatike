#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;

vector<int> V[100001];
int T[100001];
int D[100001];

int anc(int x, int d, int iter = 0)
{
    if (!d) return x;
    if (d%2)
        return anc(V[x][iter], d/2, iter+1);
    return anc(x, d/2, iter+1);
}

int lca(int x, int y)
{
    if (D[x] > D[y]) x = anc(x, D[x]-D[y]);
    if (D[y] > D[x]) y = anc(y, D[y]-D[x]);

    while (x != y)
    {
        int x0 = x, a = V[x][0]; x = a;
        int y0 = y, b = V[y][0]; y = b;
        int i = 1, d = 2;

        while (d <= D[x] && a != b)
        {
            x = a;
            y = b;
            a = V[x0][i];
            b = V[y0][i];

            i++;
            d *= 2;
        }
    }

    return x;
}

void mark(int t, vector<int> &K)
{
    int m = 0;
    for (int x : K)
        if (m < D[x])
            m = D[x];

    if (m-D[t] <= 1 || K.size() == 1)
    {
        T[t] -= K.size();
        for (int x : K) T[x]++;
        return;
    }

    map<int, vector<int> > M;
    int p = (m+D[t])/2;
    for (int x : K)
        if (D[x] > p)
            M[anc(x, D[x]-p)].push_back(x);
        else M[x].empty();

    K.clear();
    for (auto P : M)
    {
        K.push_back(P.first);
        if (!P.second.empty())
            mark(P.first, P.second);
    }
    mark(t, K);
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> N[n+1];
    map<pair<int, int>, int> M;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        N[a].push_back(b);
        N[b].push_back(a);
        M[make_pair(min(a, b), max(a, b))] = i;

        D[i] = -1; T[i] = 0;
    }   D[n] = -1; T[n] = 0;

    stack<int> S;
    queue<int> Q;
    Q.push(1);
    D[1] = 0;
    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();

        int d = 2;
        for (int i = 0; d <= D[x]; i++)
        {
            V[x].push_back(V[V[x][i]][i]);
            d *= 2;
        }

        for (int y : N[x])
        {
            if (D[y] != -1) continue;

            S.push(y);
            Q.push(y);
            D[y] = D[x]+1;
            V[y].push_back(x);
        }
    }

    for (int i = 0; i < m; i++)
    {
        int s, a;
        cin >> s >> a;

        vector<int> K;
        K.push_back(a);
        for (int j = 1; j < s; j++)
        {
            int b;
            cin >> b;
            a = lca(a, b);
            K.push_back(b);
        }

        mark(a, K);
    }

    vector<int> R;
    while (!S.empty())
    {
        int x = S.top();
        S.pop();

        if (T[x] >= k)
            R.push_back(M[make_pair(min(x, V[x][0]), max(x, V[x][0]))]);

        T[V[x][0]] += T[x];
    }
    sort(R.begin(), R.end());
    cout << R.size() << endl;
    for (int r : R) cout << r << " ";

    return 0;
}
