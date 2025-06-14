# Kolekcija filmova

Katarina voli gledati filmove i ima kolekciju od `N` filmova koje je odgledala i ocjenila. Svakom filmu je dodjelila ocjenu broj `X` od 0 do 10. Katarina je vrlo precizna i ocjenjuje filmove i na do 3 decimale (npr. `8.125`). 

Vaš zadatak je napisati program koji će odgovoriti na `M` upita sa brojevima `A` i `B`. Na svaki upit je potrebno odgovoriti sa jednim brojem - brojem filmova u kolekciji za koje vrijedi `A < X < B`.


## Ulazni podaci

Prvi red ulaza sadrži jedan broj, `N`, broj filmova u Katarininoj kolekciji.
Narednom redu se nalazi `N` brojeva `X` - ocjena filmova.
Idući red ulaza sadrži broj `M`, broj upita.
Narednih `M` redova sadrže po 2 broja - `A` i `B`.

### Ograničenja
```
1 <= N, M <= 10^5
0 <= A, X, B <= 10
```

## Podzadaci

### Podzadatak 1 (6 bodova)
`N = 1`
Sve ocjene će biti cjelobrojne.

### Podzadatak 3 (22 boda)
`N = 3, M = 3`
Sve ocjene će biti cjelobrojne.

### Podzadatak 3 (33 boda)
`M = 1`
Sve ocjene će biti cjelobrojne.

### Podzadatak 4 (39 bodova)
Bez dodatnih ograničenja.

## Izlazni podaci

Za svaki upit potrebno je ispisati po jedan broj - broj filmova u Katarininoj kolekciji koji ispunjavaju zadane uslove.

## Primjeri
### Ulaz 1
```
3
3 8 5
3
3 10
4 5.5
2 9
```
### Izlaz 1
```
2
1
3
```
### Objašnjenje 1
Uslov 1. upita ispunjavaju 2. i 3. film. 1. film ne ispunjava uslov da je ocjena koju je Katarina dala (strogo) veća od 3.
Samo 3. film ispunjava uslov 2. upita, zato što samo on ima ocjenu između 4 i 5.5.
Uslov 3 upita ispunjavaju sva 3 filma, zato što sva 3 imaju ocjenu između 2 i 9.

### Ulaz 2
```
4
3.5
2.2
8.5
1.111
3
1.8 4.05
1.2 8.9
1.1 8.5
```
### Izlaz 2
```
2
3
3
```
### Objašenjenje 2
Uslov 1. upita ispunjavaju 1. i 2. film, uslov 2. upita ispunjavaju 1., 2. i 3. film, a uslov 3. upita ispunjavaju 1., 2. i 4. film.

## Primjer 3
### Ulaz 3
```
3
9 1 5
3
7 10
0 5
4 0
```
### Izlaz 3
```
1
1
0
```
### Objašenjenje 3
Uslove 1. upita ispunjava samo 1. film, uslov 2. upita ispunjava samo 2. film, a nijedan film ne ispunjava uslov 3. upita.