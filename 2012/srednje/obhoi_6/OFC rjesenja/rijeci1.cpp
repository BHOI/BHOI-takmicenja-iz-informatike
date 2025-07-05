// delete->1   insert->2  change->3
#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#define MAXN 3001
using namespace std;

int dp[MAXN][MAXN];
int operation[MAXN][MAXN];

int levensthein (char* start, char* goal,int del_cost, int ins_cost, int change_cost )
{
    int i,j,insert,del,change,final_cost,operation_made;
    int startlen=strlen(start); int goallen=strlen(goal);
    bool identic=false;

    for (i=0; i<=startlen; i++) { dp[i][0]=i*del_cost; operation[i][0]=1; }
    for (i=0; i<=goallen; i++)  { dp[0][i]=i*ins_cost; operation[0][i]=2; }
    operation[0][0]=0;

    for (i=1; i<=startlen; i++)
    {
        for (j=1; j<=goallen; j++)
        {
            identic=false;
            change=dp[i-1][j-1]; if (start[i-1]!=goal[j-1]) change += change_cost; else identic=true;
            insert=dp[i][j-1] + ins_cost;
            del=dp[i-1][j] + del_cost;

            final_cost=change; if (!identic) operation_made=3; else operation_made=4;
            if (final_cost > insert) { final_cost=insert; operation_made=2; }
            if (final_cost > del)    { final_cost=del;    operation_made=1; }
            dp[i][j]=final_cost;
            operation[i][j]=operation_made;
        }
    }

    return dp[startlen][goallen];
}
/*void traceback(char* start, char* goal)
{
    int startlen=strlen(start);
    int goallen=strlen(goal);
    int x=startlen, y=goallen, tmp;
    stack<int> operations;

    operations.push(operation[x][y]);
    while (operation[x][y]!=0)
    {
        if       (operation[x][y]==1) x--;
        else if  (operation[x][y]==2) y--;
        else if ((operation[x][y]==3)||(operation[x][y]==4)) { x--; y--; }
        operations.push(operation[x][y]);
    }

    while (!operations.empty())
    {
        tmp=operations.top();
            operations.pop();
        // printf("%c",((char)('A' + tmp - 1)));
        if      (tmp==1) printf("A");
        else if (tmp==2) printf("B");
        else if (tmp==3) printf("C");
        else if (tmp==4) printf("D");
    }
}*/
int main()
{
    char x[MAXN],y[MAXN];
    int dl,in,ch,dist;

    freopen("rijeci.in","r",stdin);
    freopen("rijeci.out","w",stdout);

    scanf("%s%s%d%d%d",x,y,&dl,&in,&ch);

    dist=levensthein(x,y,dl,in,ch);
    printf("%d\n",dist);

    //traceback(x,y);
    return 0;
}
