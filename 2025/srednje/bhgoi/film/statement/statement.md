# Film

Kao i prošle godine dobijate jedan zadatak o filmovima! Uistinu, kreativnost postavljača zadataka nema granica.

Pitali ste Edvina, vrsnog poznavaoca filmova, koji film bi odabrao ako bi mogao samo gledati jedan film ostatak života?

Edvin vam je samo pokazao svoju listu ocijenjenih filmova i rekao da bi odabrao onaj koji je ocijenio najvišom ocjenom.

Vaš zadatak je napisati program koji će iz liste odrediti koji je to film sa najvišom ocjenom.

_Napomena:_ Iako u tekstu pišemo _decimalni zarez_, u upisu će uvijek tačka odvajati cijeli dio broja od decimalnog. Ovo je standardan način na koji računari predstavljaju decimalne brojeve.

## Ulazni podaci
Prvi red ulaza sadrži $N$, broj filmova u Edvinovoj listi.
Narednih N redova sadrže po string $S_i$ i ocjenu $O_i$, naslov filma i ocjenu koju je Edvin dao tom filmu. 

Naslovi filmova se sastoje samo od velikih i malih slova engleske abecede i neće biti duži od 30 slova, a ocjene će biti decimalni brojevi sa preciznosti do 2 cifre iza decimalnog zareza.

Svi naslovi i sve ocjene filmova su različite.

### Ograničenja
$1 \leq N \leq 1000$

$0.00 \leq O_i \leq 10.00$

## Podzadaci

### Podzadatak 1 (7 bodova)
Edvin je već (donekle) poredao listu! Prvi film liste je ujedno i najbolje ocjenjen.

### Podzadatak 2 (17 bodova)
$N = 3$

### Podzadatak 3 (17 bodova)
$N \leq 8$

### Podzadatak 4 (12 bodova)
Edvin je sigurno ocijenio barem jedan film sa savršenom ocjenom i tačno će je napisao kao `10`.

### Podzadatak 5 (33 boda)
Svaku ocjenu je napisao sa tačno 2 cifre nakon decimalnog zareza, čak i ako nisu nužne (npr. neće pisati `8.4` ili `5`, već `8.40` ili `5.00`).

### Podzadatak 6 (14 bodova)
Bez dodatnih ograničenja.

## Izlazni podaci

Potrebno je samo ispisati naslov filma sa najboljom ocjenom. 

## Primjeri
### Ulaz 1
```
3
Shrek 9
Shrek2 10
Shrek4 7.5
```
### Izlaz 1
```
Shrek2
```
### Objašnjenje 1
Sa savršenom ocjenom, Shrek2 je najbolje ocjenjeni film sa liste.\
Ovaj primjer odgovara podzadacima 2, 3, 4 i 6.

### Ulaz 2
```
5
TheThing 9.27
TheBigLebowski 9.12
PulpFiction 9.01
StarshipTroopers 8.92
ReservoirDogs 8.99
```
### Izlaz 2
```
TheThing
```
### Objašnjenje 2
Ovaj primjer odgovara podzadacima 1, 3, 5 i 6.