#include <iostream>
#include <vector>

using namespace std;

int mat[8][8], slj[8][8], br[8][8];
int MOD = 1000000007;

void simuliraj() {
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            slj[i][j] = 0;
        }
    }

    int dr[8] = {1, 1, 1, 0, -1, -1, -1, 0};
    int dc[8] = {0, 1, -1, 1, 0, 1, -1, -1};
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            for(int d=0;d<8;d++) {
                int ni = i + dr[d];
                int nj = j + dc[d];
                if(ni >= 0 && ni < 8 && nj >= 0 && nj < 8) {
                    slj[ni][nj] += mat[i][j];
                    slj[ni][nj] %= MOD;
                }
            }
        }
    }
    // for(int a=0;a<8;a++) {
    //     for(int b=0;b<8;b++) {
    //         cout << slj[a][b] << ' ';
    //     }
    //     cout << endl;
    // }

    // for(int a=0;a<8;a++) {
    //     for(int b=0;b<8;b++) {
    //         cout << mat[a][b] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
}

int main(){
    int r, k, n;

    cin >> r >> k >> n;

    string s;
    cin >> s >> s >> s;

    int rc, kc;
    for(int i=0;i<8;i++) {
        cin >> s;
        for(int j=0;j<8;j++) {
            if(s[j] == 'C') {
                rc = i;
                kc = j;
            }
        }
    }

    br[rc][kc] = 1;
    mat[rc][kc] = 1;

    for(int k=0;k<n;k++) {
        simuliraj();
        for(int i=0;i<8;i++) {
            for(int j=0;j<8;j++) {
                mat[i][j] = slj[i][j];
                br[i][j] += mat[i][j];
                br[i][j] %= MOD;
            }
        }
    }

    int naj_r=0, naj_k=0;

    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            if(br[i][j] > br[naj_r][naj_k]) {
                naj_r = i;
                naj_k = j;
            }
        }
    }

    cout << naj_r + 1 << ' ' << naj_k + 1 << endl;
    cout << br[naj_r][naj_k] << endl;

    return 0;
}