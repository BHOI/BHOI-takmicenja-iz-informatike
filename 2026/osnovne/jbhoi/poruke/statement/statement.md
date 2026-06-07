# Poruke

Luka i Luka su najbolji prijatelji koji vole slati poruke sa skrivenim značenjima. Dogovorili su se za sistem tajnih poruka: ponekad sakrivena riječ mora biti sadržana kao uzastopni dio poruke (podstring), a ponekad slova sakrivene riječi moraju biti raspoređena redom unutar poruke, ali ne moraju biti uzastopna (podniz).

Dat je cijeli broj $T$ koji određuje tip provjere, te stringovi $A$ i $B$. Ako je $T = 0$, potrebno je provjeriti da li je $A$ podstring od $B$ (tj. da li se $A$ pojavljuje kao uzastopni dio u $B$). Ako je $T = 1$, potrebno je provjeriti da li je $A$ podniz od $B$ (tj. da li se sva slova od $A$ pojavljuju u $B$ u istom redoslijedu, ali ne moraju biti uzastopna).

## Ulazni podaci

U prvom redu se nalazi cijeli broj $T$ ($0$ ili $1$).

U drugom redu se nalazi string $A$.

U trećem redu se nalazi string $B$.

Stringovi se sastoje isključivo od malih slova engleske abecede.

### Ograničenja

$T \in \{0, 1\}$

$1 \leq |A|, |B| \leq 100\;000$

Ako $T=0$, onda $ 1 \leq |A| \cdot |B| \leq 1\;000\;000$
## Podzadaci

### Podzadatak 1 (4 boda)
$|A| = |B|$

### Podzadatak 2 (18 bodova)
$|A|, |B| \leq 3$

### Podzadatak 3 (20 bodova)
$T = 0$

### Podzadatak 4 (40 bodova)
$T = 1$

### Podzadatak 5 (18 bodova)
Bez dodatnih ograničenja.

## Izlazni podaci

Na jedinoj liniji izlaza ispišite `DA` ako je uslov ispunjen, ili `NE` u suprotnom.

## Primjeri

### Ulaz 1
```
0
abc
xabcy
```

### Izlaz 1
```
DA
```

### Objašnjenje 1

String `abc` se pojavljuje kao uzastopni dio u stringu `xabcy` (drugo, treće i četvrto slovo).

### Ulaz 2
```
1
ace
abcde
```

### Izlaz 2
```
DA
```

### Objašnjenje 2

Slova `a`, `c`, `e` se pojavljuju u stringu `abcde` u istom redoslijedu (na pozicijama 0, 2, 4), pa je `ace` podniz od `abcde`.

### Ulaz 3
```
0
abc
axbxc
```

### Izlaz 3
```
NE
```

### Objašnjenje 3

String `abc` se ne pojavljuje kao uzastopni dio u stringu `axbxc`. Napomena: `abc` jeste podniz od `axbxc`, ali pitanje je da li je podstring (uzastopni dio), što nije.

### Ulaz 4
```
1
bac
abcde
```

### Izlaz 4
```
NE
```

### Objašnjenje 4

Slovo `b` se pojavljuje kao drugo slovo u `abcde`, ali slovo `a` se ne pojavljuje nigdje nakon njega. Dakle, `bac` nije podniz od `abcde`.
