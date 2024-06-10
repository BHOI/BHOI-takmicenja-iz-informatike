# Čudnost permutacije
Permutacija dužine `N` je niz brojeva takav da se sastoji od `N` brojeva i svi brojevi od `1` do `N`, uključujići `1` i `N` se pojave tačno jednom. 

Na primjer, nizovi `[3, 1, 2]` ,`[1]`, `[1, 4, 2, 3] ` jesu permutacije, međutim nizovi `[1, 3, 5]` i `[2, 2, 1]` nisu permutacije, jer prvi niz ne sadrži broj `2` i drugi niz ne sadrži broj `3` i broj `2` se ponavlja dva puta.

Čudnost permutacije je zbir proizvoda svaka dva susjedna elementa permutacije.  Čudnost permutacije `[1, 3, 2]` je `1*3 + 3*2 = 3+6 = 9`. Čudnost permutacije `[4, 3, 2, 1]` je `4*3 + 3*2 + 2*1 = 12+6+2 = 20`.

Vaš zadatak je da ispišete ostatak pri djeljenju sume čudnosti svake permutacije dužine `N` sa brojem `1 000 000 007`. Dvije permutacije su različite ako su vrijednosti na nekoj poziciji različite u permutacijama.

Vaš program će u jednom pokretanju biti upitan više upita, tačnije `T` upita. Za svaki upit trebate dati odgovor u odvojenom redu.

## Ulaz
Na prvoj liniji unosa se nalazi broj testnih slučajeva `T`.

U slijedećih `T` linija unosa nalazi se po jedan broj `N`.

### Ograničenja
```
1 <= T <= 100 000
1 <= N <= 1 000 000
```
- Podzadatak 1 (5 bodova) - `2 <= N <= 9` i `1 <= T <= 8`
- Podzadatak 2 (20 bodova) - `T=1` i `2 <= N <= 2 000`
- Podzadatak 3 (30 bodova) - `T=1` i `2 <= N <= 1 000 000`
- Podzadatak 4 (45 bodova) - Bez posebnih ograničenja.

## Izlaz
Za svaki testni slučaj potrebno je ispisati jedan broj, ostatak pri djeljenju sume čudnosti svake permutacije dužine `N` sa brojem `1 000 000 007`.

## Primjeri
### Ulaz
```
4
2
3
4
11
```
### Izlaz
```
4
44
420
970879909
```
### Objašnjenje
U slučaju kada je `N = 2`, postoje `2` moguće permutacije i to su `[1, 2]` i `[2, 1]`. Obje permutacije imaju čudnost `1*2 = 2`, tako da je suma čudnosti svih permutacija dužine `2` jednaka `2+2=4`. Na kraju nam ostaje da uradimo modulo sa brojem `1 000 000 007`, a to je `4 % 1000000007 = 4`.

U drugom testnom slučaju, postoji `6` mogućih permutacija:

- Za permutaciju `[1, 2, 3]` čudnost je `1*2 + 2*3 = 2 + 6 = 8`
- Za permutaciju `[1, 3, 2]` čudnost je `1*3 + 3*2 = 3 + 6 = 9`
- Za permutaciju `[2, 1 ,3]` čudnost je `2*1 + 1*3 = 2 + 3 = 5`
- Za permutaciju `[2, 3, 1]` čudnost je `2*3 + 3*1 = 6 + 3 = 9`
- Za permutaciju `[3, 1, 2]` čudnost je `3*1 + 1*2 = 3 + 2 = 5`
- Za permutaciju `[3, 2, 1]` čudnost je `3*2 + 2*1 = 6 + 2 = 8`

Suma čudnosti = `8+9+5+9+5+8 = 44`. Na kraju nam ostaje da uradimo modulo sa brojem `1 000 000 007`, a to je `44 % 1000000007 = 44`.
