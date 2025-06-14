#include <iostream>

using namespace std;

bool mat[101][101];

int main() {
    int h, w, n;
    cin >> h >> w >> n;

    char c;
    for (int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> c;
        }
    }
    
    cout << 0 << endl;

    return 0;
}