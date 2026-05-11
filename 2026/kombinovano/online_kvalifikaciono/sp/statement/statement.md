# Svjetsko prvenstvo

Bosna i Hercegovina je prošla grupnu fazu Svjetskog prvenstva u fudbalu! U eliminacionoj fazi učestvuje $N$ reprezentacija, rangirane od $1$ (najbolja) do $N$ (najlošija), gdje je $N$ uvijek stepen broja $2$.

Raspored utakmica u prvoj rundi se pravi po standardnom sistemu nosivosti (seedinga): rangovi se "presaviju" tako da se $1.$ rangirana uparuje sa $N.$, $2.$ sa $(N-1).$, $3.$ sa $(N-2).$, i tako dalje. Isti princip presavijanja se zatim primijeni rekurzivno na raspored parova unutar tablice, kako bi se osiguralo da se najbolje rangirane reprezentacije susretnu što kasnije u turniru.

Za $N = 8$, raspored izgleda ovako:

```
  1 vs 8  ─┐
           ├─ ? ─┐
  4 vs 5  ─┘     │
                 ├─ ? ─── Pobjednik
  2 vs 7  ─┐     │
           ├─ ? ─┘
  3 vs 6  ─┘
```

Za $N = 32$, raspored izgleda ovako:

```
  1 vs 32  ─┐
            ├── ? ─┐
 16 vs 17  ─┘      │
                   ├── ? ─┐
  8 vs 25  ─┐      │      │
            ├── ? ─┘      │
  9 vs 24  ─┘             │
                          ├── ? ─┐
  4 vs 29  ─┐             │      │
            ├── ? ─┐      │      │
 13 vs 20  ─┘      │      │      │
                   ├── ? ─┘      │
  5 vs 28  ─┐      │             │
            ├── ? ─┘             │
 12 vs 21  ─┘                    │
                                 ├── ? ─── Pobjednik
  2 vs 31  ─┐                    │
            ├── ? ─┐             │
 15 vs 18  ─┘      │             │
                   ├── ? ─┐      │
  7 vs 26  ─┐      │      │      │
            ├── ? ─┘      │      │
 10 vs 23  ─┘             │      │
                          ├── ? ─┘
  3 vs 30  ─┐             │
            ├── ? ─┐      │
 14 vs 19  ─┘      │      │
                   ├── ? ─┘
  6 vs 27  ─┐      │
            ├── ? ─┘
 11 vs 22  ─┘
```


Primijetite princip: u prvoj rundi, zbir rangova dva protivnika u svakom meču je uvijek isti i iznosi $N + 1$. **Ako pretpostavimo da uvijek pobijedi tim sa manjim (boljim) rangom**, onda u drugoj rundi zbir rangova dva protivnika u svakom meču iznosi $N/2 + 1$. U trećoj rundi taj zbir iznosi $N/4 + 1$, i tako dalje. Generalno, u $k$-toj rundi zbir rangova dva protivnika iznosi $N/2^{k-1} + 1$. Na kraju, u finalu se susreću rangovi $1$ i $2$ (zbir $N/2^{\log_2 N - 1} + 1 = 2 + 1 = 3$).

Na primjer, za $N = 32$: u prvoj rundi zbir je $33$ (npr. $1+32$, $16+17$, ...), u drugoj rundi zbir je $17$ (npr. $1+16$, $8+9$, ...), u trećoj $9$, u četvrtoj $5$, a u finalu $3$ (rangovi $1$ i $2$).

Bosna i Hercegovina ima rang $A$, a Francuska ima rang $B$. **Pod pretpostavkom da obje reprezentacije pobijede sve svoje utakmice** do međusobnog susreta, u kojoj rundi će se sresti?

## Ulazni podaci

U jedinom redu ulaza nalaze se tri cijela broja $N$, $A$ i $B$: ukupan broj reprezentacija i rangovi BiH i Francuske.

### Ograničenja

$2 \leq N \leq 2^{30}$

$N$ je stepen broja $2$.

$1 \leq A, B \leq N$

$A$ ≠ $B$

## Podzadaci

### Podzadatak 1 (4 boda)
$B = N - A + 1$ (BiH i Francuska igraju u prvoj rundi)

### Podzadatak 2 (25 bodova)
$B = A + 1$

### Podzadatak 3 (20 bodova)
$N = 8$

### Podzadatak 4 (30 bodova)
$N \leq 2^{10}$

### Podzadatak 5 (41 bod)
Bez dodatnih ograničenja.

## Izlazni podaci

Na jedinoj liniji izlaza ispišite redni broj runde u kojoj se BiH i Francuska susreću. Runde su numerisane počevši od $1$ (prva runda).

## Primjeri

### Ulaz 1
```
8 1 8
```

### Izlaz 1
```
1
```

### Objašnjenje 1

Rangovi $1$ i $8$ igraju jedan protiv drugog u prvoj rundi (četvrtfinale).

### Ulaz 2
```
8 1 2
```

### Izlaz 2
```
3
```

### Objašnjenje 2

Rang $1$ i rang $2$ su raspoređeni u suprotne polovine tablice i mogu se sresti tek u finalu, tj. trećoj rundi.

### Ulaz 3
```
8 1 4
```

### Izlaz 3
```
2
```

### Objašnjenje 3

Rang $1$ pobjeđuje rang $8$ u prvoj rundi. Rang $4$ pobjeđuje rang $5$ u prvoj rundi. Zatim se rangovi $1$ i $4$ susreću u drugoj rundi (polufinale).

### Ulaz 4
```
32 1 4
```

### Izlaz 4
```
4
```

### Objašnjenje 4

U turniru sa $32$ reprezentacije ima ukupno $5$ rundi (šesnaestina finala, osmina finala, cetvrtfinale, polufinale, finale). Rang $1$ i rang $4$ su u istoj polovini tablice, ali se nalaze u različitim osminama, pa se susreću tek u $4.$ rundi (polufinale).

### Ulaz 5
```
1024 5 12
```

### Izlaz 5
```
7
```

### Objašnjenje 5

U turniru sa $1024$ reprezentacije ima ukupno $10$ rundi. Rangovi $5$ i $12$ se susreću u $7.$ rundi.

### Ulaz 6
```
8 7 8
```

### Izlaz 6
```
3
```

### Ulaz 7
```
8 7 3
```

### Izlaz 7
```
2
```