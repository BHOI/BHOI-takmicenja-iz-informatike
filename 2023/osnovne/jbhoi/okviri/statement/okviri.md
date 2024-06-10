# Okviri

Nikola je majstor koji se bavi izradom okvira za razne vrste slika i u tome je veoma vješt. Okvire pravi od drveta i trenutno kod sebe ima `N` dasaka i sav potreban alat. Svaka daska ima svoju dužinu `D[i]`.

Dobio je zadatak da napravi pravougaone okvire i to na takav način da je suma njihovih površina što veća. Svaka daska može da se iskoristi za najviše jedan okvir, a neke od njih mogu ostati i neiskorištene.

Neka su `a1`, `a2`, `a3`, `a4` proizvoljne dužine nekih dasaka. Da bi se od njih mogao napraviti okvir, moraju se ispoštovati sledeća pravila:

- `a1 <= a2 <= a3 <= a4`

- `a1 = a2`

- `a3 = a4`

Recimo daske *5, 5, 5, 5* ili *6, 6, 8, 8* mogu da formiraju okvir, ali *3, 3, 3, 5* ne mogu.

Majstor Nikola ima i testeru pomoću koje može da skrati svoje daske. Međutim, pošto je testera veoma malena, dužina svake daske se može skratiti za najviše jedan. Na primjer daska dužine *5* može ostati ili te dužine ili dužine *4* ako se odsječe.

Koja je najveća ukupna površina koja se može dobiti izradom okvira koristeći date daske?

## Ulaz

Prva linija na ulazu sadrži pozitivan cijeli broj `N` - koji označava broj dasaka.

Druga linija sadrži `N` pozitivnih cijelih brojeva `D[i]` - dužine dasaka.

### Ograničenja
```
1 <= N <= 100 000
1 <= D[i] <= 1 000 000
```

### Podzadaci
* Podzadatak 1 (20 bodova): `1 <= N <= 10`
* Podzadatak 2 (35 bodova): `1 <= N <= 2000`
* Podzadatak 3 (45 bodova): Bez dodatnih ograničenja

## Izlaz
Izlaz sadrži samo jednu liniju koja sadrži nenegativan cijeli broj koji označava maksimalnu ukupnu površinu koja se može dobiti koristeći date daske.

## Primjeri
### Ulaz 1
```
4
2 4 4 2
```
### Izlaz 1
```
8
```
### Objašnjenje 1
Okvir sa stranicama: *2, 2, 4, 4* je validan i njegova površina je *8*.
### Ulaz 2
```
4
1 1 1 2
```
### Izlaz 2
```
1
```
### Objašnjenje 2
Ako skratimo dasku dužine *2*, moguće je formirati okvir površine *1*.
