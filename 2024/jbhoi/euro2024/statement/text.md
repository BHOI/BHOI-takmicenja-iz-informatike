# Euro 2024

EMF Euro 2024 je prvenstvo u mininogometu/minifudbalu koje se održava u Sarajevu (upravo danas se igra finale!). U duhu ovog sporta, vaš zadatak će biti da od rezultata utakmica između klubova jedne lige odredite poredak i brojeve bodova svih ekipa.

Pravila su sljedeća:
- Bit će vam dati rezultati utakmica u formatu `tim_a - tim_b : rezultat_a - rezultat_b`, gdje `tim_a` i `tim_b` predstavljaju imena timova, a `rezultat_a` i `rezultat_b` predstavljaju brojeve golova koje su ovi timovi postigli u toj utakmici. Također, ovo znači da je utakmica odigrana na domaćem stadionu tima `tim_a` (onog koji je napisan lijevo od drugog tima).
- Ako jedan tim u utakmici ima više golova od drugog on je pobjedio, dok je drugi tim izgubio. Ako je broj golova jednak onda su oba tima izjednačila.
- Ukoliko jedan tim pobjedi, a drugi izgubi onda tim koji je pobjedio dobija **3** boda za tu utakmicu, a tim koji je izgubio ne dobija bodove (dobija **0** bodova). Ako je utakmica završila izjednačenjem oba tima dobijaju po **1** bod.
- Timovi se rangiraju prvobitno po bodovima - tim sa više bodova je na višem mjestu.
U slučaju da neki timovi završavaju sa izjednačenim bodovima onda se njihov poredak rješava na sljedeće načine, i to u datom redoslijedu (prvo se načinom 1, zatim načinom 2, itd.)

1. U slučaju izjednačenja po bodovima tim sa boljom tzv. "gol razlikom" ima prednost. Gol razlika je razlika ukupnog broja postignutih i primljenih golova u svim utakmicama do sada. Dakle ako je tim `X` igrao **2** utakmice, gdje je prvu pobjedio **3-1** (dali 3 gola a primili 1), a drugu izgubio **4-0** (dali 0 golova a primili 4) njegova gol razlika je **-2** (manja je od 0).
2. U slučaju izjednačenja i po tom kriteriju prednost ima tim koji je više golova postigo ukupno. Ako timovi **X** i **Y** oba imaju isto bodova i istu gol razliku, ali tim **X** je ukupno postigo 13 golova i primio 10, dok je tim **Y** postigo 11 golova i primio 8 onda tim **X** ima prednost.
3. U slučaju izjednačenja i po tom kriteriju posmatraju se utakmice direktno između ta 2 tima (ako postoje). Tim koji je stekao više bodova u direktnim utakmicama između ta dva tima ima prednost.
4. U slučaju izjednačenja i po tom kriteriju prednost ima tim koji je više golova postigo u domaćem stadionu suprotnog tima (dakle "u gostima").

U slučaju da su dva tima izjednačena po svim ovim kriterijima potrebno je da timovi odigraju direktnu utakmicu između ovih timova. U ovom slučaju nije potrebno ispisati poredak timova, već je potrebno samo ispisati `Potrebno je razigravanje!`.

Zadatak će biti bodovan tako što je testiran na više primjera. U nekim primjerima svi timovi imaju različite brojeve bodova, u ostalim će se morati primjenjivati pravila za rješavanje izjednačenja ili čak će biti potrebno razigravanje. 

## Ulazni podaci
- Prvi red ulaza sadrži `T`, broj timova.
- Drugi red ulaza sadrži `T` naziva timova (razdvojeni razmakom) koji se sastoje od malih i velikih slova engleske abecede, te donje crte (`_`)
- Idući red ulaza sadrži `U`, broj utakmica koje su do sada odigrane u ligi.
- Idućih `U` redova ulaza sadrži format `tim_a - tim_b : rezultat_a - rezultat_b` koji opisuju utakmicu, gdje `tim_a` i `tim_b` predstavljaju imena timova, a `rezultat_a` i `rezultat_b` predstavljaju brojeve golova koje su ovi timovi postigli u toj utakmici. 

### Ograničenja
```
1 < T < 100
0 < U < 200
Imena timova neće biti duža od 20 karaktera
```

## Izlazni podaci
Ukoliko je potrebno razigravanje potrebno je samo ispisati `Potrebno je razigravanje!` (pazite na velika, mala slova, razmake i uzvicnik, morate ispisati tacno ovako kako je napisano).
U suprotnom, potrebno je u odvojenim redovima ispisati imena svih timova, poredanih od tima na vrhu tabele do tima na dnu tabele. Pored imena timova je potrebno ispisati broj bodova tog tima (odvojeno razmakom od imena tima).

## Primjeri
### Ulaz 1
```
4
A B C D
10
A - B : 5 - 1
B - A : 1 - 2
A - C : 0 - 2
C - B : 1 - 3
B - A : 2 - 1
D - A : 1 - 1
D - C : 2 - 2
C - D : 3 - 1
B - D : 2 - 4
A - D : 0 - 0
```
### Izlaz 1
```
A 8
C 7
D 6
B 6
```
### Objašnjenje 1
| Ime | Bodovi | Gol razlika | Golovi na domacem terenu | Golovi na gostujucem terenu | Ukupno golova |
|-----|--------|-------------|--------------------------|-----------------------------|---------------|
| A | 8 | 2 | 5 | 4 | 9 |
| C | 7 | 2 | 4 | 4 | 8 |
| D | 6 | 0 | 3 | 5 | 8 |
| B | 6 | -4 | 5 | 4 | 9 |

Tim `D` je ispred tima `B` jer ima bolju gol razliku.

#### Bodovi tima `A`
Tim `A` ima **8** bodova na sljedeći način:
- `3` boda   za meč `A - B : 5 - 1`
- `3` boda   za meč `B - A : 1 - 2`
- `0` bodova za meč `A - C : 0 - 2`
- `0` bodova za meč `B - A : 2 - 1`
- `1` bod    za meč `D - A : 1 - 1`
- `1` bod    za meč `A - D : 0 - 0`
- Ukupni zbir bodova tima `A` je: `3 + 3 + 0 + 0 + 1 + 1 = 8`

#### Bodovi tima `C`
Tim `C` ima **7** bodova na sljedeći način:
- `3` boda za meč `A - C : 0 - 2`
- `0` bodova za meč `C - B : 1 - 3`
- `1` bod za meč `D - C : 2 - 2`
- `3` boda za meč `C - D : 3 - 1`
- Ukupni zbir bodova tima `C` je: `3 + 0 + 1 + 3 = 7`

#### Gol razlika tima `D`
Tim `D` ima gol razliku **0** na sljedeći način:
- `0` za meč `D - A : 1 - 1`
- `0` za meč `D - C : 2 - 2`
- `-2` za meč `C - D : 3 - 1`
- `2` za meč `B - D : 2 - 4`
- `0` za meč `A - D : 0 - 0`
- Ukupni zbir za gol razliku tima `D` je: `0 + 0 + -2 + 2 + 0 = 0`

#### Gol razlika tima `B`
Tim `B` ima gol razliku **-4** na sljedeći način:
- `-4` za meč `A - B : 5 - 1`
- `-1` za meč `B - A : 1 - 2`
- `2` za meč `C - B : 1 - 3`
- `1` za meč `B - A : 2 - 1`
- `-2` za meč `B - D : 2 - 4`
- Ukupni zbir za gol razliku tima `B` je: `-4 + -1 + 2 + 1 + -2 = -4`