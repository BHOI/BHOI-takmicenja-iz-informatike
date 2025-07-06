# Lunine Gumice za Kosu

Luna obožava da se igra! Njena vlasnica Anđela odlučila je da joj napravi malu igru sa njenim ubjedljivo omiljenim predmetom ikada - gumicama za kosu!
Igra je veoma jednostavna - Luna kreće od svog malog kreveta, posjećuje dijelove kuće i na kraju će završiti iza računara - tamo najviše voli da krije gumice za kosu. Između dva mjesta će se nalaziti neki broj gumica za kosu, koje Luna može da pokupi.

No, kako Anđela jako mnogo voli svoju mačku, jednostavno mora da joj malo olakša i nagradi je za svo to kretanje - umjesto da se Lunine gumice sabiraju, one se množe! Dakle, ako Luna između mjesta $A$ i $B$ pokupi $x$ gumica, a između $B$ i $C$ pokupi $y$ gumica, onda je Luna ukupno pokupila $x\ \cdot \ y$ gumica za kosu.

Formalno, Anđelina kuća predstavljena je kao neusmjereni graf sa $N$ čvorova i $E$ grana. Na svakoj grani postoji vrijednost u intervalu $\left[0,\ 1\right]$, na primjer: $0.2$, $0.75$, $0$, $1$. Luna kreće iz početnog čvora $K$ (krevet), te završava svoj put na završnom čvoru $R$ (računar), a vrijednosti na granama koje iskoristi za svoje kretanje, množe se i računaju u finalni rezultat.

Luna je tražila vašu pomoć - koliko najviše gumica može da sakupi, ako se kreće optimalno od čvora $K$, do čvora $R$. \
Budite precizni - Luna ne voli da dobije manje gumica nego očekivano (inače će biti JAKO ljuta)!

_Napomena_: Možda vam izgleda kao da Luna dobija malo gumica, ili čak dijelove istih, ali to je zato što su brojevi namjerno smanjeni - zapravo ih dobija makar 10 puta više!

## Ulazni podaci

Prvi red ulaza sadrži brojeve $N$ i $E$ - broj čvorova i broj grana. \
Narednih $E$ redova sadrži tri vrijednosti - $u$, $v$ i $g$, koje govore da postoji dvosmjerna grana između čvorova $u$ i $v$, na kojoj se nalazi $g$ gumica za kosu. \
Posljednji red ulaza sadrži brojeve $K$ i $R$ - početni i završni čvor.

### Ograničenja
$2 \ \leq \ N \ \leq \ 10^{4}$ \
$0 \ \leq \ E \ \leq \ 2 \ * \ 10^{4}$ \
$0 \ \leq \ u, \ v \ \lt \ N,\ u \neq \ v$ \
$0 \ \leq \ g \ \leq \ 1$

## Podzadaci

### Podzadatak 1 (42 bodova)
$2 \ \leq \ N \ \leq \ 10$ \
$0 \ \leq \ E \ \leq \ 45$ \

### Podzadatak 3 (58 boda)
Bez dodatnih ograničenja.

## Izlazni podaci

Potrebno je ispisati maksimalnu vrijednost gumica za kosu koje Luna moze da osvoji.
Rješenje će se smatrati tačnim ako se razlikuje od zvaničnog rješenja za najviše $10^{-5}$.

## Primjeri
### Ulaz 1
```
3 3
0 1 0.5
1 2 0.5
0 2 0.2
0 2
```
### Izlaz 1
```
0.25000
```
### Objašnjenje 1
Luna ima dva u opticaju dva moguća puta:
- Put: $0 \to \ 2$, na kojem nailazi na $0.2$ gumice za kosu.
- Put: $0 \to 1 \to \ 2$, na kojima nailazi prvo na $0.5$, a onda opet na $0.5$ gumice. \
Ukupna vrijednost: $0.5 \ \cdot \ 0.5 \ = \ 0.25$.

### Ulaz 2
```
3 1 
0 1 1
0 2
```
### Izlaz 2
```
0.00000
```
### Objašnjenje 2
Luna, nažalost, ne može da dođe od svog kreveta (čvor $0$) do računara (čvor $2$), te će ukupno dobiti $0$ gumica.