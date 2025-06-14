# Penjač

Iako ste mislili da samo programira, vaš prijatelj Amar vam je pokazao da je također i vrsni penjač, a potrebna mu je vaša pomoć kako bi optimalno trenirao.

Penjanje je sport pozicija i poteza. Penjači koriste poteze da pređu iz jedne pozicije u drugu, čime dobiju ili izgube energiju. Kako biste pomogli svom prijatelju Amaru potrebno je da napišete program kojim ćete mu govoriti koliko mu je energije potrebno da, krenuvši od pozicije $S_i$, dođe do pozicije $T_i$.

Postoji $N$ pozicija u kojima se Amar može nalaziti, te $M$ poteza koje može napraviti. Pozicije su numerisane od $0$ do $N-1$, a potezi su opisani sa tri cijela broja: $A_i$, $B_i$ i $E_i$, što označava da Amar može napraviti potez od pozicije $A_i$ do pozicije $B_i$, čime će utrošiti $E_i$ jedinica energije. Ako je $E_i$ negativno to znači da će Amar vratiti nazad energiju radeći potez. Energija potrebna za niz poteza je jednaka zbiru utrošaka energije svih poteza u tom nizu. 

Kada Amar prvi put započne penjanje u poziciji $X_i$ on će otključati novi potez od $X_i$ do $Y_i$, čime gubi $Z_i$ energije. Amar će moći koristiti ovaj potez u trenutnom i svakom budućem pokušaju.

Otključavanje poteza je opisano sa nizom od $N$ parova cijelih brojeva $Y_j$ i $Z_j$, gdje se prvi par odnosi na početni položaj $0$, drugi na početni položaj $1$ i tako dalje, do $N$-tog para koji se odnosi na početni položaj $N-1$. 

Nakon toga Amar će vam reći $Q$, broj pokušaja koje će napraviti, zajedno sa $Q$ početnih pozicija $S_i$ i ciljnih pozicija $T_i$, a potrebno je ispisati energiju potrebnu da to ostvari. Kako ne bi komplikovao svoj trening Amar neće imati sa puno različitih početnih pozicija (pogledati ograničenja i podzadatke za više detalja). 

Iako postoje potezi kojima će Amar dobiti energiju zagarantovano je da ne postoji niz poteza kojim Amar može napraviti krug, a da nakon njega ima više energije nego na početku kruga. Moguće je da će Amar moći uraditi isti potez na više načina, gdje jedan zahtjeva manje energije od drugog. 

## Ulazni podaci

Prvi red ulaza sadrži $N$, $M$ i $Q$, broj pozicija, poteza, i pokušaja koje će Amar napraviti redom.

Idućih $M$ redova sadrži po opis poteza sa 3 broja $A_i$, $B_i$ i $E_i$, odnosno pozicija od koje potez kreće, pozicija na kojoj završava i energija potrebna za njega.

Idućih $N$ redova sadrži po 2 broja $Y_i$ i $Z_i$, što označava da prvi put kada Amar počne penjati sa pozicije $i$ on će otključati potez od $i$ do $Y_i$ za koji je potrebno $Z_i$ jedinica energije.

Idućih $Q$ redova sadrži po 2 broja $S_i$ i $T_i$ koji predstavljaju početni i ciljni položaj u njegovom pokušaju.

### Ograničenja
$2 \leq N \leq 500$

$1 \leq M \leq 3000$

$1 \leq Q \leq 10000$

$-1000 \leq E_i, Z_i \leq 1000$

Amar će krenuti iz najviše $10$ različitih početnih pozicija.

## Podzadaci

### Podzadatak 1 (9 bodova)
$Q \leq 10$

$E_i=1$, $Z_i=1$ (Za svaki potez je potrebna tačno 1 jedinica energije).

### Podzadatak 2 (11 bodova)
$N \leq 100$

$M \leq 500$

$Q = 1$

### Podzadatak 3 (25 bodova)
Amar će uvijek krenuti iz iste početne pozicije.

### Podzadatak 4 (16 bodova)
$0 \leq E_i, Z_i \leq 1000$

### Podzadatak 5 (39 bodova)
Bez dodatnih ograničenja.

## Izlazni podaci

Za svaki Amarov pokušaj potrebno je ispisati koliko će Amar minimalno energije Amar ukupno potrošiti kako bi došao od početne do ciljne pozicije, u odvojenom redu.

Ako nije moguće doći od početne do ciljne pozicije sa dostupnim potezima potrebno je ispisati `NEMOGUCE`.

## Primjeri
### Ulaz 1
```
6 3 5
0 2 1
1 2 1
2 5 1
1 1
3 1
3 1
4 1
5 1
5 1
0 1
0 3
1 2
0 3
2 4
```
### Izlaz 1
```
1
NEMOGUCE
1
2
NEMOGUCE
```
### Objašnjenje 1
U prvom pokušaju Amar ide iz pozicije 0 u poziciju 1. Potez koji mu omogućava to otključava prilikom tog pokušaja, te može doći od 0 do 1 korištenjem 1 jedinice energije.

U drugom pokušaju Amar želi preći iz pozicije 0 u poziciju 3, no to nije moguće. Jedini dostupni potezi u su: iz 0 u 2, iz 1 u 2, iz 2 u 5, iz 0 u 1 (otključan prilikom prvog pokušaja).

U trećem pokušaju Amar ide iz 1 u 2. Time otključava potez iz 1 u 3. Amar može iskoristiti direktan potez iz 1 u 2, te će iskoristiti 1 jedinicu energije.

U četvrtom pokušaju Amar opet želi preći iz pozicije 0 u 3, ali to ovaj put može zato što je u međuvremenu otključao potez iz 1 u 3. Amar može preći iz 0 u 1, pa iz 1 u 3, za utrošak od 2 jedinice energije. 

U petom pokušaju Amar želi preći iz 2 u 4. Ovim otključava potez od 2 do 3 (energija 1), ali ne postoji niz poteza koji bi mu omogućio da dođe do ciljne pozicije.

Ovaj primjer odgovara podzadacima 1 i 5.

### Ulaz 2
```
5 4 5
0 2 10
1 3 2
2 3 -11
3 4 4
1 1
3 -20
2 0
3 1
0 2
0 0
0 1
0 2
0 3
0 4
```
### Izlaz 2
```
0
1
10
-1
4
```
### Objašnjenje 2
U prvom pokušaju Amar želi preći iz pozicije u 0 u poziciju 0. Kako je već u poziciji 0 tako mu treba 0 energije za ovo (i otključava potez iz 0 u 1 za 1 jedinicu energije).

U drugom pokušaju Amar želi preći iz pozicije u 0 u poziciju 1. To može uraditi koristeći potez koji je otključao prilikom prvog pokušaja i potrebna mu je 1 jedinica energije za to.

U trećem pokušaju Amar želi preći iz pozicije u 0 u poziciju 2. Dostupan mu je direktan potez i potrebno mu je 10 jedinica energije za to.

U četvrtom pokušaju Amar želi preći iz pozicije u 0 u poziciju 3. To može uraditi preko pozicija 1 ili 2. Koristeći poziciju 2 imat će manji utrošak energije, zato što prvim potezom gubi 10 jedinica energije, ali drugim dobije nazad 11 jedinica energije (gubi -11). Dakle ukupni utrošak energije je -1.

U petom pokušaju Amar želi preći iz pozicije u 0 u poziciju 4. Preko pozicija 2 i 3, Amar ovo može uraditi sa utroškom od 4 jedinica energije.


Ovaj primjer odgovara podzadacima 3, 4 i 5.
