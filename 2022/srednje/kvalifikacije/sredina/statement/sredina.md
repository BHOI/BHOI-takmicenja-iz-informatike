# Sredina
Sredina niza (ne nužno različitih) prirodnih brojeva definišemo kao srednji element u nizu koji se dobije njegovim sortiranjem. Ukoliko je niz parne dužine, tada sredinom smatramo manji od dva srednja broja nakon sortiranja.

Na primjer, sredine nizova `(1)`, `(1, 3)`, `(4, 5, 4)`, `(4, 1, 2, 3)` i `(5, 4, 1, 2, 3)` su redom `1`, `1`, `4`, `2`, `3`.

Ako je zadan niz `X` koji se sastoji od `N` prirodnih brojeva i prirodni broj `K`, odredi broj podnizova uzastopnih elemenata zadanog niza čija je sredina barem `K`.

## Ulaz
U prvom redu nalaze se dva prirodna broja `N` i `K`.
U svakom od sljedećih `N` redova nalazi se po jedan prirodni broj `Xi`, element niza `X`.

### Ograničenja
```
1 <= N <= 200 000
1 <= K <= 1 000 000
1 <= Xi <= 1 000 000
```
*U 10% test podataka N će biti najviše 100.*

*U dodatnih 20% test podataka N će biti najviše 1000*

## Izlaz
U prvi i jedini red ispišite jedan cijeli broj - broj podnizova čija je sredina barem `K`.

## Primjeri
### Ulaz 1
```
4 3
1
1
3
4
```
### Izlaz 1
```
4
```
*Svi mogući podnizovi uzastopnih elemenata zadanog niza i njihovi srednji elementi su redom, a boldirani predstavljaju rješenje:*

- [1] = 1
- [1, 1] = 1
- [1, 1, 3] = 1
- [1, 1, 3, 4] = 1
- [1] = 1
- [1, 3] = 1
- **[1, 3, 4] = 3**
- **[3] = 3**
- **[3, 4] = 3**
- **[4] = 4**

### Ulaz 2
```
6 7
8
7
3
2
2
7
```
### Izlaz 2
```
5
```
### Ulaz 3
```
10 5
1
10
2
9
3
8
4
7
5
6
```
### Izlaz 3
```
29
```