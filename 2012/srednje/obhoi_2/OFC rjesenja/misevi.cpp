/// 786

#include <map>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <list>
#include <queue>
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define mp  make_pair       
#define coo pair<int, int>  
#define mis pair<int, coo>  

const int MAXE  = 1505;
const int MAXM = 100005;

char      labirint[MAXE][MAXE];
unsigned  udaljenost[MAXE][MAXE];
int       brojrupe[MAXE][MAXE];
mis       misevi[MAXM];
int       nr, nc, nm, nrup;
coo       rupe[4 * MAXM];

int smjer[4][2] = {
	{ 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 }
};

inline void izlaz (int r, int c, queue<coo> &q) {
	brojrupe[r][c] = nrup;
	rupe[nrup++] = mp (r, c);
	udaljenost[r][c] = 0;
	q.push (mp (r, c));		
}

inline bool valid (const coo &c, const coo &n) {
	if (n.first >= 0 && n.second >= 0 && n.first < nr && n.second < nc && labirint[n.first][n.second] != '#') {
		if (udaljenost[c.first][c.second] + 1 < udaljenost[n.first][n.second])
			return true;
		else if (udaljenost[c.first][c.second] + 1 == udaljenost[n.first][n.second]) {
			const coo &a = rupe[brojrupe[c.first][c.second]];
			const coo &b = rupe[brojrupe[n.first][n.second]];
			
			return (a.first < b.first || (a.first == b.first && a.second < b.second));
		}
		else return false;
	}
	else return false;
}

int main (void) {
 	// freopen("misevi.in","r",stdin);
	// freopen("misevi.out","w",stdout);
  
	fgets (labirint[0], MAXE, stdin);
	sscanf (labirint[0], "%d %d %d", &nr, &nc, &nm);
	for (int i = 0; i < nr; i++)
		fgets (labirint[i], MAXE, stdin);

	for (int i = 0; i < nm; i++) {
		scanf ("%d %d %d", &misevi[i].second.first, &misevi[i].second.second, &misevi[i].first);
		misevi[i].second.first--; misevi[i].second.second--;
	}
  
	memset (udaljenost, 0xff, sizeof (unsigned) * MAXE * MAXE);
	memset (brojrupe, -1, sizeof (int) * MAXE * MAXE);

	queue<coo> q;
	nrup = 0;
	for (int i = 0; i < nr; i++) {
		if (labirint[i][0] == ' ')
			izlaz (i, 0, q);
		if (labirint[i][nc - 1] == ' ') 
			izlaz (i, nc - 1, q);
	}
	for (int i = 1; i < nc - 1; i++) {
		if (labirint[0][i] == ' ') 
			izlaz (0, i, q);
		if (labirint[nr - 1][i] == ' ')
			izlaz (nr - 1, i, q);
	}
	
	while (!q.empty ()) {
		coo c = q.front (); q.pop ();
		for (int i = 0; i < 4; i++) {
			coo n = mp (c.first + smjer[i][0], c.second + smjer[i][1]);
			if (valid (c, n)) {
				q.push (n);
				udaljenost[n.first][n.second] = udaljenost[c.first][c.second] + 1;
				brojrupe[n.first][n.second] = brojrupe[c.first][c.second];
			}
		}
	}
	
	vector<map<int, mis*> > dict (nrup);
	for (int i = 0; i < nm; i++) {
		int rupa = brojrupe[misevi[i].second.first][misevi[i].second.second];
		unsigned ud = udaljenost[misevi[i].second.first][misevi[i].second.second];

		if (rupa != -1 && ud < 30 * 60) {
			map<int, mis*>::iterator it = dict[rupa].find (ud);
			if (it == dict[rupa].end ())
				dict[rupa][ud] = &(misevi[i]);
			else if (it->second->first < misevi[i].first)
				it->second = &(misevi[i]);
		}
	}

	for (int i = dict.size()-1; i >=0; i--)
		for (map<int, mis*>::iterator it = dict[i].begin (); it != dict[i].end (); it++) 
			printf ("%d %u\n", it->second->first, udaljenost[it->second->second.first][it->second->second.second]);

	return 0;
}

