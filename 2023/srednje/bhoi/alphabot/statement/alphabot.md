# Alphabot
Microsoft je od skoro razvio prototip novog alfabetskog robota i nazvali su ga Alphabot. U suštini, način na koji on funkcionise je tako sto u bazi ima određenu riječ duzine `N` koja se sastoji od malih slova engleskog alfabeta i u zavisnosti od ulaznih parametara, vraća određeni rezultat.

Postoje dva ulazna parametra. Prvi parametar `c` je slovo koje se posmatra, a drugi parametar `m` označava koliko je najviše izmjena dozvoljeno da robot napravi. Nakon što izmijeni najviše `m` slova date riječi u neka potpuno druga slova, on skenira sve moguće podsegmente koji se sastoje samo od slova `c` i vraća kao rezultat najduži od njih. 

Na primjer, ako posmatramo riječ *"oboooa"* i ako uzmemo slovo *"o"* u razmatranje, najduži podsegment je *"ooo"* i dužina mu je 3.

Potrebno je napisati tester za ovog robota. Tester se piše tako što se odgovara na `q` upita od kojih svaki na ulazu ima 2 parametra: `m` i `c` koji su opisani gore. Svaki upit se izvršava nezavisno od drugog i za svaki je potrebno ispisati koji je najduži segment koji se sastoji samo od slova `c` nakon najviše `m` izmjena.

## Ulaz
Prva linija na ulazu sadrži pozitivan cijeli broj `N` – dužina riječi u bazi.

Druga linija sadrži tu riječ od `N` slova.

Treća linija sadrži cijeli broj `Q` – broj upita.

Sljedećih `Q` linija sadrže po 2 cijela broja: `m` (maksimalan broj slova koje je moguce izmijeniti) i `c` (slovo koje se uzima u obzir).

### Ograničenja
```
1 <= N <= 1500
1 <= Q <= 200000
1 <= m <= N
c je malo slovo engleske abecede
```
### Podzadaci
* Podzadatak 1 (30 bodova) - `1 <= N <= 30`
* Podzadatak 2 (30 bodova) - Riječ u bazi je sastavljena samo od slova *"a"* i *"b"*
* Bez dodatnih ograničenja (40 poena)

## Izlaz
Izlaz sadrži `Q` linija – za *i*-ti upit potrebno je ispisati duzinu najdužeg podsegmenta koji se sastoji samo od slova `c[i]` nakon najvise `m[i]` izmjena.

## Primjeri
### Ulaz 1
```
10
takmicenje
3
2 e
4 e
8 i
```
### Izlaz 1
```
4
6
9
```
### Objašnjenje 1
* Ako zamijenimo slova *"n"* i *"j"*, dobijamo podsegment dužine *4*.
* Optimalna riječ je *"takmeeeeee"*, pa je rješenje *6*.
* *"iiiiiiiiie"* ili *"tiiiiiiiii"* su validne riječi.
### Ulaz 2
```
3
ioi
2
2 i
1 b
```
### Izlaz 2
```
3
1
```
