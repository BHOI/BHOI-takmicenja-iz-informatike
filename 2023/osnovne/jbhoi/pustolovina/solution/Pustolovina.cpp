#include <iostream>
#include <queue>
#define INTEGER_M 1000000000000
using namespace std;

typedef pair<long long, long long> ii;
typedef pair<long long, ii> iii;

long long mat[1010][1010], bfs[1010][1010], n,m,k;
priority_queue<iii> pq;

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n*m; ++i) { // clear
        mat[i/m][i%m] = 0;
        bfs[i/m][i%m] = INTEGER_M;
    }

    for (int i = 0; i < k; ++i) {
        long long t1, t2, t3;
        cin >> t1 >> t2 >> t3; t1--; t2--;
        mat[t1][t2] = max(mat[t1][t2], t3);
        pq.push({t3,{t1,t2}});
    }
    // flood fill
    while (pq.size()) {
        long long visina = pq.top().first, x=pq.top().second.first, y=pq.top().second.second;
        pq.pop();
        if (visina < mat[x][y] || visina==1) continue;
        if (x > 0 && mat[x-1][y] < visina-1) {mat[x-1][y]=visina-1; pq.push({visina-1,{x-1,y}}); }
        if (y > 0 && mat[x][y-1] < visina-1) {mat[x][y-1]=visina-1; pq.push({visina-1,{x,y-1}}); }
        if (x < n-1 && mat[x+1][y] < visina-1) {mat[x+1][y]=visina-1; pq.push({visina-1,{x+1,y}}); }
        if (y < m-1 && mat[x][y+1] < visina-1) {mat[x][y+1]=visina-1; pq.push({visina-1,{x,y+1}}); }
    }
    pq.push({-mat[0][0],{0,0}}); // init pozicija
    while (pq.size()) {
        long long visina = -pq.top().first, x=pq.top().second.first, y=pq.top().second.second;
        pq.pop();
        if (visina >= bfs[x][y]) continue;
        bfs[x][y] = visina;
        if (x > 0 && bfs[x-1][y] > visina+mat[x-1][y]) pq.push({-(visina+mat[x-1][y]),{x-1,y}});
        if (y > 0 && bfs[x][y-1] > visina+mat[x][y-1]) pq.push({-(visina+mat[x][y-1]),{x,y-1}});
        if (x < n-1 && bfs[x+1][y] > visina+mat[x+1][y]) pq.push({-(visina+mat[x+1][y]),{x+1,y}});
        if (y < m-1 && bfs[x][y+1] > visina+mat[x][y+1]) pq.push({-(visina+mat[x][y+1]),{x,y+1}});
    }
    cout << bfs[n-1][m-1] << endl;

    return 0;
}
