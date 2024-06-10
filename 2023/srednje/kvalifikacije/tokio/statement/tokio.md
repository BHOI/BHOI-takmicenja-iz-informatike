# Tokio
Jedan od najvećih i najljepših gradova Azije u kome živi preko 13 miliona ljudi je upravo i glavni grad Japana – Tokio. Poznat po nazivu „Istočni glavni grad“, ova metropola se vodi kao druga najveća urbana ekonomija svijeta. Kako je Drago uvijek bio veliki ljubitelj putovanja i upoznavanja novih kultura, odlučio se za ovaj grad kao svoju ovogodišnju ljetnu destinaciju.

Jedna od karakteristika ovog grada je ogroman broj nebodera koji su napravljeni u njemu, koje ćemo jednostavnosti radi, predstaviti kao niz brojeva `A`, gdje je `A[i]` visina `i`-tog nebodera. Neboderi su postavljeni na jednoj pravoj, gdje je prvi na poziciji `X=0`, drugi `X=1` itd. Pošto Drago dolazi iz bogate porodice, on je odlučio da dođe u ovaj grad sa privatnim helikopterom i sleti na jedan od nebodera. Svi neboderi imaju pistu za sletanje na svome vrhu, ali u zavisnosti u kome helikopteru dođe, Drago neće moći sletjeti na bilo koji od njih.

Dragove helikoptere možemo opisati sa sledećim karakteristikama:
- Brojevi `s` i `e` – indeks prvog i poslednjeg nebodera na koji helikopter ima dozvolu da sleti (uključujući i indekse `s` i `e`)
- Broj `l` i `r` – minimalna i maksimalna visina nebodera na koji helikopter može da sleti (uključujući i visine l i r)

Kako je Dragova kolekcija helikoptera ogromna, on želi da za svaki od njih pronađe broj nebodera na koje može da sleti. Pomozite Dragi da reši ovaj problem.

## Ulaz
Prva linija na ulazu sadrži dva pozitivna cijela broja `N` - broj nebodera, `M` - broj helikoptera

Druga linija sadrži `N` cijelih pozitivnih brojeva `A[i]` - visina `i`-tog nebodera.

Sljedećih `M` linija sadrže nenegativne cijele karakteristike helikoptera `s[i]`,`e[i]`,`l[i]`,`r[i]` iz teksta zadatka.

### Ograničenja
```
1 <= N,M <= 100 000
0 <= s[i] < N
s[i] <= e[i] < N
0 <= l[i] <= 100 000
l[i] <= r[i] <= 100 000
1 <= A[i] <= 100 000
```
- U 20% test primjera važi ograničenje: `N, M <= 1000`
- U 10% test primjera važi ograničenje: `M, A[i] <= 1000`
- U 10% test primjera važi ograničenje: `r[i] - l[i] <= 10`

## Izlaz
Za svaki od helikoptera ispisati jedan pozitivan cijeli broj u novom redu – broj nebodera na koje taj helicopter može da sleti.

## Primjeri
### Ulaz 1
```
5 3
1 2 3 4 5
0 4 1 2
1 4 1 2
1 1 1 2
```
### Izlaz 1
```
2
1
1
```
### Objašnjenje 1
- Prvi helikopter može da sleti na prva dva nebodera.
- Drugi helikopter može da sleti samo na drugi neboder.
- Treći helikopter može da sleti samo na prvi neboder.

## Primjer 2
### Ulaz 2
```
5 3
1 1 1 2 10
0 4 11 11
0 3 3 4
0 3 2 4 
```
### Izlaz 2
```
0
0
1
```
