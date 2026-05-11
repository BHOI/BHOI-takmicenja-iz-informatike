# Brojevi

Armena voli kvadrate, a Berina voli kubove. Armenini omiljeni brojevi su oni koji su potpuni kvadrati ($1, 4, 9, 16, 25, \ldots$), dok su Berinini omiljeni brojevi potpuni kubovi ($1, 8, 27, 64, 125, \ldots$).

Dat je raspon cijelih brojeva od $A$ do $B$ (uključujući $A$ i $B$). Koliko ima brojeva u tom rasponu koje i Armena i Berina vole, tj. brojeva koji su istovremeno i potpuni kvadrat i potpuni kub?

## Ulazni podaci

U prvom redu se nalazi cijeli broj $A$.

U drugom redu se nalazi cijeli broj $B$.

### Ograničenja

$1 \leq A \leq B \leq 100\;000\;000$

## Izlazni podaci

Na jedinoj liniji izlaza ispišite broj brojeva u rasponu $[A, B]$ koji su istovremeno potpuni kvadrat i potpuni kub.

## Testni primjeri

Ovaj zadatak ne koristi podzadatke za bodovanje, već pojedinačne testne primjere koji nose po jednak broj bodova.

## Primjeri

### Ulaz 1
```
1
100
```

### Izlaz 1
```
2
```

### Objašnjenje 1

Brojevi u rasponu $[1, 100]$ koji su i potpuni kvadrat i potpuni kub su $1$ ($= 1^2 = 1^3$) i $64$ ($= 8^2 = 4^3$).

### Ulaz 2
```
700
900
```

### Izlaz 2
```
1
```

### Objašnjenje 2

Jedini takav broj u rasponu $[700, 900]$ je $729$ ($= 27^2 = 9^3$).
