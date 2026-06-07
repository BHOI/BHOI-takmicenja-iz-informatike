# Ceste

Alisa je došla u Zemlju Čudesa i odlučila posjetiti $T$ otoka. Na svakom otoku postoji sistem cesta koji povezuje gradove, a umjesto konkretnih ograničenja brzine, znakovi na cestama govore samo koliko se ograničenje **mijenja** kada se putuje određenom cestom.

Na primjer, ako na cesti od grada $A$ do grada $B$ piše $+20$, to znači da bi ograničenje brzine u gradu $B$ trebalo biti za $20$ km/h veće nego u gradu $A$. Ako piše $-15$, ograničenje u $B$ je za $15$ km/h manje nego u $A$.

Za svaki otok, Alisa želi zamijeniti ovaj sistem novim koji svakom gradu dodjeljuje konkretno ograničenje brzine, tako da sve postojeće promjene budu poštovane. Pomozite Alisi da utvrdi, za svaki otok zasebno, da li je to uopšte moguće, ili su postojeći znakovi međusobno kontradiktorni.

## Ulazni podaci

U prvom redu se nalazi cijeli broj $T$, broj otoka.

Za svaki otok slijedi opis: u prvom redu su dva cijela broja $N_i$ i $M_i$: broj gradova i broj cesta na tom otoku. U sljedećih $M_i$ redova se nalaze po tri cijela broja $u$, $v$ i $w$: cesta od grada $u$ do grada $v$ sa promjenom ograničenja $w$ (ograničenje u $v$ je za $w$ veće nego u $u$).

Gradovi na svakom otoku su numerisani od $1$ do $N_i$.

### Ograničenja

$1 \leq T \leq 10$

$1 \leq N_i \leq 100\;000$, zbir svih $N_i \leq 100\;000$

$0 \leq M_i \leq 200\;000$, zbir svih $M_i \leq 200\;000$

$-1\;000\;000 \leq w \leq 1\;000\;000$

$1 \leq u, v \leq N_i$

Može postojati više cesta između istog para gradova. Može postojati cesta od grada do njega samog.

**Napomena:** Zbog velikog broja ulaznih podataka, preporučuje se korištenje brzog ulaza/izlaza na početku programa:
```cpp
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
```

## Testni primjeri

Ovaj zadatak ne koristi podzadatke za bodovanje, već pojedinačne testne primjere koji nose po jednak broj bodova.

U testnim primjerima koji nose $10\%$ bodova vrijedi $T = 1$ i $N, M \leq 10$.

U testnim primjerima koji nose $20\%$ bodova vrijedi $T = 1$ i graf je stablo (povezan i ima tačno $N - 1$ cestu).

## Izlazni podaci

Ispišite tačno $T$ redova. U $i$-tom redu ispišite `DA` ako je moguće dodijeliti ograničenja brzine svim gradovima $i$-tog otoka tako da sve promjene budu poštovane, ili `NE` u suprotnom.

## Primjeri

### Ulaz 1
```
1
3 3
1 2 10
2 3 20
1 3 30
```

### Izlaz 1
```
DA
```

### Objašnjenje 1

Na jedinom otoku možemo postaviti ograničenja, na primjer: grad 1 ima 50, grad 2 ima 60, grad 3 ima 80 km/h. Tada: od 1 do 2 promjena je $60 - 50 = 10$ (ispravno), od 2 do 3 promjena je $80 - 60 = 20$ (ispravno), od 1 do 3 promjena je $80 - 50 = 30$ (ispravno).

### Ulaz 2
```
2
3 3
1 2 10
2 3 20
1 3 25
4 2
1 2 5
3 4 -3
```

### Izlaz 2
```
NE
DA
```

### Objašnjenje 2

Na prvom otoku: od grada 1 do grada 3 preko grada 2 ukupna promjena je $10 + 20 = 30$, ali direktna cesta od 1 do 3 kaže da je promjena $25$. Ovo je kontradikcija, pa je odgovor `NE`.

Drugi otok je sacinjen od dva para nepovezanih gradova. Validno rješenje je da grad 1 ima ograničenje 50, grad 2 ima 55, graf 3 30 i grad 4 ima ograničenje 27 km/h. Nema kontradikcija, pa je odgovor `DA`.
