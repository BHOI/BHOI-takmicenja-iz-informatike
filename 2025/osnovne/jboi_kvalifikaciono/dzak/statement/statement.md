# Džak

Tarik ima veliki broj džakova (vreća) i punit će ih omiljenim voćem - trešnjama sa Kipra. Tariku dolazi više dostava trešanja i stavljat će ih u vreće, znajući da možda neće napuniti sve iskorištene vreće, već će jedna vreća ostati djelomično napunjena.

Tariku su posebno zanimljive posljednje vreće koje možda i neće biti u potpunosti napunjene i postavio vam je zadatak u vezi s njima. Tarik će puniti vreće redom, dakle stavljat će trešnje u prvu vreću dok je ne napuni do kraja. Nakon toga počinje puniti drugu vreću, pa eventualno treću i tako dalje.

Tarik očekuje $N$ dostava trešanja koje sadrže $T_i$ trešanja. Potrebno je napisati program koji može odgovoriti na $Q$ pitanja: ako je data veličina vreće $V_j$ i broj trešanja $P_j$ ($P_j \leq V_j$) potrebno je odrediti **za koliko dostava trešanja će posljednja vreća završiti sa tačno $P_j$ trešanja?**

Kao dodatno olakšannje znate da **veličine vreća će uvijek biti stepen broja 2**.

Na primjer, ako Tarik očekuje dostave trešanja sa 9 i 21 trešanja i ako se trešnje stavljaju u vreće veličine 8 onda posljednja vreća prve dostave će sadržavati 1 trešnju (prva vreća će biti puna i imati 8 trešanja, a druga vreća će imati 1 trešnju), dok će posljednja vreća druge dostave imati 5 trešanja (prva vreća puna i ima 8 trešanja, druga vreća puna i ima 8 trešanja, treća vreća ima 5 trešanja). Ipak, ako su veličine vreća 4 onda će posljednje vreće obje dostave imati po 1 trešnju.

Ako za pitanje $j$ vrijedi $V_j=4$ i $P_j=1$ onda je potrebno da program ispiše 2 (dakle postoje 2 dostave za koje će posljednja vreća sadržavati 1 trešnju), ako vrijedi $V_j=8$ i $P_j=1$ onda je potrebno da program ispiše 1 (samo će za prvu dostavu vrijediti da posljednja vreća sadrži 1 trešnju), dok ako vrijedi $V_j=8$ i $P_j=4$ onda je potrebno da program ispiše 0 (ni za jednu dostavu ne vrijedi da, ako se koriste vreće veličine 8, posljednja vreća će imati tačno 4 trešnje).

_Napomena:_ Kako ulazni podaci mogu biti vrlo veliki preporučujemo da koristite `ios_base::sync_with_stdio(0);` i `cin.tie(NULL);` na početku `main()` funkcije programa.

## Ulazni podaci
Prvi red ulaza se sastoji od cijelih brojeva $N$ i $Q$, broja dostava i broja pitanja.

Idući red sadrži $N$ cijelih brojeva odvojenih razmakom $T_i$, broja trešanja po dostavi.

Idućih $Q$ redova se sastoji od cijelih brojeva $V_j$, $P_j$ koji opisuju pitanje. Za svako pitanje je potrebno u odvojenom ispisati broj dostava za koje posljednja vreća sadrži tačno $P_j$ trešanja, pod uslovom da se koriste vreće veličine $V_j$.

### Ograničenja
$1 \leq N \leq 100\;000$

$1 \leq Q \leq 100\;000$

$1 \leq T_i \leq 100\;000\;000$

$1 \leq P_j \leq V_j \leq 100\;000\;000$

$V_j$ je stepen broja 2, odnosno pripada skupu $\{1, 2, 4, 8, 16, ...\}$

## Podzadaci

### Podzadatak 1 (6 bodova)
$N = Q = 1$;

$P_0$ ≠ $V_0$.

### Podzadatak 2 (8 bodova)
$N = 1$.

### Podzadatak 3 (13 bodova)
$N \leq 100$;

$Q \leq 100$.

### Podzadatak 4 (22 boda)
$V_j = 16$ za svako $j$ (sve vreće su veličine 16).

### Podzadatak 5 (51 bodova)
Bez dodatnih ograničenja.

## Izlazni podaci
Na jedinoj liniji izlaza je potrebno ispisati odgovore na sva pitanja redom, razdvojene razmacima.

## Primjeri
### Ulaz 1
```
2 3
9 21
4 1
8 1
8 4
```
### Izlaz 1
```
2 1 0
```
### Objašnjenje 1
Primjer je iz teksta zadatka.

### Ulaz 2
```
4 5
10 16 26 27
8 3
4 3
16 10
8 8
32 30
```
### Izlaz 2
```
1 1 2 1 0
```
### Objašnjenje 2
Ako su vreće veličine 8 onda će samo u četvrtoj dostavi posljednja vreća (od njih 4) imati 3 trešnje.

Ako su vreće veličine 4 onda će samo u četvrtoj dostavi posljednja vreća (od njih 7) imati 3 trešnje.

Ako su vreće veličine 16 onda će i prva i treća dostava imati posljednje vreće sa po 10 trešanja.

Ako su vreće veličine 8 onda će samo u drugoj dostavi posljednja vreća (od njih 2) imati 8 trešanja.

Ako su vreće veličine 32 onda ni u jednoj dostavi neće posljednja vreća imati 30 trešanja.

### Ulaz 3
```
5 4
79053667 66832133 4972914 28398 290542
131072 28398
2 1
8388608 4972914
1 1
```
### Izlaz 3
```
2 2 1 5 
```
### Objašnjenje 3
Posljednji odgovor je 5 zato što u svakoj dostavi posljednja vreća će imati tačno 1 trešnju. 
