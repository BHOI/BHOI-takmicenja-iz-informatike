# Kalendar
Data su vam dva datuma. Potrebno je izračunati koliko ima dana između njih.

Također treba uzeti u obzir prestupne godine. Svaka godina koja je djeljiva sa 4 je prestupna, osim godina koje su djeljive sa 100. Ako je godina djejiva sa 100, onda prestupnost zavisi od toga da li je djeljiva sa 400. Ukoliko je djeljiva sa 400, onda je prestupna, u suprotnom nije prestupna. Godina 1900 nije prestupna a godina 2000 jeste.

Prestupna godina utiče na to koliko drugi mjesec (februar/veljača) ima dana. Ukoliko je prestupna, taj mjesec ima 29 dana, u suprotnom ima 28.

## Ulaz
Na ulazu su data dva datuma (svaki u pojedinačnom redu) u formatu `gggg:mm:dd`, gdje `gggg` predstavlja godinu, `mm` mjesec a `dd` dan. Mjeseci i dani uvijek imaju 2 cifre, tj jednocifreni brojevi imaju 0 ispred. Npr, treći dan u mjesecu je dat kao `03`.

### Ograničenja
```
1900 <= yyyy <= 2038
1 <= mm <= 12
1 <= dd <= broj_dana_u_mjesecu[mm]
```
*Uneseni datumi će uvijek biti validni*

## Izlaz
Broj dana između unesena dva datuma.

## Primjeri
### Ulaz 1
```
1900:01:01
2038:12:31
```
### Izlaz 1
```
50768
```

### Ulaz 2
```
1996:03:09
1991:11:12
```
### Izlaz 1
```
1579
```