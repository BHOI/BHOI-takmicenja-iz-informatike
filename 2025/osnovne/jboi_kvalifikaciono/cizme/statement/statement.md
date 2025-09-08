# Čizme

Magične čizme Mačka (u čizmama) se nalaze u nizu u Mačkovom ormaru i naređeno im je da se poredaju. Sve su mu čizme iste, osim što su neke lijeve i neke desne. Mačku je najdraže ako na lijevom kraju ormara su sve lijeve čizme, a na desnom kraju sve desne čizme, sa praznim mjestima samo između svih lijevih i svih desnih čizama.

Kako su čizme lijene one žele u najmanjem mogućem broju poteza da se poredaju u željeno stanje. Vaš zadatak je odrediti koji je to najmanji broj poteza, te ispisati kako se čizme trebaju pomjerati.

Čizme se mogu samo pomjerati jedna po jedna, i to na jedan od sljedećih načina:

- Lijeva čizma se može pomjeriti lijevo na sljedeće načine:
  - Može se pomjeriti jedno mjesto lijevo, ako je to mjesto prazno;
  - Može se pomjeriti dva mjesta lijevo, ako je to mjesto prazno, a mjesto između njih je zauzeto (može preskočiti čizmu direktno lijevo od sebe).


- Desna čizma se može pomjeriti desno na sljedeće načine:
  - Može se pomjeriti jedno mjesto desno, ako je to mjesto prazno;
  - Može se pomjeriti dva mjesta desno, ako je to mjesto prazno, a mjesto između njih je zauzeto (može preskočiti čizmu direktno desno od sebe).

Čizma ne može izaći van ormara (van granica niza), a primjetite da:

- Ako se čizma može pomjeriti onda se može pomjeriti na samo jedan način
- Desne čizme se ne mogu pomjerati lijevo
- Lijeve čizme se ne mogu pomjerati desno

Potrebno je da u konačnici mjesta budu popunjena (s lijeva na desno) svim lijevim čizmama, pa prazninom, pa svim desnim čizmama.

Potrebno je ispisati minimalan broj poteza za koji se ovo može postići, te opisati te poteze tako što ispisujući niz brojeva koji sadržavaju polja sa kojih će se čizme pomjeriti.

## Ulazni podaci
Prvi red sadrži cijeli broj $N$, veličinu niza.

Drugi red sadrži $N$ cijelih brojeva $c_i$ koji opisuju pozicije u ormaru. Ako $c_i=0$, to znači da na poziciji $i$ se ne nalazi nijedna čizma. Ako $c_i=1$, to znači da se na poziciji $i$ nalazi lijeva čizma. Ako $c_i=2$, to znači da se na poziciji $i$ nalazi desna čizma.

### Ograničenja
$3 \leq N \leq 13$

U ormaru se nalazi barem jedna lijeva čizma, jedna desna čizma, te jedno prazno mjesto.

Zagarantovano je da je opisanim potezima moguće poredati čizme na željeni način u svim primjerima nad kojim će se testirati.

## Bodovanje

Ovaj zadatak ne koristi podzadatke za bodovanje, već pojedinačne testne primjere koji nose po jednak broj bodova.

Ukoliko vaš program ispisuje validan niz poteza za redanje čizama, ali on nije najkraći, onda dobijate 20% bodova za taj testni primjer.

Ukoliko vaš program ispisuje ispravno rješenje (najkraći niz poteza kojim se čizme poredaju) onda dobijate 100% bodova za taj testni primjer. 

Ukoliko postoji više načina da se poredaju čizme u minimalnom broju poteza dovoljno je ispisati bilo koji od njih za maksimalan broj bodova.

## Izlazni podaci
U prvom redu potrebno je ispisati jedan cijeli broj, dužinu vašeg niza koji opisuje poteze.

U drugom redu potrebno je ispisati niz cijelih brojeva, razdvojenih razmacima, koji sadrži mjesta sa kojih će čizma se pomjeriti, redom. Mjesta su s lijeva na desno označena cijelim brojevima od $1$ do $N$.

## Primjeri
### Ulaz 1
```
3
2 1 0
```
### Izlaz 1
```
2
1 2
```
### Objašnjenje 1
Ispod su prikazana sva stanja, počevši od početne iz primjera. Lijeve čizme su označene sa L, a desne sa D:

| 1 | 2 | 3 |
|---|---|---|
| D | L |   |
|   | L | D |
| L |   | D |

### Ulaz 2
```
5
2 1 0 0 1
```
### Izlaz 2
```
5
5 1 3 4 3
```
### Objašnjenje 2
Ispod su prikazana sva stanja, počevši od početne iz primjera. Lijeve čizme su označene sa L, a desne sa D:

| 1 | 2 | 3 | 4 | 5 |
|---|---|---|---|---|
| D | L |   |   | L |
| D | L |   | L |   |
|   | L | D | L |   |
|   | L |   | L | D |
|   | L | L |   | D |
| L | L |   |   | D |

### Ulaz 3
```
11
0 2 1 2 0 2 1 0 1 1 1
```
### Izlaz 3
```
24
7 3 5 9 11 9 7 6 4 2 7 6 4 9 7 6 8 6 4 10 8 6 7 8 
```
