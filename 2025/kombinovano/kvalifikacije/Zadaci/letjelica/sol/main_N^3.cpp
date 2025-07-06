#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    set <long long> st;

    for(int x=0;x<=n;x++) {
        for(int y=0;y<=n;y++) {
            for(int z=0;z<=n;z++) {
                long long d = x*x + y*y + z*z;
                if(abs(x) + abs(y) + abs(z) <= n && (n-x-y-z)%2 == 0) {
                    st.insert(d);
                }
            }
        }
    }

    cout << st.size() << endl;

    return 0;
}