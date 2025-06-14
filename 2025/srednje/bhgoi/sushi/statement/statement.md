# Sushi

Preko ljeta ste otišli u Japan sa planom da osjetite fantastičnu kulturu i izvanredno gostoprimstvo, no gastronomsko iskustvo vas je nagovorilo da se okušate u radu u sushi restoranu. No, prije nego što možete raditi sa ribom, prvo morate raditi razne neobične poslove za sushi majstore.

Vaš prvi zadatak u restoranu je vezan za najvažniji sastojak sushija, rižu! 

Sushi se šalje iz kuhinje prema stolovima pokretnom trakom. Svaki komad sushija sadržava određeni broj zrna riže, a vaš zadatak je odgovarati na upite tipa koliko se zrna riže nalazi trenutno na traci. 

Upis se sastoji od niza naredbi, gdje svaka naredba pripada jednoj od 3 tipa:
- Naredba `0` zahtjeva da ispišete trenutni broj zrna riže na traci;
- Naredba `1 A B` (gdje su `A` i `B` prirodni brojevi) ukazuje da je na početak trake dodano `A` komada sushija sa po `B` zrna riže;
- Naredba `2 C` (gdje je `C` prirodan broj) ukazuje da se sa kraja trake pojelo posljednjih `C` komada sushija.

Prije prve naredbe traka je prazna.

## Ulazni podaci
Prvi red sadrži $N$, broj naredbi.\
Idućih $N$ redova sadrži naredbu u skladu sa opisom zadatka.

### Ograničenja
$1 \leq N \leq 10\;000$\
$1 \leq A, B, C \leq 1\;000\;000$\
Zagarantovano je da se nikada neće jesti više komada sushija nego što se nalazi na traci.

## Podzadaci

### Podzadatak 1 (5 bodova)
$N=2$\
$1 \leq A, B, C \leq 100$\
Druga naredba će sigurno biti naredba `0`.

### Podzadatak 2 (41 bod)
$N \leq 100$\
$1 \leq A, B, C \leq 100$

### Podzadatak 3 (11 bodova)
Neće biti naredbi tipa `2 C`.

### Podzadatak 4 (18 bodova)
$B$ (broj zrna riže u jednom komadu sushija) će uvijek biti jednako $1\;000\;000$.

### Podzadatak 5 (25 bodova)
Bez dodatnih ograničenja.

## Izlazni podaci

Za svaku `0` naredbu iz ulaza potrebno je ispisati trenutni broj zrna riže na traci u odvojenom redu.

## Primjeri
### Ulaz 1
```
2
1 3 5
0
```
### Izlaz 1
```
15
```
### Objašnjenje 1
Upis se sastoji od 2 naredbe. Prva je naredba dodavanja, dodatna su 3 komada sushija sa po 5 zrna riže. Druga naredba zahtjeva ispis trenutnog broja zrna riže, što je 15.

### Ulaz 2
```
5
1 3 4
0
1 10 10
2 5
0
```
### Izlaz 2
```
12
80
```
### Objašnjenje 2
Upis se sastoji od 5 naredbi.

Nakon prvog dodavanja na traci imamo 3 komada sushija sa po 4 zrna riže, dakle 12 zrna ukupno. Nakon drugog dodavanja imamo još 100 zrna riže, dakle ukupno 112. Oduzimanjem 5 komada ostaje samo 8 od 10 komada sushija dodana u drugom dodavanju, čime preostaje 80 zrna riže.

### Ulaz 3
```
9
0
1 50 20
0
2 45
0
1 10 100
0
2 15
0
```
### Izlaz 3
```
0
1000
100
1100
0
```