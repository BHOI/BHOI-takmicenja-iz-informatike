// Primijetimo da zadatak možemo riješiti tako da razmatramo jedan po jedan blok, za svaki blok nađemo 
// vrijeme potrebno da od početnog stanja dobijemo traženo te saberemo sva ta vremena. Naime, svaka 
// operacija mijenja samo jedan blok pa je jasno da je ovo ispravan pristup.
// Za pojedini blok postupak je sljedeći:
// 1. Ako postoji bit koji je na početku 0, a treba biti 1 onda nemamo izbora – moramo cijeli blok 
// najprije pretvoriti u 1.
// 2. Za svaki bit koji je 1 a treba biti 0 pretvorimo ga u nulu.
// Ovaj algoritam se može jednostavno implementirati tako da se vrijednost memorije čuva u stringu te se sa 
// jednom for petljom prolazi kroz sve blokove, a drugom kroz pojedine bitove u bloku. Na temelju indeksa 
// bloka i indeksa bita unutar bloka se lagano izračuna indeks u stringovima koji sadrže bitove.

#include <iostream>
#include <string>

using namespace std;

int main() {
  int blocks, cells;
  string mem_a, mem_b;
  cin >> blocks >> cells;
  cin >> mem_a >> mem_b;
  int ret = 0;
  for (int i = 0, curr = 0; i < blocks; i++, curr += cells + 1) {
    string block_a = mem_a.substr(curr, cells);
    string block_b = mem_b.substr(curr, cells);
    bool set_all = false;
    for (int j = 0; j < cells; j++) {
      if (block_a[j] == '0' && block_b[j] == '1') set_all = true;
    }
    if (set_all) {
      ret += 100;
      for (int j = 0; j < cells; j++) {
        if (block_b[j] == '0') ret++;
      }
    } else {
      for (int j = 0; j < cells; j++) {
        if (block_a[j] == '1' && block_b[j] == '0') ret++;
      }
    }
  }
  cout << ret << endl;
  return 0;
}
