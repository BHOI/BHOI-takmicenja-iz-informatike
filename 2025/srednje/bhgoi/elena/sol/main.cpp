#include <iostream>
#include <vector>

using namespace std;

long long mod = 1000000007;

int main(){
    int r, k, n;
    cin >> r >> k >> n;

    vector<vector<bool>> moves(3, vector<bool> (3, false));
    char c;
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            
            cin >> c;
            if(c == '*'){
                moves[i][j] = true;
            }
        }
    }

    // Poteze invertujemo, idemo od cilja do svih ostalih

    swap(moves[0][0], moves[2][2]);
    swap(moves[0][1], moves[2][1]);
    swap(moves[0][2], moves[2][0]);
    swap(moves[1][0], moves[1][2]);


    int r_c, k_c;
    vector<vector<bool>> free(r, vector<bool> (k, true));

    for(int i=0; i<r; i++){
        for(int j=0; j<k; j++){
            cin >> c;
            if(c == '#') {
                free[i][j] = false;
            }
            else if(c == 'C') {
                r_c = i;
                k_c = j;
            }
        }
    }

    vector<vector<long long>> dp(r, vector<long long> (k, 0));
    vector<vector<long long>> dp_old(r, vector<long long> (k, 0));
    vector<vector<long long>> sum(r, vector<long long> (k, 0));
    
    dp_old[r_c][k_c] = 1;
    sum[r_c][k_c] = 1; // Sa 0 poteza ima 1 mogucnost - startanjem na C

    // Odredimo broj poteza od ciljnog polja do svih ostalih
    // Zato koristimo invertovane poteze

    while(n--) {
        for(int i=0; i<r; i++){
            for(int j=0; j<k; j++){
                if(!free[i][j]){
                    continue;
                }
                // Proci kroz moguce poteze
                for(int x=-1; x<=1; x++){
                    for(int y=-1; y<=1; y++){
                        // Da li je potez sa (i,j) na (i+x,j+y) moguc (nakon invertovanja)?
                        if(moves[x+1][y+1] && i+x >= 0 && i+x < r && j+y >= 0 && j+y < k && free[i+x][j+y]){
                            dp[i+x][j+y] += dp_old[i][j];
                            dp[i+x][j+y] %= mod;
                        }
                    }
                }
            }
        }

        dp_old = dp;

        // Dodati na sum matricu
        for(int i=0; i<r; i++){
            for(int j=0; j<k; j++){
                sum[i][j] += dp[i][j];
                sum[i][j] %= mod;

                dp[i][j] = 0; // Resetujemo dp
            }
        }
    }

    int r_opt = 0, k_opt = 0;

    for(int i=0; i<r; i++){
        for(int j=0; j<k; j++){
            if(sum[i][j] > sum[r_opt][k_opt]){
                r_opt = i;
                k_opt = j;
            }
        }
    }

    cout << r_opt+1 << ' ' << k_opt+1 << endl;
    cout << sum[r_opt][k_opt] << endl;

    return 0;
}