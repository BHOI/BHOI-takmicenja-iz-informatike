# Bazen

Red je na Muamera da čisti lokalni olimpijski bazen. Njegov cilj je da ga što bolje očisti podvodnim usisivačem, no kada usisa jednu pločicu bazena Muamer poremeti vodu oko te pločice i više ne može usisati susjedne pločice. Pomozite Muameru tako što odredite koje pločice treba usisati kako bi uklonio što više prljavštine sa bazena.

Bazen se sastoji od $N$ redova i $M$ kolona pločica. Svaka pločica ima određenu količinu prljavštine $D_{i,j}$. Kada Muamer usisa pločicu, on ne može usisati nijednu od njenih četiri susjedne pločice (gore, dolje, lijevo, desno). Muamer želi odabrati skup pločica za usisavanje tako da nijedne dvije odabrane pločice nisu susjedne, a ukupna količina uklonjene prljavštine bude što veća.

Svaki treći red bazena ($3$, $6$, $9$, $\ldots$) je već čist, tj. sve pločice u tom redu imaju količinu prljavštine $0$.

## Ulazni podaci
Prvi red ulaza sadrži dva cijela broja $N$ i $M$, broj redova i kolona bazena.

Idućih $N$ redova sadrži po $M$ cijelih brojeva $D_{i,j}$, koji predstavljaju količinu prljavštine na pločici u $i$-tom redu i $j$-toj koloni.

### Ograničenja
$1 \leq N, M \leq 1\;000$

$0 \leq D_{i,j} \leq 1\;000$

$D_{i,j} = 0$ za svaki $i$ takav da je $i$ djeljivo sa $3$ (redovi $3, 6, 9, \ldots$)

## Podzadaci

### Podzadatak 1 (5 bodova)
$M = 1$

### Podzadatak 2 (12 bodova)
$N = 1$, $N \times M \leq 20$

### Podzadatak 3 (9 bodova)
$N \times M \leq 20$

### Podzadatak 4 (23 bodova)
$N = 1$

### Podzadatak 5 (25 bodova)
$N \leq 3$

### Podzadatak 6 (26 bodova)
Bez dodatnih ograničenja.

## Izlazni podaci

U prvi red ispišite jedan cijeli broj, najveću moguću količinu uklonjene prljavštine.

U idućih $N$ redova ispišite po $M$ znakova, matricu koja prikazuje koje pločice treba usisati. Znak `*` označava usisanu pločicu, a znak `.` pločicu koja nije usisana.

Ako postoji više optimalnih rješenja, ispišite bilo koje.

## Primjeri
### Ulaz 1
```
5 3
5 1 3
1 8 1
0 0 0
1 3 1
4 1 6
```
### Izlaz 1
```
29
*.*
.*.
...
.*.
*.*
```
### Objašnjenje 1
U prvom dijelu, Muamer usisava pločice $(1,1)$, $(1,3)$, $(2,2)$, $(4,2)$, $(5,1)$ i $(5,3)$ sa prljavštinama $5$, $3$, $8$, $3$, $4$ i $6$, što daje $29$.

### Ulaz 2
```
1 5
0 7 6 1 5
```
### Izlaz 2
```
12
.*..*
```
### Objašnjenje 2
Bazen ima samo jedan red. Muamer usisava pločice $(1,2)$ i $(1,5)$ sa prljavštinama $7$ i $5$. Ukupna količina uklonjene prljavštine je $7 + 5 = 12$.
