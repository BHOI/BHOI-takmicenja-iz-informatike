# Kusur
Kompanija za kafe-aparate vas je unajmila da implementirate za njihove aparate algoritam za vraćanje kusura. Naime, njihovi dosadašnji modeli su imali problem sa računanjem kusura zbog toga što su nepravilno koristili računice sa decimalnim vrijednostima (float/double), te zbog toga bi mašina po nekad zaglavila ili vratila pogrešan kusur.

Možete li vi pronaći bolje rješenje ?

Vaš program će primiti osnovne informacije (koliko novca je uplaćeno, koliko košta cijena proizvoda i koje su kovanice dostupne). Sve kovanice su dostupne u neograničenim količinama.

Vaš program treba da ispiše koliko je ukupno kovanica potrebno da bi aprat mogao izbaciti kusur. **Aparat mora da vrati što manje kovanica**.

Također postoji šansa da je nemoguće vratiti kusur. U tom slučaju potrebno je ispisati odgovarajuću poruku (vidjeti sekciju *Izlaz*)

## Unos
U prvoj liniji data su 3 broja: `N U P`.

* `N` - koliko vrsta kovanica aparat posjeduje
* `U` - koliko novca je uplaćeno od korisnika
* `P` - koliko novca košta proizvod

U sljedećoj liniji nalazi se `N` brojeva, **sortiranih** u rastućem poretku, odvojenih razmakom. Oni predstavljaju `Ki`, tačnije, kovanicu i, koja je dostupna aparatu.

### Ograničenja
```
1 <= N <= 50
0.01 <= P <= U <= 100 000.00
0.01 <= Ki <= 1000.0
```
*`U`, `P` i `Ki` su uvijek dati sa dvije decimale.*

*U 40% slučajeva rezultat se može dobiti uzimajući najveće moguće kovanice*

## Izlaz
Na jednoj liniji izlaza ispisati broj koliko je potrebno kovanica da se vrati kusur.

Ukoliko nije moguće vratiti kusur sa datim kovanicama, na ekran ispisati `greska`.

## Primjeri
### Ulaz 1
```
4 1.00 0.10
0.10 0.20 0.25 0.50
```
### Izlaz 1
```
3
```

*Potrebno je vratiti __0.9__ kusura. To se može uraditi sa kovanicama __0.5__, i 2 x __0.2__. U ovom slučaju nismo uzimali samo najveće kovanice redom, te je ovakvih slučajeva u testovima __60%__*
### Ulaz 2
```
4 1.00 0.05
0.10 0.20 0.25 0.50
```
### Izlaz 2
```
3
```

*Potrebno je vratiti __0.95__ kusura. To se može uraditi sa kovanicama __0.5__, __0.25__ i __0.2__. U ovom slučaju smo uzimali najveće kovanice redom, te je ovakvih slučajeva u testovima __40%__.*
### Ulaz 3
```
4 1.00 0.04
0.10 0.20 0.25 0.50
```
### Izlaz 3
```
greska
```

*Potrebno je vratiti __0.96__ kusura sto je nemoguće s ovim kovanicama.*