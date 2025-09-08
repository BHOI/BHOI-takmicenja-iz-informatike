#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
typedef pair<int, int> pii;
 
int n;
int fin, strt;
vector<int> pow3;
 
vector<pii> par;
vector<bool> vis;
vector<int> temp_arr(13);
 
vector<int> path;
void dfs(int me) {
    if (me == fin) {
        while (me != strt) {
            path.push_back(par[me].second);
            me = par[me].first;
        }
        return;
    }
 
    int k = me;
    for (int i = 0; i < n; i++)
        temp_arr[i] = k % 3, k /= 3;
    for (int i = 0; i < n; i++) {
        if (temp_arr[i] == 1) {
            int to_go = me;
            if (i != 0 and temp_arr[i - 1] == 0)
            {
                to_go -= pow3[i];
                to_go += pow3[i - 1];
 
                if (!vis[to_go]) {
                    par[to_go] = pii(me, i);
                    vis[to_go] = true;
                    dfs(to_go);
                    temp_arr[i - 1] = 0;
                    temp_arr[i] = 1;
                }
            } else if (i > 1 and temp_arr[i - 1] != 0 and temp_arr[i - 2] == 0) {
                to_go -= pow3[i];
                to_go += pow3[i - 2];
 
                if (!vis[to_go]) {
                    par[to_go] = pii(me, i);
                    vis[to_go] = true;
                    dfs(to_go);
                    temp_arr[i - 2] = 0;
                    temp_arr[i] = 1;
                }
            }
        } else if (temp_arr[i] == 2) {
            int to_go = me;
            if (i != n - 1 and temp_arr[i + 1] == 0) {
                to_go -= pow3[i] * 2;
                to_go += pow3[i + 1] * 2;
 
                if (!vis[to_go])
                {
                    par[to_go] = pii(me, i);
                    vis[to_go] = true;
                    dfs(to_go);
                    temp_arr[i + 1] = 0;
                    temp_arr[i] = 2;
                }
            } else if (i < n - 2 and temp_arr[i + 2] == 0) {
                to_go -= pow3[i] * 2;
                to_go += pow3[i + 2] * 2;
 
                if (!vis[to_go]) {
                    par[to_go] = pii(me, i);
                    vis[to_go] = true;
                    dfs(to_go);
                    temp_arr[i + 2] = 0;
                    temp_arr[i] = 2;
                }
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n;
    pow3.resize(n + 1, 1);
    for (int i = 1; i <= n; i++)   
        pow3[i] = pow3[i - 1] * 3;
 
    int num1 = 0, num2 = 0;
    for (int i = 0; i < n; i++) {
        int home;
        cin >> home;
        strt += home * pow3[i];
        if (home == 1)
            num1++;
        else if (home == 2)
            num2++;
    }
 
    par.resize(pow3[n], pii(-1, -1));
    vis.resize(pow3[n]);
 
    for (int i = 0; i < num1; i++)
        fin += pow3[i];
    for (int i = 0; i < num2; i++)
        fin += pow3[n - 1 - i] * 2;
 
    dfs(strt);
    reverse(path.begin(), path.end());
    cout << path.size() << "\n";
    for (int i = 0; i < path.size(); i++)
        cout << path[i] + 1 << " ";
    cout << "\n";
}