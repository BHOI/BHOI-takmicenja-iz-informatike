// Za određivanje je li sredina niza veći ili jednak K nisu bitne tačne vrijednosti elemenata, već samo jesu li 
// veći ili jednaki K. Zato možemo niz zapisati tako da brojeve manje od K zamijenimo s -1, a veće ili 
// jednake K s 1. Primijetite da ako takav niz ima pozitivnu sumu da to upravo znači da mu je i sredina 
// barem K. Preostali dio problema je efikasno prebrojati koliko ima takvih uzastopnih podnizova.
// Proći ćemo po nizu od početka do kraja i pritom pratiti vrijednosti suma svih intervala koji završavaju na 
// trenutnoj poziciji. Preciznije, ako smo sad na elementu i, tada znamo sume intervala [i, i], [i - 1, i], ..., 
// [1, i], [0, i], i želimo moći efikasno provjeriti koliko je takvih suma pozitivno, za šta ćemo iskoristiti 
// odgovarajuću strukturu podataka. Primijetite da proširivanje s i na i + 1 odgovara dodavanju nule u 
// strukturu te povećavanju svih elemenata u strukturi za A[i + 1].
// Kako bismo ostvarili navedeno potrebna nam je struktura podataka koja podržava sljedeće operacije:
// - ubaci_nulu() -> ubacuje broj 0 u strukturu
// - povećaj_sve(x) -> povećava sve brojeve u strukturi za x
// - prebroji_pozitivne() -> vraća broj pozitivnih brojeva u strukturi
// Operacija povećaj_sve sugerira korištenje pomoćnog brojača s kojeg povećavamo umjesto povećavanja 
// svih brojeva u strukturi. Kako bi to funkcionisalo, u strukturu umjesto 0 ubacujemo -s (jer je -s + s = 0).
// Uz ovaj brojač potrebna nam je struktura s nešto klasičnijim operacijama:
// - ubaci_broj(x) -> ubacuje broj x u strukturu
// - prebroji_veće(x) -> vraća broj brojeva u strukturi većih od x
// Kao što smo rekli,
// - ubaci_nulu() se sada implementira kao ubaci_broj(-s).
// - povećaj_sve(x) se implementira kao s += x.
// - prebroji_pozitivne() se implementira kao prebroji_veće(-s).
// Za niz dužine n složenost ovakve obrade je O(n log n) pod uvjetom da operacije nad strukturom imaju 
// složenost O(log n).
// Operacije ubaci_broj(x) i prebroji_veće(x) u složenosti O(log n) podržava svako balansirano binarno stablo, 
// ali i implementacijski puno jednostavnija logaritamska struktura (koja zapravo po upitu ima složenost 
// O(log V), gdje je V maksimalna vrijednost broja u strukturi, što je još uvijek dovoljno efikasno). Za detalje 
// pogledajte i binarno indeksirano stablo: https://www.topcoder.com/thrive/articles/Binary%20Indexed%20Trees.

#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

class Logaritamska
{
public:
  Logaritamska(int n)
  {
    this->n = n;
    data.resize(2 * n + 2);
  }

  void dodaj(int indeks, int val)
  {
    for (indeks += n + 1; indeks < (int)data.size(); indeks += indeks & -indeks)
      data[indeks] += val;
  }

  /**
   * Sumiraj sve vrijednosti od pocetka do indeksa ukljucivo.
   */
  int sumiraj(int indeks)
  {
    int ret = 0;
    for (indeks += n + 1; indeks > 0; indeks -= indeks & -indeks)
      ret += data[indeks];
    return ret;
  }

private:
  int n; // [-n, n]
  vector<int> data;
};

int main()
{
  cin.sync_with_stdio(false); // da bude jednako brz kao i scanf
  int n, k, a, delta = 0;
  long long ret = 0;
  cin >> n >> k;
  Logaritamska l(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a;
    if (a >= k)
      a = 1;
    else
      a = -1;
    delta += a;
    l.dodaj(a - delta, 1);
    int curr = (i + 1) - l.sumiraj(-delta);
    // cout << curr << endl;
    ret += curr;
  }
  cout << ret << endl;
  return 0;
}
