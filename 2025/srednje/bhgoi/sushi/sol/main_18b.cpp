#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main(){
    long long n, a, b, c;
    cin >> n;
    queue<pair<long long, long long>> q;
    long long sum = 0;
    for (long long i = 0; i < n; i++){
        long long x;
        cin >> x;
        if(x == 0) {
            cout << sum << endl;
        }
        if(x == 1) {
            cin >> a >> b;
            q.push({a, 1000000});
            sum += a * 1000000;
        }
        if(x == 2) {
            cin >> c;
            while(c > 0) {
                if(q.front().first <= c) {
                    c -= q.front().first;
                    sum -= q.front().first * q.front().second;
                    q.pop();
                } else {
                    sum -= q.front().second * c;
                    q.front().first -= c;
                    break;
                }
            }
        }
    }

    return 0;
}