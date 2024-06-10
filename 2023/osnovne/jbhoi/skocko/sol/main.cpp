#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
    // ifstream cin("tests/21.in");
    // ifstream cin1("tests/21");
    int n;
    cin >> n;
    int a[n], sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n);
    vector <int> dp(sum + 1);
    dp[0] = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = sum; j >= 0; j--)
        {
            if(dp[j]) dp[j + a[i]] = 1;
        }
    }
    long long ans = 0;
    int cnt = 0;
    for(int i = sum; i >= 0; i--)
    {
        if(dp[i])
        {
            cnt++;
            ans += sum + 1 - i;
        }
        else ans += cnt;
    }
    /*
    long long ans2;
    cin1 >> ans2;
    cout << ans2 << endl;
    */
    cout << ans << endl;
    return 0;
}
