# Kišobrani

Nad gradom se sprema kiša! Grad se može zamisliti kao mreža sa $R$ redova i $C$ kolona. Redovi su numerisani od $1$ (vrh) do $R$ (dno), a kolone od $1$ do $C$. Iznad reda $1$ je nebo, a ispod reda $R$ je tlo.

U gradu su postavljeni kišobrani. Svaki kišobran se nalazi u tačno jednom redu i pokriva uzastopne kolone. Kišobran $i$ je opisan trojkom $(r_i, a_i, b_i)$: nalazi se u redu $r_i$ i pokriva kolone od $a_i$ do $b_i$. Svaki kišobran ima parnu širinu, tj. $b_i - a_i + 1$ je paran broj.

Kiša pada sa neba: iz svake kolone od $1$ do $C$ pada tačno jedna kap kiše ravno nadolje. Kap koja pada iz kolone $c$ prolazi kroz redove $1, 2, \ldots, R$ redom. Ako kap u nekom redu naleti na kišobran koji pokriva kolone od $a$ do $b$ (širine $w = b - a + 1$):

- Ako se kap nalazi na lijevoj polovini kišobrana (kolone od $a$ do $a + w/2 - 1$), sklizne ulijevo i nastavi padati sa kolone $a - 1$.
- Ako se kap nalazi na desnoj polovini kišobrana (kolone od $a + w/2$ do $b$), sklizne udesno i nastavi padati sa kolone $b + 1$.

Nakon što sklizne sa kišobrana, kap nastavlja padati nadolje kroz preostale redove i može naletjeti na druge kišobrane.

Na kraju, svaka kap padne na tlo na nekoj koloni. Neke kapi mogu završiti van mreže (na koloni $0$ ili $C + 1$).

Za $Q$ upita, svaki zadan intervalom $[L_j, D_j]$, odredite koliko kapi kiše padne na tlo unutar kolona od $L_j$ do $D_j$ (uključujući krajeve).

## Ulazni podaci

U prvom redu nalaze se četiri cijela broja $R$, $C$, $N$ i $Q$: broj redova mreže, broj kolona, broj kišobrana i broj upita.

U svakom od idućih $N$ redova nalaze se tri cijela broja $r_i$, $a_i$ i $b_i$ koji opisuju $i$-ti kišobran: red u kojem se nalazi, te prvu i posljednju kolonu koju pokriva.

U svakom od idućih $Q$ redova nalaze se dva cijela broja $L_j$ i $D_j$ koji opisuju $j$-ti upit.

### Ograničenja

- $1 \leq R \leq 100$
- $1 \leq C \leq 10^9$
- $0 \leq N \leq 200\;000$
- $1 \leq Q \leq 200\;000$
- $1 \leq r_i \leq R$
- $1 \leq a_i \leq b_i \leq C$
- $b_i - a_i + 1$ je paran za svaki kišobran
- Dva kišobrana u istom redu imaju barem jednu praznu kolonu između sebe
- $1 \leq L_j \leq D_j \leq C$

**Napomena:** Koristite `ios::sync_with_stdio(false)` i `cin.tie(nullptr)` za brži unos.

## Podzadaci

### Podzadatak 1 (5 bodova)

- $C \leq 1\;000\;000$
- $N = 0$
- $Q \leq 1\;000$

### Podzadatak 2 (6 bodova)

- $C \leq 1\;000\;000$
- $N \leq 1$
- $Q \leq 1\;000$

### Podzadatak 3 (10 bodova)

- $C \leq 1\;000\;000$
- $N \leq 10\;000$
- Svi kišobrani se nalaze u istom redu.
- $Q \leq 1\;000$

### Podzadatak 4 (10 bodova)

- $N \leq 10\;000$
- $C \leq 1\;000$
- $Q \leq 1\;000$

### Podzadatak 5 (7 bodova)

- $C \leq 1\;000\;000$
- $N \leq 10\;000$
- $Q \leq 1\;000$

