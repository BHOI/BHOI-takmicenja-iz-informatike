# Susjedi

Vladan pravi video igru i vi mu pomažete pri programiranju te igre. Trenutno, vaš zadatak je od od niza brojeva odrediti koja dva susjedna broja odabrati kako bi njihov zbir bio što veći.

Nakon što se upiše broj `N` i niz od `N` cijelih brojeva potrebno je odrediti i ispisati koja dva susjedna broja treba sabrati kako bi se dobio što veći zbir. Pored njihovog mjesta u nizu, potrebno je ispisati i zbir.

## Ulazni podaci

Prvi red ulaza sadrži jedan broj, `N`, broj članova niza.

Drugi red ulaza sadrži `N` cijelih brojeva `X`, razdvojeni razmakom, koji označavaju brojeve niza, redom.

### Ograničenja
```
1 < N < 10**5
-10**18 < X < 10**18
```

## Podzadaci

### Podzadatak 1 (20 bodova)
`N = 2`
`-100 < X < 100`

### Podzadatak 2 (31 bodova)
`-100 < X < 100`
Postoji samo jedan par susjednih brojeva sa najvećim zbirom.

### Podzadatak 3 (32 bodova)
`-10**9 < X < 10**9`

### Podzadatak 4 (17 bodova)
Bez dodatnih ograničenja.

## Izlazni podaci

Potrebno je ispisati tri broja u jednom redu, razdvojeni razmacima. Za pronađeni par susjednih brojeva potrebno je ispisati redni broj ranijeg, redni broj kasnijeg, te zbir ta dva broja, redom.

*Napomena: ako postoji više parova brojeva sa istim najvećim zbirom potrebno je odabrati najkasniji.*

## Primjeri
### Ulaz 1
```
5
10 20 30 40 20
```
### Izlaz 1
```
3 4 70
```
### Objašnjenje 1
Dva susjedna broja koja daju najveći zbir su 3. i 4. broj, a njihov zbir je 70.

### Ulaz 2
```
2
4 15
```
### Izlaz 2
```
1 2 19
```
### Objašenjenje 2
Samo je jedan par susjendih brojeva, to su 1. broj i 2. broj, sa zbirom 19.

## Primjer 3
### Ulaz 3
```
7
4 -1 2 0 1 1 2
```
### Izlaz 3
```
6 7 3
```
### Objašenjenje 3
Prva dva i posljednja dva broja oba imaju najveći zbir, 3, ali pošto je u takvim slučajevima potrebno ispisati kasniji par, tako su odabrani 6. i 7. brojevi.

## Primjer 4
### Ulaz 4
```
5
-10 -20 -15 -60 0
```
### Izlaz 4
```
1 2 -30
```
### Objašenjenje 4
Zbir svaka dva susjedna broja je negativan. Najveći je zbir prva dva, sa zbirom -30.