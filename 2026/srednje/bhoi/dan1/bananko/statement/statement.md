# Bananko

U srcu Bosne i Hercegovine planira se izgradnja jedinstvenoga naučno-istraživačkog kampusa posvećenog proučavanju i optimizaciji ukusa čokoladnih bananica. Kampus će sadržavati $N$ instituta, a svaki institut zahtijeva po jednu zgradu iste veličine.

Arhitekte su odlučile da zgrade moraju biti grupisane u kvadratne blokove. Kvadratni blok koji je $X$ zgrada širok i $X$ zgrada visok sadrži tačno $X^2$ zgrada. Na primjer, blok koji je 3 zgrade širok sadrži $3^2 = 9$ zgrada, a blok koji je 5 zgrada širok sadrži $5^2 = 25$ zgrada.

Vaš zadatak je odrediti minimalan broj kvadratnih blokova koji zajedno sadrže tačno $N$ zgrada.

Na primjer, za $N = 41$ moguće je koristiti blokove sa $36 + 4 + 1 = 41$ zgradama (3 bloka), ali i blokove sa $25 + 16 = 41$ zgradama (2 bloka). Optimalno rješenje koristi 2 bloka.

## Ulazni podaci

U jedinom redu nalazi se cijeli broj $N$.

### Ograničenja

- $1 \leq N \leq 100\;000$

## Podzadaci

### Podzadatak 1 (15 bodova)

- $N < 10$

### Podzadatak 2 (18 bodova)

- $N < 100$

### Podzadatak 3 (20 bodova)

- $N < 10\;000$

### Podzadatak 4 (12 bodova)

- Svi prosti faktori broja $N$ su oblika $4k + 1$, gdje je $k$ nenegativan cijeli broj (na primjer, $5, 13, 17, 29, \ldots$).

### Podzadatak 5 (35 bodova)

- Nema dodatnih ograničenja.

## Izlazni podaci

Ispisati jedan cijeli broj: minimalan broj kvadratnih blokova potrebnih da kampus sadrži tačno $N$ zgrada.

## Primjeri

### Ulaz 1
```
1
```
### Izlaz 1
```
1
```
### Objašnjenje 1
Jedan blok veličine $1 \times 1$ sadrži tačno 1 zgradu.

### Ulaz 2
```
12
```
### Izlaz 2
```
3
```
### Objašnjenje 2
$12 = 4 + 4 + 4 = 2^2 + 2^2 + 2^2$, što zahtijeva 3 kvadratna bloka. Nije moguće napraviti kampus s 12 zgrada koristeći samo 1 ili 2 bloka.

### Ulaz 3
```
41
```
### Izlaz 3
```
2
```
### Objašnjenje 3
$41 = 25 + 16 = 5^2 + 4^2$, što zahtijeva 2 kvadratna bloka.