### Podzadatak 6 (22 bodova)

- $C \leq 1\;000\;000$
- $N \leq 10\;000$
- $Q \leq 100\;000$

### Podzadatak 7 (40 bodova)

- Nema dodatnih ograničenja.

## Izlazni podaci

Za svaki upit ispisati jedan cijeli broj u posebnom redu: broj kapi kiše koje padnu na tlo unutar kolona od $L_j$ do $D_j$.

## Primjeri

### Ulaz 1
```
3 9 1 3
2 4 7
1 3
4 7
8 9
```

### Izlaz 1
```
5
0
4
```

### Objašnjenje 1

Mreža ima 3 reda i 9 kolona. Postoji jedan kišobran u redu 2 koji pokriva kolone 4 do 7 (širine 4). Lijeva polovina kišobrana su kolone 4 i 5, a desna polovina su kolone 6 i 7.

```
         1  2  3  4  5  6  7  8  9
Red 1:   .  .  .  .  .  .  .  .  .
Red 2:   .  .  .  L  L  R  R  .  .
Red 3:   .  .  .  .  .  .  .  .  .
Zemlja:  1  2  3  4  5  6  7  8  9
```

Kapi sa kolona 1, 2 i 3 ne nailaze na kišobran i padaju ravno na tlo.
Kapi sa kolona 4 i 5 udaraju u lijevu polovinu kišobrana i skliznu na kolonu 3.
Kapi sa kolona 6 i 7 udaraju u desnu polovinu kišobrana i skliznu na kolonu 8.
Kapi sa kolona 8 i 9 ne nailaze na kišobran i padaju ravno na tlo.

Na tlu, na kolonu 3 padnu 3 kapi (originalne sa 3, 4 i 5), na kolonu 8 padnu 3 kapi (originalne sa 6, 7 i 8), a na kolone 1, 2 i 9 po jedna kap.

- Upit $[1, 3]$: na kolone 1, 2, 3 padne ukupno $1 + 1 + 3 = 5$ kapi.
- Upit $[4, 7]$: na kolone 4 do 7 ne padne nijedna kap.
- Upit $[8, 9]$: na kolone 8 i 9 padne ukupno $3 + 1 = 4$ kapi.

### Ulaz 2
```
3 9 2 3
1 4 7
2 1 6
1 3
4 7
8 9
```

### Izlaz 2
```
0
0
4
```

### Objašnjenje 2

Kišobran u redu 1 pokriva kolone 4 do 7, a kišobran u redu 2 pokriva kolone 1 do 6.

```
         1  2  3  4  5  6  7  8  9
Red 1:   .  .  .  L  L  R  R  .  .
Red 2:   L  L  L  R  R  R  .  .  .
Red 3:   .  .  .  .  .  .  .  .  .
Zemlja:  1  2  3  4  5  6  7  8  9
```

Kapi sa kolona 1, 2 i 3 prolaze red 1 bez prepreke. U redu 2, udaraju u lijevu polovinu donjeg kišobrana (kolone 1, 2, 3) i skliznu na kolonu 0, van mreže.

Kapi sa kolona 4 i 5 udaraju u lijevu polovinu gornjeg kišobrana u redu 1 i skliznu na kolonu 3. U redu 2, udaraju u lijevu polovinu donjeg kišobrana i skliznu na kolonu 0, van mreže.

Kapi sa kolona 6 i 7 udaraju u desnu polovinu gornjeg kišobrana u redu 1 i skliznu na kolonu 8. Prolaze red 2 bez prepreke i padaju na kolonu 8.

Kapi sa kolona 8 i 9 ne nailaze ni na jedan kišobran i padaju na kolone 8 i 9.

- Upit $[1, 3]$: na kolone 1 do 3 ne padne nijedna kap (sve su završile na koloni 0).
- Upit $[4, 7]$: na kolone 4 do 7 ne padne nijedna kap.
- Upit $[8, 9]$: na kolone 8 i 9 padne ukupno $3 + 1 = 4$ kapi.
