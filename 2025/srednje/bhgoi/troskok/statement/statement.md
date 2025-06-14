# Troskok

Kada dođe ljeto, nekada nam može biti malo dosadno, ako je napolju previše vruće, a u kući nemamo mnogo šta da radimo. Luni - isto tako.
Zato, kada se igra sa Anđelom, voli da se penje (ili silazi) sa njene penjalice. Igra je poprilično jednostavna: Ako počne na penjalici visine $h_i$, onda mora da izabere još dvije penjalice $h_j$ i $h_k$, takve da važi $0 \  \leq \ i \ \lt \ j \ \lt \ k \ \lt \ N$ (gdje je $N$ broj penjalica), te $h_i \ \gt \ h_j \gt \ h_k$ ili $h_i \ \lt \ h_j \ \lt \ h_k$.
Dakle, visine penjalica moraju da striktno opadaju ili striktno rastu.

Anđela je poredala N penjalica raznih (unikatnih) veličina i planira da se čitavo poslijepodne igra sa Lunom. Možete li im pomoći i odgovoriti na pitanje: Koliko postoji različitih trojki $(i,\ j,\ k)$, koje zadovoljavaju gorepomenute uslove?

Pošto odgovor može biti vrlo velik potrebno je ispisati njegov ostatak pri djeljenju sa $10^9+7$ (milijardu i sedam).

## Ulazni podaci
Prvi red ulaza sadrži $N$, broj penjalica.\
Drugi red ulaza sadrži $N$ vrijednosti $h_i$ ($0 \ \leq \ i \ \lt \ N$), visine penjalica.

### Ograničenja
$3 \leq N \leq 10^{4}$\
$1 \leq h_i \leq 10^{4}$

## Podzadaci

### Podzadatak 1 (22 boda)
$N \ \leq \ 250$

### Podzadatak 2 (32 boda)
$N \ \leq \ 1000$

### Podzadatak 3 (46 bodova)
Bez dodatnih ograničenja.

## Izlazni podaci
Potrebno je ispisati koliko različitih trojki $(i,\ j,\ k)$ postoji, koji ispunjavaju gorepomenute uslove. Imajte na umu da se jedna penjalica može naći u više trojki, i da ne moraju nužno sve trojke (u kojima se ta jedna penjalica pojavi) biti rastuće ili opadajuće - bitno je samo da je jedan od uslova ispunjen.

## Primjeri
### Ulaz 1
```
5
1 5 2 3 4
```
### Izlaz 1
```
4
```
### Objašnjenje 1
Postoje $4$ validne trojke: $(1,\ 2,\ 3)$, $(1,\ 2,\ 4)$, $(1,\ 3,\ 4)$, $(2,\ 3,\ 4)$.\
Pomenute trojke koriste vrijednosti, a ne indekse, radi jednostavnosti razumijevanja.

### Ulaz 2
```
3
2 1 3
```
### Izlaz 2
```
0
```
### Objašnjenje 2
Ne postoji ni jedna trojka tako da su vrijednosti rastuće ili opadajuće.