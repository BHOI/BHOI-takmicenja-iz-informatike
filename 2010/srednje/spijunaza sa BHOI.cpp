#include <fstream>
#include <algorithm>

using namespace std;

long parent[1000001];
long tree_size[1000001];

struct edge_info {
	long cost;
	long point1;
	long point2;
};

edge_info edges[2020001];

long find_root(long vertex)
{
	if (parent[vertex]==vertex)
		return vertex;
	else return parent[vertex]=find_root(parent[vertex]);
}

bool combine_components(long vertex1, long vertex2)
{
	long r1=find_root(vertex1);
	long r2=find_root(vertex2);
	if (r1==r2) return 0;
	if (tree_size[r1]<tree_size[r2]){
		tree_size[r2]+=tree_size[r1];
		parent[r1]=r2;
		return 1;
	}
	tree_size[r1]+=tree_size[r2];
	parent[r2]=r1;
	return 1;
}

bool compare (edge_info e1, edge_info e2)
{
	return (e1.cost<e2.cost);
}

int main()
{
	FILE * fin=fopen("spijunaza.in", "r");
	FILE * fout=fopen("spijunaza.out", "w");
	long n,k,m,i,a,b;
	unsigned long long length=0;
	fscanf(fin, "%ld %ld %ld", &n, &k, &m);
	for (i=1;i<=n;i++)
		parent[i]=i, tree_size[i]=1;
	for (i=0;i<k;i++){
		fscanf(fin, "%ld %ld", &a, &b);
		combine_components(a, b);
	}
	for (i=0;i<m;i++){
		fscanf(fin, "%ld %ld %ld", &edges[i].point1, &edges[i].point2, &edges[i].cost);
	}
	sort(edges, edges+m, compare);
	for (i=0;i<m;i++){
		if (!combine_components(edges[i].point1, edges[i].point2)) continue;
		length+=edges[i].cost;
	}
	fprintf(fout, "%llu\n", length);
	return 0;
}
