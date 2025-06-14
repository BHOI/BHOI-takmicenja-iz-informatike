#include <iostream>
#include <stack>
#include <utility>

using namespace std;

int main(){
    long long n, a, b, c;
    cin >> n;
    stack<pair<long long, long long>> st;
    long long sum = 0;
    for (long long i = 0; i < n; i++){
        long long x;
        cin >> x;
        if(x == 0) {
            cout << sum << endl;
        }
        if(x == 1) {
            cin >> a >> b;
            st.push({a, b});
            sum += a * b;
        }
    }

    return 0;
}