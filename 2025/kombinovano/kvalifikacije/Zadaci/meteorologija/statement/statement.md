# Meteorologija

Meteorolozi konstantno izučavaju ponašanje i promjenu vjetra na različitim visinama. Kako bi ovo uradili koriste balone koji će doći do određene visine i spustiti se na tlo.

Vaš lokalni meteorolog je pustio $N$ ovakvih balona i zabilježio koliko daleko istočno su odletjeli. Udaljenost sjeverno i južno ga ne zanima, a odlazak zapadno je označio sa negativnim brojevima. Na primjer, ako je balon odletio $3$ kilometra istočno to je označio brojem $3$, a ako je balon odletio $2$ kilometra zapadno to je označio brojem $-2$.

Meteorolog će vama dati svojih $N$ mjerenja udaljenosti balona, a vaš zadatak je pomoći mu tako što napišete program koji će poredati po tome koliko daleko su baloni odletjeli od njihove početne lokacije. Potrebno ih je poredati od najbližeg do najdaljeg.

Po pitanju udaljenosti gledamo odlazak na zapad i na istok, dakle $-4$ treba staviti poslije $2$ u nizu, a $2$ treba staviti poslije $-1$ u nizu. Ako su dva balona jednako udaljena onda je potrebno zapadni staviti prije istočnog u nizu.

## Ulazni podaci

Prvi red ulaza sadrži $N$, broj balona koje je meteorolog pustio.\
Drugi red ulaza sadrži $N$ brojeva $M_i$ razdvojenih razmakom, mjerenja meteorologa.

### Ograničenja
$1 \leq N \leq 10^{5}$ (__napomena__: $10^5$ je $1$, pa pet $0$ nakon toga, odnosno $100\;000$),\
$-10^9 \leq M_i \leq 10^9$

## Podzadaci

### Podzadatak 1 (9 bodova)
$N\leq4$,\
$0 \leq M_i < 10$

### Podzadatak 2 (18 bodova)
$N\leq10^3$,\
$0 \leq M_i \leq 10^5$,\
Sve udaljenosti od početka će biti različite.

### Podzadatak 3 (25 bodova)
$N\leq10^3$

### Podzadatak 4 (28 bodova)
$-10^5 \leq M_i \leq 10^5$

### Podzadatak 5 (20 bodova)
Bez dodatnih ograničenja.

## Izlazni podaci

Potrebno je ispisati sve udaljenosti sa ulaza poredane po želji meteorologa. 

## Primjeri
### Ulaz 1
```
4
7 3 1 3
```
### Izlaz 1
```
1 3 3 7
```
### Objašnjenje 1
Baloni su poredani od najbližih do najdaljih. Ovaj primjer podzadacima 1, 3, 4 i 5.

### Ulaz 2
```
6
-2 1 2 -2 1 -1
```
### Izlaz 2
```
-1 1 1 -2 -2 2
```
### Objašnjenje 2
Ovaj primjer odgovara podzadacima 3, 4 i 5.

### Ulaz 3
```
8
-486 856 -966 -92 159 293 -56 516
```
### Izlaz 3
```
-56 -92 159 293 -486 516 856 -966
```

### Objašnjenje 3
Ovaj primjer odgovara podzadacima 2, 3 i 5.