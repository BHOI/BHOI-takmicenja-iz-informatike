# Lego
Bego mnogo voli Lego kockice i upravo je kao poklon dobio ogroman set Lego kockica. Ovaj set ima 26 vrsta Lego kockica koje možemo predstaviti kao mala slova engleske abecede. Čitav set možemo predstaviti kao niz malih slova engleske abecede. Bego želi da napravi svoju omiljenu figuru koristeći ovaj set Lego kockica. Njegovu figuru također možemo predstaviti kao niz malih slova engleske abecede. Bego će redom tražiti u setu kockice koje mu trebaju za njegovu figuru, i ukoliko pronađe dovoljan broj svake vrste kockica, napravit će svoju figuru. On želi napraviti što je više moguće ovih figura. Vaš zadatak je odrediti koliko će Bego moći napraviti njemu omiljenih lego figura.
## Ulaz
Prva linija inputa sadrži string koji će se sastojati isključivo od malih slova engleske abecede. Ovaj string predstavlja opis čitavog seta Lego kockica. Svaki karakter predstavlja tip kockice.
Druga linija outputa sadrži string koji će se sastojati isključivo od malih slova engleske abecede. Ovaj string predstavlja opis Begine omiljene Lego figure.
Oba stringa će biti dužine ne veće od 105.
## Izlaz
Trebate ispisati koliko će Bego moći napraviti njemu omiljenih figura koristeći novi set Lego kockica koji je dobio.

## Podzadaci
### Podzadatak 1 (5 bodova)
Oba stringa su identična.
### Podzadatak 2 (11 bodova)
Set Lego kockica ima samo jednu vrstu kockica, a Begina omiljena figura se sastoji također samo od jedne vrste kockica (ne nužno iste vrste kao u setu).
### Podzadatak 3 (14 bodova)
Ukupan broj kockica u setu jednak je broju kockica koji je potreban za Beginu omiljenu figuru.
### Podzadatak 4 (70 bodova)
Nema dodatnih ograničenja.

## Primjeri
### Ulaz 1
```
aaabbbccc
abc
```
### Izlaz 1
```
3
```
### Objašnjejne 1
Bego na raspolaganju ima tačno onoliko kockica svake vrste koliko mu je potrebno da napravi 3 figure.
### Ulaz 2
```
aabc
abd
```
### Izlaz 2
```
0
```
### Objašnjejne 2
Novi set Lego kockica uopšte ne sadrži kockicu tipa d koja je neophodna za Beginu omiljenu figuru, tako da on ne može napraviti niti jednu figuru.
### Ulaz 3
```
azzzabb
zaba
```
### Izlaz 3
```
1
```
### Objašnjenje 3
Nakon što Bego napravi jednu figuru, ponestat će mu figura tipa a, tako da je to jedina figura koju može napraviti.