#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define int long long
#define pii pair<int,int>
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
using namespace std;

signed main() {
    int n;
    cin >> n;
    queue<pii> q;
    int sum = 0, temp, x, y;
    while(n--) {
        cin >> temp;
        if(!temp) cout << sum << "\n";
        else if(temp == 1) {
            cin >> x >> y;
            sum += x * y;
            q.push({x, y});
        } else {
            cin >> x;
            while(x) {
                if(q.front().ff > x) {
                    q.front().ff -= x;
                    sum -= x * q.front().ss;
                    x = 0;
                } else {
                    sum -= q.front().ff * q.front().ss;
                    x -= q.front().ff;
                    q.pop();
                }
            }
        }
    }
}