# Suncobrani

Dariz ne želi izgoriti na suncu, pa koristi suncobrane (i kremu za sunce!).

Jedan suncobran $i$ pokrije polja od $A_i$ do $B_i$ i debeo je $D_i$ milimetara. Količina zaštite na nekom polju je zbir debljina suncobrana koja pokriju ta polja. 

Dariz želi leći tako da pokrije $l$ uzastopnih polja, pomozite mu odrediti gdje da legne tako da je maksimalno zaštićen. To ćete odrediti tako što saberete količine zaštite svakog polja koje Dariz pokriva.

Ako ima više mjesta gdje Dariz može leći sa maksimalnom zaštitom odredite prvo takvo mjesto (odrediti prvo i poljednje polje koje će pokriti tako da su indeksi tih polja što manji).

## Ulazni podaci

U prvom redu se nalaze cijeli brojevi $N$ i $l$, broj suncobrana i broj polja koje će Dariz pokriti kad legne.

U svakom od idućih $N$ redova se nalaze brojevi $A_i$, $B_i$ i $D_i$, prvo polje koje suncobran $i$ pokrije, posljednje i debljina tog suncobrana.

### Ograničenja

- $1 \leq N \leq 200\;000\;$
- $1 \leq l \leq 10^9$
- $1 \leq A_i \leq B_i \leq 10^9$
- $1 \leq D_i \leq 10$

## Podzadaci

### Podzadatak 1 (4 bodova)
- $N = 1$
- $1 \leq l \leq 10\;000$
- $1 \leq A_i \leq B_i \leq 100\;000$

### Podzadatak 2 (6 bodova)
- $l = 1$
- $A_i = B_i$ za svako $i$
- $1 \leq N \leq 1\;000$
- $1 \leq A_i \leq B_i \leq 100\;000$

### Podzadatak 3 (8 bodova)
- $1 \leq A_i \leq B_i \leq 1\;000$
- $l = 1000$
- $1 \leq N \leq 1\;000$

### Podzadatak 4 (11 bodova)
- $A_i = B_i$ za svako $i$

- $1 \leq N \leq 1\;000$
- $1 \leq l \leq 10\;000$
- $1 \leq A_i \leq B_i \leq 100\;000$

### Podzadatak 5 (13 bodova)
- $1 \leq N, l, A_i, B_i, D_i \leq 10$

### Podzadatak 6 (18 bodova)

- $1 \leq N \leq 1\;000$
- $1 \leq l \leq 10\;000$
- $1 \leq A_i \leq B_i \leq 100\;000$

### Podzadatak 7 (40 bodova)

Bez dodatnih ograničenja

## Izlazni podaci

Na jedinoj liniji izlaza ispisati dva cijela broja, prvo i posljednje polje koje će Dariz pokriti ako legne tako da bude maksimalno zaštićen suncobranima.

Indeksi ispisanih polja **mogu biti negativni**.

## Primjeri

### Ulaz 1
```
1 3
2 6 5
```

### Izlaz 1
```
2 4
```

### Objašnjenje 1

Jedini suncobran pokriva polja 2 do 6 sa debljinom 5. Sva polja unutar raspona imaju zaštitu 5, pa je ukupna zaštita za bilo koja 3 uzastopna polja u tom rasponu jednaka 15. Biramo prvu takvu poziciju, pa Dariz leži na poljima 2, 3 i 4.

### Ulaz 2
```
2 2
1 4 3
3 6 5
```

### Izlaz 2
```
3 4
```

### Objašnjenje 2

Suncobran 1 pokriva polja 1 do 4 (debljina 3), a suncobran 2 pokriva polja 3 do 6 (debljina 5). Zaštita po poljima: polje 1 = 3, polje 2 = 3, polje 3 = 8, polje 4 = 8, polje 5 = 5, polje 6 = 5. Za $l = 2$ uzastopna polja, sume su: [1,2] = 6, [2,3] = 11, [3,4] = 16, [4,5] = 13, [5,6] = 10. Maksimalna suma je 16, a postiže se na poziciji [3,4].

### Ulaz 3
```
2 5
1 2 5
4 4 5
```

### Izlaz 3
```
0 4
```

### Objašnjenje 3

Suncobran 1 pokriva polja 1 i 2 (debljina 5), a suncobran 2 pokriva samo polje 4 (debljina 5). Zaštita po poljima: polje 1 = 5, polje 2 = 5, polje 3 = 0, polje 4 = 5. Za $l = 5$ uzastopnih polja, sume za [0,4] i [1,5] su obje 15. Biramo prvu poziciju, pa Dariz leži na poljima 0, 1, 2, 3  i 4.
