# Klikeri
Zara ima veliku kolekciju klikera, a sada želi razdvojiti jednobojne od šarenih klikera. U liniji ima $N$ klikera koji su jednobojni (1) ili šareni (2). 

Zanima je koliko parova klikera mora zamijeniti kako bi razdvojila ove dvije grupe klikera. Grupe klikera će biti razdvojene ako su svi šareni klikeri prije svih jednobojnih ili ako su svi šareni klikeri poslije svih jednobojnih.

Možete li pomoći Zari odrediti koliko zamjena mora napraviti? Klikeri koji se zamijene **ne** moraju biti susjedni.

## Ulazni podaci

U prvom redu se nalazi cijeli broj $N$, broj klikera u liniji.

U drugom redu nalazi se $N$ cijelih brojeva $b_1, b_2, \ldots, b_N$, koji boje klikera. Broj 1 predstavlja jednobojne klikere, broj 2 predstavlja šarene.

### Ograničenja

- $1 \leq N \leq 1\;000\;000$
- $b_i \in \{1, 2\}$

## Podzadaci

### Podzadatak 1 (3 boda)

- $N = 1$

### Podzadatak 2 (8 bodova)

- $N = 2$

### Podzadatak 3 (33 boda)

- $N \leq 10$

### Podzadatak 4 (15 bodova)

- Broj šarenih klikera je najviše 10.

### Podzadatak 5 (41 bod)

- Nema dodatnih ograničenja.

## Izlazni podaci

Ispisati broj zamjena klikera koji je potreban da se razdvoje šareni i jednobojni klikeri.

## Primjeri

### Ulaz 1
```
5
1 2 1 2 2
```
### Izlaz 1
```
1
```
### Objašnjenje 1
Dovoljno je zamijeniti kliker na 2. mjestu i kliker na 3. mjestu da se dobije `1 1 2 2 2`, čime su razdvojene dvije grupe klikera.

### Ulaz 2
```
9
1 2 1 1 1 2 1 2 1
```
### Izlaz 2
```
2
```
### Objašnjenje 2
Zara može zamijeniti 1. i 8. kliker, čime dobije `2 2 1 1 1 2 1 1 1`, te 3. i 6. kliker, čime dobije `2 2 2 1 1 1 1 1 1`. Dakle, dovoljne su dvije zamjene.


### Ulaz 3
```
14
1 2 1 2 1 2 1 2 1 2 1 2 1 2
```
### Izlaz 3
```
3
```

