#include <iostream>
#include <utility>
#include <vector>
#include <stack>

using namespace std;

char other(char c)
{
    if (c == '(') return ')';
    if (c == ')') return '(';
    if (c == '[') return ']';
    if (c == ']') return '[';
    if (c == '{') return '}';
    if (c == '}') return '{';
}

int main()
{
    int n, k;
    string s;
    cin >> n >> k >> s;

    stack<int> S;
    vector<pair<int, int> > P, U;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') S.push(i);
        else
        {
            if (S.empty())
            {
                cout << "nemoguce";
                return 0;
            }
            pair<int, int> M = make_pair(S.top(),i);
            S.pop();

            int d = s[i] - s[M.first];
            if (d == 1 || d == 2)
                P.push_back(M);
            else U.push_back(M);
        }
    }
    if (!S.empty())
    {
        cout << "nemoguce";
        return 0;
    }

    int u = U.size();
    int p = P.size();
    if (u)
    {
        if (k < u)
        {
            cout << "nemoguce";
            return 0;
        }
    }
    else
    {
        if (k % 2)
        {
            cout << "nemoguce";
            return 0;
        }
    }

    string r = s;
    int i, j = 0;
    for (i = 0; i < p && 2*i < k-u-1; i++)
    {
        if (r[P[i].first] == '(')
        {
            r[P[i].first] = '[';
            r[P[i].second] = ']';
        }
        else
        {
            r[P[i].first] = '(';
            r[P[i].second] = ')';
        }
    }
    int t = 2*i;
    for (i = t; i < k-u; i++)
    {
        r[U[j].first] = (char)(('('+'['+'{')-(s[U[j].first]+other(s[U[j].second])));
        r[U[j].second] = (char)((')'+']'+'}')-(other(s[U[j].first])+s[U[j].second]));
        j++;
        t += 2;
    }
    for (; t < k; t++)
    {
        r[U[j].first] = other(s[U[j].second]);
        j++;
    }

    cout << r;
}
