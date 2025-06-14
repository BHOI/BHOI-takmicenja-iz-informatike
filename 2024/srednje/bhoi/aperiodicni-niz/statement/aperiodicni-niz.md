# Aperiodični niz

Orle je Azuru zadao zagonetku koju je Azur odmah riješio. Iznenađen, Orle vas je pitao da napišete program kojim će moći provjeriti da li su Azurovi odgovori tačni ili ih samo izmišlja.

Orle je započeo zagonetku tako što je napisao sljedeći niz: $1, 1, 2, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 4, 5, 1, 2, \dots$

Brzo primjećujete da je Orle zadao niz tako što je napisao prvi prirodni broj, zatim prva dva prirodna broja, zatim prva tri, zatim prva četiri i tako dalje. Orle postavlja jednostavno pitanje - koji je $N$-ti broj u ovom nizu?

Vaš zadatak je napisati program koji odgovara na ovo pitanje.

***Napomena**: obratite pažnju na veličinu brojeva na ulazu, potencijalno će biti potrebno koristiti $long\;long$ umjesto $int$.*

## Ulazni podaci

Prvi i jedini red ulaza sadrži jedan prirodan broj, $N$, iz opisa zadatka.

### Ograničenja

$1 \leq N \leq 10^{14} \\$ 

## Podzadaci

### Podzadatak 1 (11 bodova)
$1 \leq N \leq 20 \\$ 

### Podzadatak 2 (30 bodova)
$1 \leq N \leq 10^9 \\$ 
Broj nakon $N$-tog broja je $1$.

### Podzadatak 3 (25 bodova)
$1 \leq N \leq 10^5 \\$ 

### Podzadatak 4 (15 bodova)
$1 \leq N \leq 10^9 \\$ 

### Podzadatak 5 (19 bodova)
Bez dodatnih ograničenja.

## Izlazni podaci

Potrebno je ispisati jedan broj, $N$-ti član niza.

## Primjeri
### Ulaz 1
```
3
```
### Izlaz 1
```
2
```
### Objašnjenje 1
1, 1, **2**, 1, 2, 3, 1, 2, 3, 4, ...

### Ulaz 2
```
7
```
### Izlaz 2
```
1
```
### Objašenjenje 2
1, 1, 2, 1, 2, 3, **1**, 2, 3, 4, ...

### Ulaz 3
```
55
```
### Izlaz 3
```
10
```

### Ulaz 4
```
77
```
### Izlaz 4
```
11
```



