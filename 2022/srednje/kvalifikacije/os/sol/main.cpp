// U ovom implementacijskom zadatku potrebno je samo tačno simulirati postupak opisan u tekstu. 
// Vjerovatno najlakši pristup se postiže korištenjem dinamičkih struktura podataka - hijerarhija direktorija 
// je stablo u kojemu svaki čvor odgovara jednom direktoriju te sadrži pokazivače na direktorije koje 
// direktno sadrži te na direktorij u kojemu je direktno sadržan. Međutim, ovdje ćemo opisati rješenje koje 
// ne koristi dinamičke strukture podataka nego samo jednodimenzionalna polja.
// Root direktorij ćemo označiti brojem 0, a ostale direktorije ćemo prilikom stvaranja označavati redom 
// brojevima 1, 2, 3, itd. Za svaki direktorij pamtimo sljedeće vrijednosti: Brojnu oznaku direktorija u 
// kojem je direktorij direktno sadržan, ime direktorija, te da li je direktorij izbrisan ili ne.
// int parent[MAX];
// string name[MAX];
// int deleted[MAX];
// Dodatno, u svakom trenutku pamtimo indeks trenutnog direktorija i ukupni broj direktorija napravljenih 
// do sada. Sve zadane operacije se na jednostavan način daju implementirati kao operacije na ova tri polja. 
// Na primjer, naredba ‘rmdir X’ se radi na sljedeći način:
// 1. Najprije prolaskom kroz polja tražimo indeks direktorija X kojeg treba izbrisati, njega ćemo 
// prepoznati lako, to je jedinstveni direktorij koji nije izbrisan, ima ime X i roditelj mu je upravo 
// trenutni direktorij (!deleted[i] && name[i] == X && parent[i] == current)
// 2. Ako nismo našli takav direktorij ispisujemo ‘greska’.
// 3. Provjeravamo da li je direktorij prazan tako da probamo naći bilo koji neizbrisani direktorij koji je 
// sadržan u X (opet još jednim prolaskom kroz polja). 
// 4. Ako direktorij nije prazan ispisujemo ‘greska’.
// 5. Brišemo direktorij tako da samo postavimo vrijednost polja deleted na istinu.
// 6. Putanju direktorija računamo tako da u while petlji spajamo imena direktorija dok ne dođemo do 
// root direktorija. 
// Ostale naredbe se implementiraju na analogan način.

#include <iostream>
#include <string> 

using namespace std;

const int MAX = 102;
const string ERROR = "greska";

int k;
int parent[MAX];
string name[MAX];
int deleted[MAX];
int current;

int add(string dirname, int dirparent) {
  parent[k] = dirparent;
  name[k] = dirname;
  deleted[k] = 0;
  return k++;
}

int find(string dirname, int dirparent) {
  for (int i=0; i<k; i++)
    if (name[i] == dirname && parent[i] == dirparent && !deleted[i])
      return i;
  return -1;
}

int empty(int dir) {
  for (int i=0; i<k; i++)
    if (parent[i] == dir && !deleted[i])
      return 0;
  return 1;
}

string path(int d) {
  if (d == 0)
    return "/";
  string sol;
  while (d != 0) {
    sol = "/" + name[d] + sol;
    d = parent[d];
  }
  return sol;
}

string mkdir(string x) {
  if (find(x, current) != -1)
    return ERROR;
  int newdir = add(x, current);
  return path(newdir);
}

string rmdir(string x) {
  int todel = find(x, current);
  if (todel == -1)
    return ERROR;
  if (!empty(todel))
    return ERROR;
  string sol = path(todel);
  deleted[todel] = 1;
  return sol;
}

string cd(string x) {
  if (x == "..") {
    if (current == 0)
      return ERROR;
    current = parent[current];
    return path(current);
  }
  int newdir = find(x, current);
  if (newdir == -1)
    return ERROR;
  current = newdir;
  return path(current);
}

int main() {
  k = 1;
  current = 0;
  name[0] ="";
  parent[0] = -1;
  deleted[0] = 0;
  int n;
  cin >> n;
  for (int i=0; i<n; i++) {
    string a, b;
    cin >> a >> b;
    if (a == "cd")
      cout << cd(b) << endl;
    if (a == "mkdir")
      cout << mkdir(b) << endl;
    if (a == "rmdir")
      cout << rmdir(b) << endl;
  }
  return 0;
}
