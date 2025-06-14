#include <iostream>
#include <deque>
#include <utility>

using namespace std;

int main(){
    int n;
    cin >> n;
    cin >> n;
    if(n == 0) {
        cout << 0 << endl << 0 << endl;
        return 0;
    }
    int a, b;
    cin >> a >> b;
    cout << a * b << endl;

    return 0;
}