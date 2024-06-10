# MŠ Pejnt	
Hamo i Zijo igraju se igre u programu MŠ Pejnt. Podlogu ovog programa možemo predstaviti kao 2D koordinatni sistem. Prije početka igre, nacrtali su N pravougaonika čije su stranice paralelne koordinatnim osama.

Igra se igra na sljedeći način: prvo Hamo odabere neki od pravougaonika i oboji ga. U nastavku igrači igraju naizmjenično. Igrač u svom potezu mora obojiti neki pravougaonik, ali samo pod uslovom da preklapa neki pravougaonik koji je prije bio obojen. Za dva pravougaonika kažemo da se preklapaju ukoliko je površina njihovog presjeka pozitivna. Nije dovoljno da se dva pravougaonika dodiruju po vrhu ili ivici da bi se preklapala. Ukoliko igrač ne može obojiti nijedan pravougaonik (jer ne postoji pravougaonik koji zadovoljava opisani uslov), on gubi igru. Igrač u svom potezu mora obojiti neki pravougaonik ako može (drugim riječima, ne smije odustati od igre dok zaista ne izgubi).

Ukoliko su vam date pozicije svih `N` pravougaonika, vaš zadatak je odrediti koliko poteza igra može najmanje i najviše trajati. Drugim riječima, kad se pogledaju svi mogući ishodi igre, koji je najmanji broj poteza nakon kojeg igra završi u nekom ishodu, a koji najveći?

Nijedan igrač ne može odustati od igre prije nego što dođe u situaciju da nema šta odigrati.

## Ulaz
Prva linija na ulazu sadrži pozitivan cijeli broj `N` koji označava broj pravougaonika koje su Hamo i Zijo nacrtali.

U sljedećih `N` linija nalaze se po 4 cijela broja `a`, `b`, `c`, `d`. `(a,b)` predstavlja koordinate lijevog donjeg ćoška pravougaonika, dok `(c,d)` predstavlja koordinate gornjeg desnog ćoška pravougaonika.

### Ograničenja
```
1 <= N <= 5 000
0 < a, b, c, d < 100 000 000
a < c
b < d
```
- Podzadatak 1 (3 boda) - `N = 1`
- Podzadatak 2 (18 bodova) - `N = 2`
- Podzadatak 3 (24 boda) - `N = 3`
- Podzadatak 4 (55 bodova) - bez posebnih ograničenja

## Izlaz
Izlaz sadrži jednu liniju koja sadrži dva broja odvojena razmakom. Prvi broj je minimalni broj poteza koji se mogu odigrati u igri, dok je drugi broj maksimalni broj poteza koji se mogu odigrati u igri.

## Primjeri
### Ulaz 1
```
2
1 1 10 10
30 30 40 40
```
### Izlaz 1
```
1 1
```
### Objašnjenje 1
Obzirom da se pravougaonici ne preklapaju, šta god Hamo obojio u prvom potezu, Zijo ne može obojiti ništa, tako da igra uvijek traje samo 1 potez.

### Ulaz 2
```
2
1 1 10 10
1 1 20 20
```
### Izlaz 2
```
2 2
```
### Objašnjenje 2
Koji god pravougaonik Hamo obojio u prvom potezu, Zijo može obojiti drugi, tako da igra uvijek traje tačno 2 poteza.

### Ulaz 3
```
3
1 1 5 5
2 2 4 4
10 10 20 20
```
### Izlaz 3
```
1 2
```
### Objašnjenje 3
Ako Hamo u prvom potezu oboji neki od prva dva pravougaonika, Zijo može obojiti onaj od ta dva koji nije obojio Hamo, te igra završava nakon dva poteza. Ako Hamo u prvom potezu oboji treći pravougaonik, Zijo nema opcija te se igra završava nakon jednog poteza. Igra ni u jednom slučaju ne može trajati tri poteza.