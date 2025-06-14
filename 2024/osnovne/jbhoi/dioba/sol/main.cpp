// Previse spor za veliko N

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
Za svaki slučaj testiranja, prvo pročitamo broj N, K i S.
N je broj čvorova.
Za svaki od K parova radimo union find, tretiramo spojene čvorove kao jedan čvor.
Spajamo graf preko S parova, te radimo bipartitno uparivanje (bipartite matching).
*/

int main() {
	ios_base::sync_with_stdio(false);
	int R;
	cin >> R;

	while(R--) {
		int N, K, S;
		cin >> N >> K >> S;

		vector<int> parent(N), Ka(K), Kb(K);
		vector<bool> mentioned(N, false);
		for(int i=0;i<N;i++) parent[i] = i;

		for(int i=0;i<K;i++) {
			cin >> Ka[i] >> Kb[i];
			Ka[i]--; Kb[i]--;
			int a = Ka[i], b = Kb[i];
			mentioned[a] = true;
			mentioned[b] = true;

			if(a > b) swap(a, b);
			while(parent[a] != a) a = parent[a];
			while(parent[b] != b) b = parent[b];
			parent[b] = a;
		}

		int p;
		for(int i=0;i<N;i++) {
			if(!mentioned[i]) continue;
			p = i;
			while(parent[p] != p) p = parent[p];
			parent[i] = p;
		}

		// Upisati S parove

		vector<int> Sa(S), Sb(S);
		for(int i=0;i<S;i++) {
			cin >> Sa[i] >> Sb[i];
			Sa[i]--; Sb[i]--;
			mentioned[Sa[i]] = true;
			mentioned[Sb[i]] = true;
		}

		// Prvo provjeriti slučaj da li K parovi spajaju sve čvorove

		vector<vector<int>> graph_orig(N);
		for(int i=0;i<K;i++) {
			int a = Ka[i], b = Kb[i];
			graph_orig[a].push_back(b);
			graph_orig[b].push_back(a);
		}
		vector<bool> visited(N, false);
		queue<int> q;
		q.push(0);
		int num_visited = 0;
		while(!q.empty()) {
			int node = q.front();
			q.pop();
			if(visited[node])
				continue;
			visited[node] = true;
			num_visited++;
			for(int i=0;i<graph_orig[node].size();i++) {	
				int next = graph_orig[node][i];
				if(!visited[next]) {
					q.push(next);
				}
			}
		}
		if(num_visited == N) {
			cout << "NE" << endl;
			continue;
		}

		// Nisu svi čvorovi spojeni
		// Sve spojene komponente tretiramo kao pojedinačne čvorove
		// Radimo bipartitno uparivanje preko S parova

		vector<vector<int>> bipartite_graph(N);
		for(int i=0;i<S;i++) {
			int a = Sa[i], b = Sb[i];
			while(parent[a] != a) a = parent[a];
			while(parent[b] != b) b = parent[b];
			bipartite_graph[a].push_back(b);
			bipartite_graph[b].push_back(a);
		}

		vector<int> team(N, -1);
		visited = vector<bool>(N, false);
		q = queue<int>();
		int node, next;
		bool ok = true;

		for(int i=0;i<N;i++) {
			if(!mentioned[i]) continue;
			if(parent[i] != i) continue;
			if(team[i] != -1) continue;
			
			
			q = queue<int>();
			team[i] = 0;
			q.push(i);
			while(!q.empty()) {
				// BFS sa bipartitnim uparivanjem
				node = q.front();
				q.pop();
				if(visited[node])
					continue;
				visited[node] = true;
				for(int j=0;j<bipartite_graph[node].size();j++) {
					next = bipartite_graph[node][j];
					
					if(team[next] == -1) {
						team[next] = 1 - team[node];
						q.push(next);
					} else if(team[next] == team[node]) {
						// Učenici "next" i "node" su u istom timu, a ne smiju biti
						ok = false;
						break;
					}
				}
				if(!ok) break;
			}
			if(!ok) break;
		}
		if(ok) {
			cout << "DA" << endl;
		}
		else {
			cout << "NE" << endl;
		}
	} 


	return 0;
}