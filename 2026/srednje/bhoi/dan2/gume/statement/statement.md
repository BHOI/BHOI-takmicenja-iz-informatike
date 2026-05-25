# Gume

Hadžem ponovo mijenja gume na automobilu. Ispred servisa nalazi se red od $N$ automobila. Gume su raspoređene u mreži od 2 reda i $2N$ kolona, gdje svaki automobil zauzima blok $2 \times 2$: automobil $i$ zauzima kolone $2i-1$ i $2i$ (za $i = 1, 2, \ldots, N$).

Hadžemov automobil je prvi u redu (kolone 1 i 2). Kako bi mogao voziti, sve 4 gume na njegovom automobilu moraju biti iste veličine.

Gume je moguće zamijeniti s bilo kojom susjednom gumom (gore, dolje, lijevo ili desno). Dijagonalne zamjene nisu dozvoljene. Gume s ostalih automobila mogu se koristiti.

Pronađi minimalan broj zamjena susjednih guma potrebnih da sve 4 gume Hadžemovog automobila budu iste veličine.

## Ulazni podaci

U prvom redu nalazi se cijeli broj $N$, broj automobila.

U naredna 2 reda nalazi se po $2N$ cijelih brojeva koji predstavljaju veličine guma u mreži, redom po redovima.

### Ograničenja

- $1 \leq N \leq 1\;000$
- $1 \leq g_{i,j} \leq 10^6$
- Garantuje se da postoji barem jedna veličina gume koja se pojavljuje barem 4 puta u mreži.

## Testni primjeri

Ovaj zadatak ne koristi podzadatke za bodovanje, već pojedinačne testne primjere koji nose po jednak broj bodova.

U testnim primjerima koji nose $20\%$ bodova vrijedi $N = 2$.

## Izlazni podaci

Ispisati jedan cijeli broj: minimalan broj zamjena guma.

## Primjeri

### Ulaz 1
```
2
3 1 3 3
3 1 3 3
```
### Izlaz 1
```
2
```
### Objašnjenje 1
Hadžemov automobil ima gume: 3, 1, 3, 1. Zamjenom gume na poziciji (1,2) sa gumom na poziciji (1,3) dobijamo trojku na poziciji (1,2). Zamjenom gume na poziciji (2,2) sa gumon na poziciji (2,3) dobijamo trojku na poziciji (2,2). Sve 4 gume na Hadžemovom automobilu su iste veličine, a napravljene su ukupno 2 zamjene.

### Ulaz 2
```
1
5 5
5 5
```
### Izlaz 2
```
0
```
### Objašnjenje 2
Sve gume Hadžemovog automobila su već iste veličine, nije potrebna nijedna zamjena.

### Ulaz 3
```
4
2 4 2 3 3 5 4 5
3 4 2 3 5 2 4 5
```
### Izlaz 3
```
7
```
### Objašnjenje 3
Minimalan broj zamjena je 7, i to je samo moguće ako se odaberu gume veličine 2. 

### Ulaz 4
```
5
14 20 15 20 16 20 17 10 20 11
12 13 14 15 16 17 10 11 12 13
```
### Izlaz 4
```
17
```

### Ulaz 5
```
5
21 15 16 17 21 10 11 21 12 13
14 15 16 21 17 10 11 12 13 14
```
### Izlaz 5
```
13
```

### Ulaz 6
```
5
16 17 22 10 11 12 13 14 22 15
16 22 17 10 11 12 22 13 14 15
```
### Izlaz 6
```
15
```

### Ulaz 7
```
6
17 10 11 12 13 23 14 15 16 17 10 11
23 12 13 14 23 15 16 17 10 23 11 12
```
### Izlaz 7
```
17
```

### Ulaz 8
```
6
10 11 12 13 14 15 16 17 10 11 12 13
14 15 24 16 17 24 10 24 11 12 24 13
```
### Izlaz 8
```
24
```
