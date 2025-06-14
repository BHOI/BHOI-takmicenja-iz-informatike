#include <iostream>
#include <deque>
#include <utility>

using namespace std;

int main(){
    long long n, a, b, c;
    cin >> n;
    deque<long long> dq;
    for (long long i = 0; i < n; i++){
        long long x;
        cin >> x;
        if(x == 0) {
            long long sum = 0;
            for(auto it : dq) {
                sum += it;
            }
            cout << sum << endl;
        }
        if(x == 1) {
            cin >> a >> b;
            for(long long i=0;i<a;i++) {
                dq.push_back(b);
            }
        }
        if(x == 2) {
            cin >> c;
            while(c--) {
                dq.pop_front();
            }
        }
    }

    return 0;
}