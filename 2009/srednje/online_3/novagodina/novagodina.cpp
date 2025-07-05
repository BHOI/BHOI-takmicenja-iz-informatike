#include <climits>
#include <iostream>

using namespace std;

#define INFINITY INT_MAX

struct Edge {
    int source, destination, weight;
};

void BellmanFord(Edge edges[], int distance[], int edgenum, int nodes)
{
    for (int i=0; i < nodes; ++i)
    {
        for (int j=0; j < edgenum; ++j)
        {
            if (distance[edges[j].source] != INFINITY)
            {
                int tmp = distance[edges[j].source] + edges[j].weight;
                if (tmp < distance[edges[j].destination])
                    distance[edges[j].destination] = tmp;
            }
        }
    }
}

int main()
{
    freopen("novagodina.in", "r", stdin);
    freopen("novagodina.out", "w", stdout);
    int n,m,k,l;
    cin >> n >> m >> k >> l;
    Edge edges[2*m];
    for (int i=0; i < m; ++i)
    {
        int s, d, w;
        cin >> s >> d >> w;
        edges[2*i].source = s;
        edges[2*i].destination = d;
        edges[2*i].weight = w;
        edges[2*i+1].source = d;
        edges[2*i+1].destination = s;
        edges[2*i+1].weight = w;
    }
    int distance[n];
    for (int i=0; i < n; ++i)
       distance[i] = INFINITY;
    for (int i=0; i < k; ++i)
    {
        int g, h;
        cin >> g >> h;
        distance[g] = h;
    }
    BellmanFord(edges, distance, 2*m, n);
    for (int i=0; i < l; ++i)
    {
        int tmp;
        cin >> tmp;
        if (distance[tmp] != INFINITY)
            cout << distance[tmp] << "\n";
        else
            cout << "N/A\n";
    }
    fclose(stdin);
    fclose(stdout);
}
