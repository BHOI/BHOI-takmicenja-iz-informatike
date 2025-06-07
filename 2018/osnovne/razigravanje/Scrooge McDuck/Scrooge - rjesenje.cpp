#include <iostream>
#include <utility>
#include <stack>
#include <stdio.h>

using namespace std;

long long mat[1010][1010], ks[1010][1010], pc[1010][1010], dp[1010][1010];

int main()
{

//    freopen ("myfile.txt","w",stdout);

    int n, m, k;

    cin >> n >> m >> k;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> mat[i][j];
            ks[i][j]=mat[i][j];
        }
    }


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i>1 && j>1)
            {
                ks[i][j]+=ks[i-1][j]+ks[i][j-1]-ks[i-1][j-1];
            }
            else if(i>1)
            {
                ks[i][j]+=ks[i-1][j];
            }
            else if(j>1)
            {
                ks[i][j]+=ks[i][j-1];
            }
        }
    }

//    for(int i=1;i<=n;i++)
//    {
//        ks[i][m+1]=ks[i][m];
//    }
//    for(int i=1;i<=m;i++)
//    {
//        ks[n+1][i]=ks[n][i];
//    }
//    ks[n+1][m+1]=ks[n][m];

    int u, d, l, r;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            u=max(0, i-k-1);
            l=max(0, j-k-1);

            d=min(n, i+k);
            r=min(m, j+k);

            pc[i][j]=ks[d][r]+ks[u][l]-ks[u][r]-ks[d][l];
        }
    }

    if(k==0)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                pc[i][j]=mat[i][j];
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            dp[i][j]=pc[i][j];
            if(i>1 && j>1)
            {
                dp[i][j]+=min(dp[i-1][j], dp[i][j-1]);
            }
            else if(i>1)
            {
                dp[i][j]+=dp[i-1][j];
            }
            else if(j>1)
            {
                dp[i][j]+=dp[i][j-1];
            }
        }
    }

    int x, y;
    x=1;
    y=m;
    stack<pair<int, int> > stk;

    //trazi min

    for(int i=1;i<=n;i++)
    {
        if(dp[i][m]<dp[x][y])
        {
            x=i;
            y=m;
        }
    }

    for(int i=1;i<=m;i++)
    {
        if(dp[n][i]<dp[x][y])
        {
            x=n;
            y=i;
        }
    }
    /// VAZNO IZBRISATI AKO HOCES PRAVO RJESENJE
//    cout << dp[x][y] << '\n';

//    stk.push(make_pair(x, y));

    while(1)
    {
        stk.push(make_pair(x, y));

        if(x==1 && y==1)
        {
            break;
        }
        else if(x==1)
        {
            y--;
        }
        else if(y==1)
        {
            x--;
        }
        else
        {
            if(dp[x-1][y]<dp[x][y-1])
            {
                x--;
            }
            else
            {
                y--;
            }
        }
    }

    cout << stk.size() << '\n';

    while(stk.size())
    {
        cout << stk.top().first << ' ' << stk.top().second << ' ' << '\n';
        stk.pop();
    }


    /*
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout << mat[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout << ks[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    */

/*
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout << pc[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    */
    /*
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    */

    /*
    5 5 1
    1 1 1 1 99
    1 1 1 1 1
    1 1 1 1 1
    1 1 1 1 1
    99 1 1 1 1
    */

    return 0;
}
