# PIN

Martin je nedavno zaposlen kao administrator računarskog sistema u velikoj kompaniji. Kompanija nije mijenjala svoj sistem autorizacije još od 1980-ih godina. Svaka osoba ima lični identifikacioni broj (PIN) koji se sastoji od četiri znaka (nisu nužno različiti).

Kako je kompanija rasla, dodana je mogućnost korištenja i slova, ali je dužina PIN-a ostala ista.

Martin nije zadovoljan ovakvim sistemom. Pretpostavimo da postoje osobe čiji se PIN-ovi razlikuju u samo jednom znaku, na primjer `61ab` i `62ab`. Ako prva osoba slučajno pritisne `2` umjesto `1`, sistem bi je i dalje mogao prijaviti kao drugu osobu.

Martin zato želi napraviti statistiku o PIN-ovima koji su trenutno u upotrebi. Posebno ga zanima koliko postoji parova PIN-ova koji se razlikuju u tačno jednoj poziciji. Nada se da će taj broj biti dovoljno zabrinjavajući da uvjeri svog šefa da uloži u sigurniji sistem.

## Zadatak

Dat je spisak PIN-ova koji su trenutno u upotrebi. Potrebno je odrediti broj parova PIN-ova koji se razlikuju u tačno jednoj poziciji.

## Ulaz

U prvom redu ulaza nalazi se jedan pozitivan cijeli broj $ N $, broj PIN-ova.

Svaki od narednih $ N $ redova sadrži po jedan PIN.

## Ograničenja

Možete pretpostaviti da u svim test primjerima važi:

- $ ( 1 \le N \le 50000 ) $

Svaki PIN:

- ima tačno 4 znaka
- svaki znak je ili cifra ili malo slovo engleske abecede od `a` do `z`

## Izlaz

Ispišite jedan cijeli broj: broj parova PIN-ova koji se razlikuju u tačno jednoj poziciji.

## Podzadaci
N $ \le $ 1000 - 30 poena

Bez ograničenja - 70 poena

## Primjer 1

### Ulaz

```text
4
0010
a010
0202
a000
```

### Izlaz

```text
2
```
### Objašnjenje
Parovi koji se razlikuju za jedan su (```0010```, ```a010```) i (```a010```, ```a000```).

## Primjer 2
### Ulaz
``` text
3
0000
0001
0001
```
### Izlaz
```
2
```
