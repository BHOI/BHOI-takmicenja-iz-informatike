# Igralište

Na školskom igralištu $N$ djece igra igru. Svako dijete ima papir zalijepljen na čelo na kojem piše neki broj, ali ne može vidjeti svoj papir. Neka djeca mogu vidjeti neku drugu djecu i reći im šta im piše na čelu, ali ne i sebi.

Poznato je $M$ parova djece $(a_i, b_i)$ koja se mogu međusobno vidjeti. Ako dijete $a_i$ vidi dijete $b_i$, onda i dijete $b_i$ vidi dijete $a_i$.

Dijete može saznati šta mu piše na čelu samo ako ga barem jedno drugo dijete može vidjeti. Koliko djece nikada neće moći saznati šta im piše na čelu?

## Ulazni podaci

U prvom redu se nalaze dva cijela broja $N$ i $M$: broj djece i broj parova djece koja se mogu vidjeti.

U sljedećih $M$ redova se nalaze po dva cijela broja $a_i$ i $b_i$: par djece koja se mogu međusobno vidjeti.

### Ograničenja

$1 \leq N \leq 100\;000$

$0 \leq M \leq 100\;000$

$1 \leq a_i, b_i \leq N$

$a_i $ ≠ $ b_i$

Nijedan par se ne pojavljuje više puta.

## Podzadaci

### Podzadatak 1 (9 bodova)
$M = 0$

### Podzadatak 2 (16 bodova)
$M = 2$

### Podzadatak 3 (39 bodova)
$N \leq 10$, $M \leq 10$

### Podzadatak 4 (16 bodova)
Bez dodatnih ograničenja.

## Izlazni podaci

Na jedinoj liniji izlaza ispišite broj djece koja nikada neće moći saznati šta im piše na čelu.

## Primjeri

### Ulaz 1
```
5 3
1 2
3 4
4 5
```

### Izlaz 1
```
0
```

### Objašnjenje 1

Dijete $1$ može saznati od djeteta $2$, i obrnuto. Dijete $3$ može saznati od djeteta $4$, dijete $4$ od djeteta $3$ ili $5$, a dijete $5$ od djeteta $4$. Sva djeca mogu saznati šta im piše na čelu.

### Ulaz 2
```
4 1
2 3
```

### Izlaz 2
```
2
```

### Objašnjenje 2

Djeca $2$ i $3$ se mogu međusobno vidjeti, ali djeca $1$ i $4$ ne vidi niko, pa nikada neće saznati šta im piše na čelu.
