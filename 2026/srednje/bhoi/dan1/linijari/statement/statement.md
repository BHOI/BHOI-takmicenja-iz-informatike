# Linijari

Melika želi provjeriti da li je njen krevet baš dug koliko roditelji govore da jeste. Kako bi to uradila, koristit će linijare. 
Melika će naredati linijare dužinom i ako taj mega-linijar može doći od jednog kraja kreveta do drugog onda će Melika moći izmjeriti svoj krevet.

Pomozi Meliki da utvrdi može li linijarima izmjeriti dužinu $X$.

Sretno takmičenje!

## Ulazni podaci

U prvom redu nalaze se dva cijela broja $N$ i $X$, gdje je $N$ broj linijara, a $X$ dužina koju Melika želi izmjeriti.

U drugom redu nalazi se $N$ cijelih brojeva odvojeni razmakom $a_1, a_2, \ldots, a_N$, koji predstavljaju dužine linijara.

### Ograničenja

- $1 \leq N \leq 1\;000$
- $1 \leq X \leq 10^9$
- $1 \leq a_i \leq 10^6$

## Podzadaci

### Podzadatak 1 (24 boda)

- $N = 1$

### Podzadatak 2 (44 boda)

- $N \leq 100$
- $X \leq 100$
- $a_i \leq 100$

### Podzadatak 3 (32 boda)

Nema dodatnih ograničenja.

## Izlazni podaci

Ispisati `DA` ako Melika može izmjeriti dužinu $X$, ili `NE` u suprotnom.

## Primjeri

### Ulaz 1
```
3 10
3 4 5
```
### Izlaz 1
```
DA
```
### Objašnjenje 1
Ako Melika poreda sve linjare redom onda će imati mega-linijar dužine 12, što je dovoljno da izmjeri krevet dužine 10.

### Ulaz 2
```
2 15
6 7
```
### Izlaz 2
```
NE
```
### Objašnjenje 2
Melika ne može izmjeriti krevet dužine 15 jer nema dovoljno velik linijar, čak i ako poreda sve svoje linijare s kraja na kraj.


### Ulaz 3
```
1 30
30
```
### Izlaz 3
```
DA
```
### Objašnjenje 3
Melika ima samo jedan linijar, ali je on taman dovoljno dug da izmjeri svoj krevet.

