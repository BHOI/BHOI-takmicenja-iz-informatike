#include <iostream>
#include <vector>

int Min(int a, int b) {
    if(a == -1) return b;
    if(b == -1) return a;
    return std::min(a, b);
}

int main() {
    int n;
    std::cin >> n;
    std::vector <std::vector <int> > dp(n, std::vector <int>(n+1, -1));
    std::vector <int> cost(n+1);
    for(int i = 1; i <= n; ++i) std::cin >> cost[i];

    int mini = -1;
    dp[0][1] = 0; //nepotrebno
    dp[1][2] = cost[2];
    dp[1][1] = cost[1] + cost[2];

    for(int i = 2; i < n; ++i) {
        for(int j = n; j >= 1; --j) {
            if(j + i <= n && dp[i][j+i] != -1) dp[i][j] = Min(dp[i][j], dp[i][j+i] + cost[j]);
            if(j - i > 0 && dp[i-1][j-i] != -1) dp[i][j] = Min(dp[i][j], dp[i-1][j-i] + cost[j]);
        }
    }

    for(int i = 0; i < n; ++i) mini = Min(mini, dp[i][n]);
    std::cout << mini << std::endl;
    return 0;
}
