# Izbirljivi gosti

U pripremama za JBOI 2026 pozvali ste počasne goste takmičenja. Iako vrijedni za takmičenje, ovi gosti su su dosta izbirljivi po pitanju sobe u kojoj žele biti i insistiraju na to da budu u jednoj od dvije sobe koje odaberu, ili neće nikako doći. 

Ipak, kako imaju barem malo razumjevanja prema vama kao organizatorima, nije im problem da prelaze između te dvije sobe koliko god puta je to potrebno.

Kako dolazi svaki od $N$ gostiju govore vam svoje preferencije za sobe i vi ih raspoređujete. Gost $i$ vam govori svoje preferirane sobe $A_i$ i $B_i$, a vi ih smještate po sljedećim pravilima:
1. Ako je soba $A_i$ slobodna smjestit ćete ih u tu sobu;
2. Ako je soba $B_i$ slobodna smjestit ćete ih u tu sobu;
3. Probate gosta koji je već u $A_i$ premjestiti u njihovu alternativnu sobu, a ako je ona zauzeta probate to uraditi i sa gostom u toj zauzetoj sobi i sve tako dok ne uspijete smjestiti novog gosta ili dođete do prethodno posjećene sobe. Ako ne uspijete, probate iduće pravilo;
4. Probate gosta koji je već u $B_i$ premjestiti u njihovu alternativnu sobu, a ako je ona zauzeta probate to uraditi i sa gostom u toj zauzetoj sobi i sve tako dok ne uspijete smjestiti novog gosta ili dođete do prethodno posjećene sobe. Ako ne uspijete, probate iduće pravilo;
5. Odustajete i odbijete gosta $i$.

Za svakog novog gosta potrebno je odrediti da li ćete ih moći primiti.

_Napomena:_ Kako ulazni podaci mogu biti vrlo veliki preporučujemo da koristite `ios_base::sync_with_stdio(0);` i `cin.tie(NULL);` na početku `main()` funkcije programa.

## Ulazni podaci
Prvi red se sastoji od dva cijela broja razdvojena razmakom $N$ i $M$, broj gostiju i broj soba, redom.

Idućih $N$ redova sadrže dva cijela broja razdvojena razmakom $A_i$ i $B_i$, preferirane sobe za gosta $i$.

### Ograničenja
$1 \leq N, M \leq 300\;000$

$1 \leq A_i, B_i \leq M$

$A_i \neq B_i$

## Podzadaci

### Podzadatak 1 (7 bodova)
$A_i = 1$ za svako $i \in [1,N]$

### Podzadatak 2 (32 boda)
$N, M \leq 100$

### Podzadatak 3 (25 bodova)
$N, M \leq 3000$

### Podzadatak 4 (36 bodova)
Bez dodatnih ograničenja.

## Izlazni podaci
Za svakog gosta potrebno je, u odvojenom redu, ispisati `DA` ako ih prateći opisana pravila možete primiti ili `NE`, u suprotnom.

## Primjeri
### Ulaz 1
```
5 5
1 3
1 2
1 3
1 4
1 3
```
### Izlaz 1
```
DA
DA
DA
DA
NE
```
### Objašnjenje 1
Prvog gosta smještamo u sobu 1. Drugog gosta smještamo u sobu 2. Trećeg gosta smještamo u sobu 3. Četvrtkog gosta smještamo u sobu 4. Petog gosta ne možemo smjestiti.

### Ulaz 2
```
10 5
5 1
2 3
5 2
3 2
5 1
2 1
5 3
2 3
4 3
3 5
```
### Izlaz 2
```
DA
DA
DA
DA
NE
NE
NE
NE
DA
NE
```

