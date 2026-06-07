#include <iostream>

using namespace std;

int main() {
    int a, b;
    int boris = 0, cnt = 0;
    cin >> a >> b;
    
    while(a >= boris) {
        boris += b;
        cnt++;
    }

    cout << cnt << endl;

    return 0;
}
