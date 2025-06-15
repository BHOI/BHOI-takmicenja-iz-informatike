# Kolegice

Hana sa kolegicama putuje u EGOIstan gdje koriste lokalnu valutu Ego. Kako ne bi morale rješavati pojedinačne troškove nakon svakog zajedničkog troška dogovorile su se da će zapisivati svaki put jedna pokrije tuđi trošak.

Sada, došao je kraj putovanja i vrijeme je da se riješe dugovi. Vi ćete dobiti listu koju su zapisivale u toku putovanja, a potrebno je za svakoga ispisati finalno stanje. Finalno stanje za jednu kolegicu je zbir svih njenih dugova prema ostalima minus zbir svih dugova drugih kolegica prema njoj (dakle pozitivno stanje znači da duguje kolegicama, negativno da se njoj duguje).

Finalno stanje je potrebno ispisati u obliku liste poredane od kolegice sa najvećim finalnim stanjem do kolegice sa najmanjim. Ako dvije kolegice imaju isto finalno stanje potrebno je prvo ispisati onu sa manjim brojem.

## Ulazni podaci
Prvi red ulaza sadrži cijele brojeve $N$ i $M$, broj kolegica (uključujući Hanu) i broj troškova zabilježenih u toku putovanja. Kolegice su označene brojevima od $0$ do $N-1$.

Idućih $M$ redova sadrži po 3 cijela broja $A_i$, $B_i$ i $E_i$ koji označava da se kolegica $A_i$ zadužila kolegici $B_i$ za $E_i$ Egoa.

### Ograničenja
$1 \leq N, M \leq 1000$

$0 \leq A_i, B_i, < N$

$1 \leq E_i \leq 10^{15}$


## Podzadaci

### Podzadatak 1 (13 bodova)
$M = 1$

$1 \leq E_i \leq 100$

### Podzadatak 2 (16 bodova)
$N = 2$

$1 \leq E_i \leq 100$

### Podzadatak 3 (17 bodova)
Sve kolegice su posuđivale samo od Hane (broj 0), odnosno $B_i = 0$.

$1 \leq E_i \leq 100$

### Podzadatak 4 (45 bodova)
$1 \leq E_i \leq 100$

### Podzadatak 5 (9 bodova)
Bez dodatnih ograničenja.

## Izlazni podaci

Potrebno je ispisati $N$ redova sa brojevima $K_i$ i $S_i$, odvojenih razmacima, gdje $K_i$ predstavlja broj kolegice, a $S_i$ konačno stanje. Potrebno je ispisati redove redom od kolegice sa najvećim konačnim stanjem, do kolegice sa najmanjim. Ukoliko dvije kolegice imaju isto stanje potrebno je prvo ispisati kolegicu sa manjim brojem.

## Primjeri
### Ulaz 1
```
2 1
1 0 10
```
### Izlaz 1
```
1 10
0 -10
```
### Objašnjenje 1
Kolegica sa brojem 1 se zadužila Hani (broj 0) za 10 Egoa. Kolegicino konačno stanje je 10, dok je Hanino -10. Ovaj primjer odgovara svakom podzadatku.

### Ulaz 2
```
5 6
0 2 4
2 4 3
4 0 3
1 4 1
3 0 1
3 1 3
```
### Izlaz 2
```
3 4
0 0
2 -1
4 -1
1 -2
```
### Objašnjenje 2
Kako je Hana (broj 0) jednako mnogo dužna koliko su kolegice njoj dužne njeno stanje je 0.

### Ulaz 3
```
3 3
0 1 5
2 1 4
1 2 1
```
### Izlaz 3
```
0 5
2 3
1 -8
```