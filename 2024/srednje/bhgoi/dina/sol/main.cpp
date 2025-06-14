#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n, a, b, x, y;
	cin >> n;
	cin >> a >> b;
	cin >> x >> y;
	
	vector<vector <int>> graf(n); // graf držimo kao listu susjedstva

	for(int i = 0; i < n-1; i++) {
		int cvor1, cvor2;
		cin >> cvor1 >> cvor2;
		graf[cvor1].push_back(cvor2);
		graf[cvor2].push_back(cvor1);
	}

	// BFS

	vector<int> udaljenosti(n, 0); // udaljenost od početnog čvora (čvor a)
	vector<bool> posjecen(n, false); // je li čvor posjećen

	queue<int> q;

	q.push(a);
	posjecen[a] = true;
	while (!q.empty()) {
		int cvor = q.front();
		q.pop();
		if(cvor == b) {
			break;
		}
		for (int susjed : graf[cvor]) {
			if (!posjecen[susjed]) {
				posjecen[susjed] = true;
				udaljenosti[susjed] = udaljenosti[cvor] + 1;
				q.push(susjed);
			}
		}
	}
	
	int br_poteza = (udaljenosti[b]+x-2*y-1)/(x-y);

	if(br_poteza < 1) {
		br_poteza = 1;
	}

	cout << br_poteza << endl;

	return 0;
}

/*
9
6 0
4 1
0 1
1 2
2 3
2 4
4 5
5 6
4 7
4 8

Kretanje je:
6 -> 5 -> 4 -> 2 -> 1 -> 2 -> 1 -> 0
*/