# Hurry d.o.o.

Gospodin Hurry je vlasnik multimilijarderske firme za transport i skladištenje robe. Njegov najnoviji klijent, firma koja proizvodi mehaničke tastature, zahtijeva rješenje za organizaciju transporta njihove najnovije linije tastatura, “Worse Fox”. 

U skladištu se nalazi $n$ vrsta paketa sa tastaturama, pri čemu postoji beskonačna zaliha svakog tipa paketa (firma je vrlo ambiciozna s prodajom). Beskonačni nizovi paketa su poredani jedan do drugog, označeni sa brojevima od $1$ do $n$, tako da se u $i$-tom nizu nalaze paketi tipa $i$. 

Gospodin Hurry posjeduje viljuškare koji će napraviti tačno $k$ putovanja do skladišta i svaki put zgrabiti po jedan od $t$ uzastopnih paketa (ako je prvi paket koji je robot zgrabio $i$, onda su pokupljeni i paketi $i+1$, $i+2$, …, $i+t-1$). Uslijed podesive širine viljuške, $t$ je broj između dva data ulazna parametra $x$ i $y$  ($x \leq t \leq y$).

S obzirom da različite vrste tastatura imaju različitu popularnost, paketi tipa $i$, imaju vrijednost $A_i$, pri čemu je $A_i$  broj koji može biti pozitivan, ali i negativan. 

Kako bi “Worse Fox” ostvarile najveći mogući profit, Mr. Hurry vas je zamolio da napravite program koji će odrediti koja je maksimalna moguća vrijednost zbira svih vrijednosti paketa prikupljenih u $k$ putovanja do skladišta, pri čemu je svaki put uzeto između $x$ i $y$ uzastopnih paketa i ne postoje dva putovanja u kojem su uzeti **svi isti** paketi (kako bi se održala raznolikost tastatura na prodaju).

## Ulazni podaci

Prva linija na ulazu sadrži pozitivne cijele brojeve $n$, $k$, $x$, $y$ – broj vrsta paketa, broj putovanja do skladišta, najmanji i najveći broj paketa pokupljenih u jednom putovanju.
Narednih $n$ linija sadrže vrijednosti $A_i$ , tako da $i$-ta linija sadrži vrijednost $i$-tog tipa paketa.

### Ograničenja

$1 \leq n, k \leq 500 000\\$
$1 \leq x \leq y \leq n\\$
$-1000 \leq A_i \leq 1000$

## Podzadaci

### Podzadatak 1 (8 bodova)
$1 \leq n \leq 1000 \\$
$1 \leq k \leq 500 000 \\$ 

### Podzadatak 2 (7 bodova)
$1 \leq n \leq 500 000 \\$
$k = 1 \\$ 

### Podzadatak 3 (20 bodova)
$1 \leq n \leq 10 000 \\$
$1 \leq k \leq 10 000 \\$ 

### Podzadatak 4 (15 bodova)
$1 \leq n \leq 80 000 \\$
$1 \leq k \leq 80 000 \\$ 

### Podzadatak 5 (50 bodova)
Bez dodatnih ograničenja.


## Izlazni podaci

Output sadrži jedan broj koji predstavlja maksimalnu vrijednost zbira vrijednosti svih prikupljenih paketa.

## Primjeri
### Ulaz 1
```
4 3 2 3
3
2
-6
8
```
### Izlaz 1
```
11
```
### Objašnjenje 1
Kombinacije paketa sa dužinama između 2 i 3 sa 3 najveća zbira vrijednosti su (1,2), (2,3,4) i (3,4).

### Ulaz 2
```
5 1 1 5
10
-4
-7
-6
5
```
### Izlaz 2
```
10
```
### Objašenjenje 2
Kombinacija paketa sa dužinom između 1 i 5 sa najvećim zbirom vrijednosti je (1). 