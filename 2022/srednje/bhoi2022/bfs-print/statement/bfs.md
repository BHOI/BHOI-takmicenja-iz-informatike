# BFS
Muamer je skoro naučio svima dobro poznat algoritam – BFS ili algoritam pretrage grafa u širinu. Nije mnogo prošlo, brat Muhamed mu je postavio zadatak od koga ga već par dana boli glava.

Svima je poznato kako funkcioniše taj opšte poznat algoritam. Međutim, redoslijed kojim se biraju čvorovi prilikom izvršavanja algoritma, može da varira i stoga može da postoji više sekvenci koje bi opisale taj redoslijed.

Naime, Muamerov zadatak je da za datu sekvencu i stablo, provjeri da li je to neka od sekvenci koje je mogao da formira BFS prilikom izvršavanja ako je BFS __počeo izvršavanje iz čvora broj 1__.

Stablo je povezani graf bez ciklusa čija su svaka dva vrha u njemu
povezana tačno jednim putem.

## Ulaz
Prva linija na ulazu sadrži pozitivan cijeli broj `N` - broj čvorova
stabla.

Sljedećih N - 1 linija opisuju grane stabla. Svaka sadrži dva broja `x` i `y` - čvorovi koji su povezani u grafu. Garantovano je da je graf u ulazu stablo.

Posljednja linija sadrži `N` različitih brojeva `A1`, `A2`, ... `An` - sekvenca koju je potrebno provjeriti.

### Ograničenja
```
1 <= N <= 200 000
1 <= x, y <= N
```

* Podzadatak 1 (10 poena): `1 <= N <= 10`
* Podzadatak 2 (20 poena): `1 <= N <= 200`
* Podzadatak 3 (70 poena): Bez ograničenja

## Izlaz
Ispisati `DA` ako data sekvenca odgovara nekom od BFS sekvenci datog stabla, ili ispisati `NE` u suprotnom.

## Primjeri
### Ulaz 1
```
4
1 2
1 3
2 4
1 2 3 4
```

### Izlaz 1
```
DA
```

_mogući scenarij:_

```
   1(1)             1(1)
 /   \            /   \
3(2)  2(3)       3(3)  2(2)
       \                \
        4(4)             4(4)
```

_U zagradama su dati redoslijedi_

### Ulaz 2
```
4
1 2
1 3
2 4
1 4 2 3
```

### Izlaz 2
```
NE
```