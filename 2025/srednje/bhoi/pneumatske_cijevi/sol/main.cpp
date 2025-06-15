#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> P[2001];  //edges
int D[2001][2001];    //distances
int M[2001][2001];    //distances from a to b when there is an additional line at the depth of a
int L[2001];          //smallest index of vertex at each depth

vector<int> A[2001];  //ancestors of each vertex
int LCA[2001][2001];  //lowest common ancestor of a, b
int LmD[2001][2001];  //leftmost descendant of a at depth d

void dfs(int a, int b, int n, int (&T)[2001][2001], vector<int> (&Q)[2001])       //dfs to find all distances from a
{
    if (n >= T[a][b]) return;
    
    T[a][b] = n;
    for (int c:Q[b]) dfs(a, c, n+1, T, Q);
}

void bfs(int start, int (&T)[2001][2001], vector<int> (&Q)[2001]) {
    queue<int> q;
    q.push(start);
    T[start][start] = 0;
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        for(int neighbor : Q[node]) {
            if(T[start][neighbor] > T[start][node] + 1) {
                T[start][neighbor] = T[start][node] + 1;
                q.push(neighbor);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        P[a].push_back(b);          //get edges
        P[b].push_back(a);
        if (a < b)
            A[b].push_back(a);     //get parents
        else A[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)    //calculate LCA for all i,j
    {
        LCA[i][i] = i;
        for (int j = 1; j < i; j++)
        {
            LCA[i][j] = LCA[A[i][0]][j];
            LCA[j][i] = LCA[i][j];
        }
    }
    for (int i = 2; i <= n; i++)    //get all ancestors of i
        for (int j:A[A[i][0]])
            A[i].push_back(j);
    
    vector<int> Q[2001];
    for (int i = 1; i <= n; i++)    //initialize some values
    {
        Q[i] = P[i];
        for (int j = 1; j <= n; j++)
        {   
            D[i][j] = 5000;
            M[i][j] = 5000;
            LmD[i][j] = 5000;
        }
    }
    for (int i = 1; i <= n; i++)    //get all distances in the tree (we could have also used lca and depth for this)
        dfs(i, i, 0, D, P);
        
    L[0] = 1;
    for (int i = 2; i <= n; i++)    //separate vertices by depth
        if (D[1][i] > D[1][i-1])
            L[D[1][i]] = i;
    L[D[1][n]+1] = n+1;

    
    for (int d = 1; d <= D[1][n]; d++)
    {
        for (int i = L[d]; i < L[d+1]-1; i++)    //for each depth d, create a graph with additional line at d
        {
            Q[i].push_back(i+1);
            Q[i+1].push_back(i);
        }
        
        int num_edges = 0;
        for(int i=0;i<2001; i++) {
            num_edges += Q[i].size();
        }
        
        
        int cnt = 0;
        for (int i = L[d]; i < L[d+1]; i++) {   //get distances in the modified graph starting from all vertices at depth d in the original tree
            cnt++;
            bfs(i, M, Q);
        }
        
        for (int i = L[d]; i < L[d+1]; i++)    //reset Q
            Q[i] = P[i];
            
        for (int i = L[d]; i < L[d+1]; i++)    //get the leftmost descendant of each vertex x at depth d (if it doesn't exist, then LmD[x][d] remains 5000)
        {
            LmD[i][d] = i;
            for (int k = 0; k < d; k++)
                if (LmD[A[i][k]][d] == 5000)
                    LmD[A[i][k]][d] = i;
        }
    }
    
    for (int z = 0; z < q; z++)     //answer queries
    {
        int a, b, d;
        cin >> a >> b >> d;
        int r = D[a][b];            //distance in original tree
        
        if (a != LCA[a][b] && d <= D[1][n] &&
            b != LCA[a][b] && D[1][LCA[a][b]] < d)
        {
            int x, y;               //get the root of the unique subtree rooted at a child of LCA[a][b] and containing a, resp. b
            if (LCA[a][b] == A[a][0]) x = a;
            else x = A[a][D[1][a]-D[1][LCA[a][b]]-2];
            if (LCA[a][b] == A[b][0]) y = b;
            else y = A[b][D[1][b]-D[1][LCA[a][b]]-2];
            
            //if the new distance is shorter than the original one, then it is guaranteed to be the length of a path passing either through LmD[x][d] or LmD[y][d]
            
            if (LmD[x][d] != 5000 &&
                r > M[LmD[x][d]][a]+M[LmD[x][d]][b])
                r = M[LmD[x][d]][a]+M[LmD[x][d]][b];
            if (LmD[y][d] != 5000 &&
                r > M[LmD[y][d]][a]+M[LmD[y][d]][b])
                r = M[LmD[y][d]][a]+M[LmD[y][d]][b];
        }
                    
        cout << r << '\n';
    }
    
    return 0;
}