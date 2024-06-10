# Kiša
Data vam je slika kiše, a vaš cilj je naći koliko je duga najduža kapljica kiše na toj slici.

Slika je data kao dvodimenzionalni niz karaktera `.` (*koji predstavlja prazan prostor*) ili `#` (*koji predstavlja kap ili dio kapljice*). Kapljice padaju prema dole i sa ulaza se vide kao vertikalna linija napravljena od `#` karaktera. Jedna kapljica se smatra kao jedan uzastopni vertikalni niz `#` karaktera. Kapljice mogu dodirivati druge kapljice s lijeve ili desne strane, ali se sve one računaju kao različite kapljice.

Na izlazu ispišite jedan broj - koliko je duga najduža kapljica na slici.

## Ulaz
Na prvoj liniji standardnog ulaza data su 2 broja: `w` i `h`, koji predstavljaju širinu (width) i visinu (height) slike.

Nakon toga se unosi `h` stringova `w` širine. Stringovi mogu imati samo karaktere `.` ili `#`.

### Ograničenja
```
1 <= w, h < 1000
u 25% testnih primjera sve kapljice su iste visine
```
*vremensko ograničenje izvršenja programa je 1s*

## Izlaz
Na prvoj i jedinoj liniji standardnog izlaza treba ispisati jedan broj - dužina najduže kapljice na slici.

## Primjeri
### Ulaz 1
```
3 5
...
##.
##.
#..
##.
```
### Izlaz 1
```
4
```
*kapljica koja se nalazi u prvoj koloni, a koja se proteže od drugog do zadnjeg reda je najduža*
### Ulaz 2
```
8 4
...#...#
.#.#.#.#
.#...##.
...#..#.
```
### Izlaz 2
```
2
```
*na slici se nalazi 5 kapljica dužine 2*