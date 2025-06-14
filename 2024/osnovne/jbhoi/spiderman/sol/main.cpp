#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i=0; i<n; i++) {
        cin >> h[i];
    }
    stack<int> s;
    for(int i=0; i<n; i++){
        while(!s.empty() && s.top() < h[i]) {
            s.pop();
        }
        s.push(h[i]);
    }
    cout << s.size() << endl;

}