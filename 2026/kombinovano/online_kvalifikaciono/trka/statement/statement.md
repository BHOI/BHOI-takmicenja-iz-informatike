# Trka

Vanja, Ivana i Tarik se takmiče ko će prvi stići od tačke $A$ do tačke $B$ u prostoru. Tačke su zadane koordinatama u trodimenzionalnom koordinatnom sistemu.

Vanja se kreće tako da svake sekunde može promijeniti svaku od svojih koordinata za najviše $1$ (može promijeniti sve tri koordinate istovremeno). Ivana se teleportira brzinom od $1$ jedinice u sekundi duž prave linije od $A$ do $B$. Tarik se kreće tako da svake sekunde promijeni tačno jednu od svojih koordinata za $1$.

Udaljenost koju Ivana mora preći između dvije tačke $(x_1, y_1, z_1)$ i $(x_2, y_2, z_2)$ u 3D prostoru iznosi $\sqrt{(x_2-x_1)^2 + (y_2-y_1)^2 + (z_2-z_1)^2}$.

Koliko vremena (u cijelim sekundama, zaokruženo na dolje) treba svakom od njih da stigne od $A$ do $B$?

## Ulazni podaci

U prvom redu se nalaze tri cijela broja $x_1$, $y_1$, $z_1$: koordinate tačke $A$.

U drugom redu se nalaze tri cijela broja $x_2$, $y_2$, $z_2$: koordinate tačke $B$.

### Ograničenja

$-1\;000 \leq x_1, y_1, z_1, x_2, y_2, z_2 \leq 1\;000$

## Izlazni podaci

U prvom redu ispišite vrijeme koje je potrebno Vanji (cijeli broj).

U drugom redu ispišite vrijeme koje je potrebno Ivani (cijeli broj, zaokružen na dolje).

U trećem redu ispišite vrijeme koje je potrebno Tariku (cijeli broj).

## Testni primjeri

Ovaj zadatak ne koristi podzadatke za bodovanje, već pojedinačne testne primjere koji nose po jednak broj bodova.

U testnim primjerima koji nose $20\%$ bodova vrijedi $y_1 = y_2$ i $z_1 = z_2$.

## Primjeri

### Ulaz 1
```
0 0 0
0 5 0
```

### Izlaz 1
```
5
5
5
```

### Objašnjenje 1
Svakome će trebati tačno 5 sekundi da dođe od tačke $(0,0,0)$ do $(0,5,0)$.


### Ulaz 2
```
3 -2 1
4 -1 3
```

### Izlaz 2
```
2
2
4
```

### Objašnjenje 2

Razlike po koordinatama su 1, 1 i 2, redom. Vanji treba $\max(1, 1, 2) = 2$, Ivani $\lfloor\sqrt{6}\rfloor = 2$, Tariku $1 + 1 + 2 = 4$ sekundi.


### Ulaz 3
```
32 -176 6
-725 42 7
```

### Izlaz 3
```
757
787
976
```


