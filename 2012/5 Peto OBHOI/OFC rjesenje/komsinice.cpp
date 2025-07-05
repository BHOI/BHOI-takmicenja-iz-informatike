#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXH = 699791;

struct hash_t {
	string s;
	int h;
	vector<int> nn;

	hash_t () : h (-1) {}
} ht[MAXH];

int hash (const string &s) {
	int res = 0, pow = 1;
	for (int i = 0; i < s.size (); i++) {
		res = (res + ((s[i] - 'a') * pow) % MAXH) % MAXH;
		pow = (pow * 26) % MAXH;
	}
	return res;
}

int insert (const string &s) {
	int h = hash (s);

	int i = h;
	while (ht[i].h != -1)
		i = (i + 1) % MAXH;
	ht[i].h = h;
	ht[i].s = s;
	return i;
}

int lookup (const string &s) {
	int h = hash (s);

	int i = h;
	while (ht[i].h != -1) {
		if (ht[i].h == h && ht[i].s == s)
            return i;
		i = (i + 1) % MAXH;
	}
	return -1;
}

void add_node (int h1, int h2) {
	ht[h1].nn.push_back (h2);
	ht[h2].nn.push_back (h1);
}

int parent[MAXH];
void bfs (const string &a, const string &b) {
	int ap, bp;
	if ((ap = lookup (a)) == -1 || (bp = lookup (b)) == -1 || a.size() != b.size())
        cout << "NE POSTOJI" << endl;
	else {
	    memset (parent, -1, sizeof parent);

		queue<int> q;
		q.push (ap);
		parent[ap] = -2;

		while (!q.empty ()) {
			int p = q.front (); q.pop ();
			for (int i = 0; i < ht[p].nn.size (); i++) {
				int np = ht[p].nn[i];
				if(np == bp) {
				    vector<int> sol;
				    sol.push_back (np);
					for (int ipx = p; ipx > -1; ipx = parent[ipx])
                        sol.push_back (ipx);
                    cout << sol.size() << endl;
					for(int isx = sol.size () - 1; isx >= 0; isx--)
                        cout << ht[sol[isx]].s << endl;
					return;
				}
				if (parent[np] != -1)
                    continue;
				q.push(np);
				parent[np] = p;
			}
		}
		cout << "NE POSTOJI" << endl;
	}
}


int main (void) {
	int n; cin >> n;
	string s, t;

	while (n--) {
		cin >> s;

		int sp = insert (s);
        t = s;
		for (int si = 0; si < s.size (); si++) {
			for (int c = 'a'; c <= 'z'; c++) {
				s[si] = c;
				int idx = lookup (s);
				if (idx != -1 && idx != sp)
					add_node (idx, sp);
			}
			s = t;
		}
	}

	cin >> s >> t;
	bfs (s, t);

	return 0;
}



