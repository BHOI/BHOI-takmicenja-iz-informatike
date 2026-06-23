# Cipele

Tarik je pronašao kutiju punu cipela, ali cipele su promiješane. Svaka cipela ima oznaku zapisanu na njenom đonu, poput *L 42* ili *D 43*. Broj predstavlja veličinu cipele, a slovo označava da li je cipela *D* (desna) ili *L* (lijeva).

Sve cipele su iste osim veličine i toga da li su desne ili lijeve. Tarik treba tvoju pomoć!

Ako ima ukupno $N$ *cipela*, možeš li izračunati *koliko parova cipela* Tarik može da sastavi? Par se sastoji od jedne desne i jedne lijeve cipele iste veličine.

*Napomena*: Jedna cipela se može koristiti samo *jednom* i ne može biti dio dva ili više parova.

## Ulazni podaci

Prvi red se sastoji od prirodnog broja $N$ koji predstavlja broj pojedinačnih cipela koje je Tarik pronašao.

U svakom od narednih redova nalazi se par oznake i broja $X\;A$ koji predstavlja da li je cipela lijeva ili desna $(X)$ i veličinu $(A)$.

### Ograničenja

$0 < N < 1000$.

Veličine cipela su sigurno manje od $45$, odnosno vrijedi $0 < A < 45$. Cipela će uvijek biti ili desna ili lijeva.

## Izlazni podaci

Na jedinoj liniji izlaza potrebno je ispisati broj parova cipela koje je moguće napraviti.

## Bodovanje

Vaš program će biti testiran sa nekoliko testnih primjera, pri čemu svi testni primjeri nose isti broj bodova. Testni primjeri koji se koriste za bodovanje vam nisu unaprijed poznati. Bodove za testni primjer ćete dobiti ako i samo ako na dati ulaz vaš program ispiše *tačno* očekivani izlaz, ništa više i ništa manje.

U 5% testnih primjera vrijedi $N=1$. U narednih 20% testnih primjera vrijedi $N<10$. Za preostalih 75% testnih primjera nema dodatnih ograničenja.

## Primjeri
### Ulaz 1
```
5
L 42
D 42
L 34
D 40
L 41
```

### Izlaz 1
```
1
```

### Objašnjenje 1

Od 5 cipela, jedini par koji se može složiti je par veličine 42 (jedna lijeva i jedna desna). Cipele veličine 34, 40 i 41 nemaju odgovarajući par.

### Ulaz 2
```
6
L 38
D 38
L 38
D 38
L 40
D 40
```

### Izlaz 2
```
3
```

### Objašnjenje 2

Postoje dvije lijeve i dvije desne cipele veličine 38, što daje 2 para. Postoji još jedna lijeva i jedna desna cipela veličine 40, što daje 1 par. Ukupno je moguće sastaviti 3 para.

### Ulaz 3
```
4
L 36
L 36
D 37
D 37
```

### Izlaz 3
```
0
```

### Objašnjenje 3

Nema ni jednog para jer postoje samo lijeve cipele veličine 36 i samo desne cipele veličine 37. Nije moguće sastaviti nijedan par.
