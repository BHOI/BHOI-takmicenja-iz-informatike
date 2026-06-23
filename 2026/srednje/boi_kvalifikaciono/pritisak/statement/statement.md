# Pritisak

Sarajevski vodovodni sistem ima neobičan problem: vodeni tornjevi koji snabdijevaju grad imaju previše dobar pritisak. Kao rezultat, građane poprska voda kada peru kašike i drugi konkavni escajg. 

Kako bi riješili ovaj grozan problem gradska uprava je odlučila pokušati sljedeći pristup: otvaranjem direktne cijevi između dva tornja može smanjiti pritisak tornja sa višim pritiskom na toranj sa nižim.

Potrebno je odrediti da li je moguće na ovaj način promijeniti pritiske u tornjevima da budu baš onakvi kakve ih želimo.

Formalno, dat je neusmjereni povezani graf sa $N$ čvorova (numerisanih od $1$ do $N$) i $M$ grana. Svaki čvor $u$ ima početni pritisak $a_u$ i ciljni pritisak $b_u$. Operacija se sastoji od odabira grane $(u, v)$ i postavljanja $a_u = \min(a_u, a_v)$ ili $a_v = \min(a_u, a_v)$.

Odrediti da li je moguće, primjenom nula ili više operacija, transformirati niz $a$ u niz $b$.

## Ulazni podaci

Prva linija sadrži jedan cijeli broj $T$, broj testova.

Svaki test počinje linijom koja sadrži dva cijela broja $N$ i $M$, broj čvorova i broj grana u grafu.

Naredna linija sadrži $N$ cijelih brojeva $a_1, a_2, \ldots, a_N$, početni pritisci čvorova.

Naredna linija sadrži $N$ cijelih brojeva $b_1, b_2, \ldots, b_N$, ciljni pritisci čvorova.

Narednih $M$ linija, svaka sadrži dva cijela broja $u$ i $v$ koji opisuju granu između čvorova $u$ i $v$.

Vaš kod treba da za svih $T$ testova unutar testnog primjera odredi da li je moguće ovo uraditi ili ne.

### Ograničenja

- $1 \leq T \leq 300\,000$
- $1 \leq N \leq 150\,000$
- $0 \leq M \leq 200\,000$
- $1 \leq a_u, b_u \leq N$ za svaki čvor $u$
- Suma svih $N$ po svim testovima je najviše $300\,000$
- Suma svih $M$ po svim testovima je najviše $400\,000$
- Graf je uvijek povezan i nema višestrukih grana niti petlji

## Podzadaci

### Podzadatak 1 (15 bodova)

Graf je **zvijezda**: postoji jedan čvor koji je direktno povezan sa svim ostalim čvorovima i nema drugih grana ($M = N - 1$, maksimalni stepen je $N - 1$).

Suma $N^2$ po svim testovima je najviše $5\,000\,000$.

### Podzadatak 2 (7 bodova)

Graf je **kompletan**: svaka dva čvora su direktno povezana granom ($M = \frac{N(N-1)}{2}$, $N \leq 50$).

Suma $N \cdot M$ po svim testovima je najviše $12\,000\,000$.

### Podzadatak 3 (8 bodova)

Graf je **lanac**: čvorovi su poredani u niz gdje su susjedni čvorovi međusobno povezani ($M = N - 1$, svaki čvor ima stepen najviše $2$).

Suma $N^2$ po svim testovima je najviše $5\,000\,000$.

### Podzadatak 4 (15 bodova)

Graf je **lanac**.

### Podzadatak 5 (7 bodova)

Graf je **stablo** ($M = N - 1$).

Suma $N^2$ po svim testovima je najviše $5\,000\,000$.

### Podzadatak 6 (16 bodova)

Graf je **stablo** ($M = N - 1$) i niz $a$ je permutacija od $\{1, 2, \ldots, N\}$.

### Podzadatak 7 (10 bodova)

Suma $N \cdot M$ po svim testovima je najviše $5\,000\,000$.

### Podzadatak 8 (22 bodova)

Bez dodatnih ograničenja.

## Izlazni podaci

Za svaki test-primjer ispisati $1$ ako je moguće transformirati $a$ u $b$, inače ispisati $0$.

## Primjeri

### Ulaz 1

```
2
4 4
3 3 2 1
2 1 2 1
1 2
2 3
3 4
4 2
4 4
3 3 2 1
1 2 2 1
1 2
2 3
3 4
4 2
```

### Izlaz 1

```
1
0
```

### Objašnjenje 1

U prvom testu: čvor 1 ima početni pritisak 3 i ciljni 2, a čvor 2 ima početni pritisak 3 i ciljni 1. Otvaranjem cijevi (2, 3) pritisak tornja 2 se smanji na 2. Otvaranjem (1, 2) pritisak tornja 1 se smanji na 2. Otvaranjem (4, 2) pritisak tornja 2 se smanji na 1. Odgovor je 1.


U drugom testu imamo isti graf, ali nije moguće smanjiti pritisak čvora 1 da bude manji od pritiska čvora 2. Odgovor je 0.