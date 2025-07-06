#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    set <long long> st;

    for(int x=-n;x<=n;x++) {
        for(int y=-n;y<=n;y++) {
            for(int z=-n;z<=n;z++) {
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