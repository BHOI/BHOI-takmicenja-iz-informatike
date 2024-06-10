# Parovi

Veliki broj ljudi se dosađuje čekajući u redu ispred prodavnice kako bi mogli kupiti
kompjuter sa najnovijim bosanskohercegovačkim operativnim sistemom, bOSna 2022.
Svaka osoba mašta o tome koliko će stvari moći raditi na tom kompjuteru. Budući da
novi operativni sistem predstavlja svjetski vrhunac tehnologije, brojevi stvari koje te
osobe imaju u glavi može imati i do 18 cifara u decimalnom sistemu.

Par prirodnih brojeva je "dobar" ako ta dva broja imaju bar jednu zajedničku cifru
(ne nužno na istom mjestu) u decimalnom sistemu. Vaš zadatak je napisati program
koji može odrediti koliko je parova ljudi u gore spomenutom redu zamislilo brojeve koji
skupa čine dobar par. Redoslijed ljudi u paru nije bitan.

## Ulaz
Prva linija na ulazu sadrži pozitivan cijeli broj `N`, broj ljudi u redu.
Slijedi `N` linija u kojima su redom dati zamišljeni brojevi ljudi u redu, `a[i]`, veličinom između
1 i 10<sup>18</sup>.

### Ograničenja
```
1 <= N <= 1 000 000
1 <= a[i] <= 1 000 000 000 000 000 000
```

* Podzadatak 1 (20 bodova): `N <= 1000` i `a[i] < 100 000`.
* Podzadatak 2 (20 bodova): `N <= 10000`.
* Podzadatak 3 (60 bodova): nema daljih ograničenja.

## Izlaz
Izlaz sadrži samo jednu liniju. U njoj je napisan pozitivan cijeli broj koji označava broj parova ljudi koji su skupa zamislili dobar par brojeva.

## Primjeri
### Ulaz 1
```
4
23
100
50
62
```

### Izlaz 1
```
2
```

## Ulaz 2
```
3
13
71
71
```
## Izlaz 2
```
3
```