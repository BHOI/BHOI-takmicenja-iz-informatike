#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    unordered_set <long long> st;
    for(long long x=0;3*x<=n;x++) {
        for(long long sum = n-x; sum >= 2*x; sum -= 2) {
            // y + z = sum
            // x <= y <= z
            // y <= sum/2
            for(long long y=x;2*y<=sum;y++) {
                st.insert(x*x + y*y + (sum-y)*(sum-y));
            }
        }
    }
    cout << st.size() << "\n";
    return 0;
}