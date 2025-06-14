#include <iostream>
#include <vector>

using namespace std;

int cx, cy;
bool zauzeto[8][8];
bool kr[8];

int dfs(int x, int y, int poteza) {
    if(poteza == 0) {
        if(x == cx && y == cy) {
            return 1;
        }
        return 0;
    }

    if(x < 0 || x > 7 || y < 0 || y > 7) {
        return 0;
    }

    if(zauzeto[x][y]) {
        return 0;
    }

    int br = 0;
    if(x == cx && y == cy) {
        br++;
    }


    if(kr[0]) br += dfs(x-1, y-1, poteza-1);
    if(kr[1]) br += dfs(x-1, y, poteza-1);
    if(kr[2]) br += dfs(x-1, y+1, poteza-1);
    if(kr[3]) br += dfs(x, y-1, poteza-1);
    if(kr[4]) br += dfs(x, y+1, poteza-1);
    if(kr[5]) br += dfs(x+1, y-1, poteza-1);
    if(kr[6]) br += dfs(x+1, y, poteza-1);
    if(kr[7]) br += dfs(x+1, y+1, poteza-1);
    return br;
}

int main(){
    int r, k, n;
    char c;

    cin >> r >> k >> n;

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    kr[0] = (s1[0] == '*');
    kr[1] = (s1[1] == '*');
    kr[2] = (s1[2] == '*');
    kr[3] = (s2[0] == '*');
    kr[4] = (s2[2] == '*');
    kr[5] = (s3[0] == '*');
    kr[6] = (s3[1] == '*');
    kr[7] = (s3[2] == '*');

    string s;

    for(int i=0;i<8;i++) {
        cin >> s;
        for(int j=0;j<8;j++) {
            if(s[j] == '#') {
                zauzeto[i][j] = true;
            }
            if(s[j] == 'C') {
                cx = i;
                cy = j;
            }
        }
    }

    int mx, my, br = 0, tr;
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            tr = dfs(i, j, n);
            if(tr > br) {
                mx = i;
                my = j;
                br = tr;
            }
        }
    }

    cout << mx+1 << ' ' << my+1 << endl;
    cout << br << endl;

    return 0;
}