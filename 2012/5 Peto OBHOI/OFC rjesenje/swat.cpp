#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

bool discovered[100005];
bool visited[100005];
int time_entry[100005], time_exit[100005];

vector<int> v[100005];

inline void dfs(int start)
{
	int time = 1, temp;
	stack<int> s;
	s.push(start);
	s.push(start);
	discovered[start] = 1;
	while (s.size()){
		temp = s.top(); s.pop();
		if (visited[temp]){
			time_exit[ temp ] = time++;
		}
		else {
			time_entry[ temp ] = time++;
			visited[temp] = 1;
			for (int i=0; i < v[ temp ].size(); i++)
				if (!discovered[ v[ temp ][i] ]){
					s.push( v[temp][i] );
					s.push( v[temp][i] );
					discovered[ v[temp][i] ] = 1;
				}
		}
	}
}

int main()
{
	freopen("swat.in", "r", stdin);
	freopen("swat.out", "w", stdout);
	int n;
	int a, b;
	scanf("%d\n", &n);
	for (int i=0; i<n-1; i++){
		scanf("%d %d\n", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	for (int i=1; i <= n; i++){
		printf("%d\n", (time_exit[i] - time_entry[i] - 1)/2);
	}
	return 0;
}

