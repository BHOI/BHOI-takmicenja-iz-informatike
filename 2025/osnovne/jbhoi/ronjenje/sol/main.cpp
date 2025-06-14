#include <iostream>

using namespace std;

bool mat[101][101];

int main() {
    int h, w, n;
    cin >> h >> w >> n;

    int berina_i, berina_j;
    char c;
    for (int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> c;
            if(c == '*') {
                mat[i][j] = true;
            }
            if(c == 'B') {
                berina_i = i;
                berina_j = j;
            }
        }
    }

    int r = (n-1)/2;
    int br = 0;

    for(int i=berina_i - r; i <= berina_i + r; i++) {
        for(int j = berina_j - r; j <= berina_j + r; j++) {
            if(i >= 0 && i < h && j >= 0 && j < w) {
                br += mat[i][j];
            }
        }
    }

    cout << br << endl;

    return 0;
}