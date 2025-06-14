#include <iostream>

using namespace std;

bool mat[102][102];

int main() {
    int h, w, n;
    cin >> h >> w >> n;

    int berina_i, berina_j;
    char c;
    for (int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> c;
            if(c == '*') {
                mat[i+1][j+1] = true;
            }
            if(c == 'B') {
                berina_i = i+1;
                berina_j = j+1;
            }
        }
    }

    int br = 0;
    br += mat[berina_i-1][berina_j-1];
    br += mat[berina_i-1][berina_j];
    br += mat[berina_i-1][berina_j+1];
    br += mat[berina_i][berina_j-1];
    br += mat[berina_i][berina_j+1];
    br += mat[berina_i+1][berina_j-1];
    br += mat[berina_i+1][berina_j];
    br += mat[berina_i+1][berina_j+1];

    cout << br << endl;

    return 0;
}