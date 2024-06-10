# MS Kalkulator
Jedna od neprocenjivih inovacija koja je postala dostupna na javnom tržištu u ranim 70-tim je
upravo izum koji je danas daleko prevaziđen, a to je džepni kalkulator. Glavni doprinos ovoj
inovaciji je razvoj prvog intelovog mikropocesora – intel 4004 koji se koristio u ovoj liniji
proizvodnje prvih kalkulatora.

Jedna od posebnih vrsta kalkulatora, koja se proizvodila u to vrijeme jeste MSKalkulator od
strane kompanije Megasoft. MSKalkulator je imao ekran koji je prikazivao sve cijele brojeve u
granici od *[0, 10<sup>9</sup> + 6]* i podržavao samo jednu operaciju, operaciju množenja. Ukoliko bi
prilikom izvršavanja ovih operacija rezultat izašao izvan granica opsega ekrana, on bi bio
odsečen po modulu 10<sup>9</sup> + 7 radi prikazivanja (1000000006 ∗ 2 = 1000000005).

Profesor Filip, koji se tada bavio testiranjem ovih specijalnih kalkulatora, primjetio je čudan
fenomen rada koji je bio direktno povezan sa ovom vrstom mikroprocesora. Ukoliko bi smanjio
temperaturu unutar sobe ispod -10 °C , kalkulator bi zamijnio sve operacije množenja sa
operacijama stepenovanja.

Testiranje se obavljalo u posebnoj prostoriji u kojoj je bilo podešeno konstantnih -20 °C , dok
je profesor Filip izvršavao niz operacija množenja na kalkulatoru. Kako je boravak u toliko
hladnoj prostoriji prenaporan za profesora, on je mogao __najviše jednom__ da napravi pauzu i da
napusti sobu. Tokom svoje pauze mogao je ponijeti kalkulator sa sobom i izvršiti __najviše jednu__
operaciju množenja na kalkulatoru (pod normalnim temperaturnim uslovima).

Recimo da profesor Filip izvršava slijedeće operacije množenja na kalkulatoru gdje je inicijalna
vrijednost 3 prikazana na ekranu: 2, 2, 3. Ukoliko je profesor odlučio da odradi sve operacije
unutar test-prostorije, kalkulator bi sve operacije izračunao kao operacije stepenovanja i
dobio bi ((3<sup>2</sup>)<sup>2</sup>)<sup>3</sup> = 531441. Ukoliko bi profesor odlučio da izađe van prostorije tokom
izračunavanja druge operacije, ona bi se računala kao regularno množenje dok bi ostale dvije
morao uraditi unutar test-prostorije, te bi one bile računate kao stepenovanje. U tom slučaju
rezultat nakon izvršenih operacija bi bio: (3<sup>2</sup> ∗ 2)<sup>3</sup> = 5832.

Pomozite profesoru Filipu da odredi najveći mogući broj koji bi mogao vidjeti na ekranu.

## Ulaz
Prvi red ulaza sadrži pozitivan cijeli broj `N`, i cijeli broj `K` koji
predstavljju broj operacija množenja i početni broj na kalkulatoru, respektivno.
Drugi red ulaza sadrži niz od `N` cijelih brojeva `a[i]` razdvojenih blanko znacima (razmacima),
koji predstavljaju unesene brojeve u kalkulator.
### Ograničenja
```
1 <= N <= 100 000
0 <= K, a[i] <= 1 000 000 000
```

* Podzadatak 1 (5 bodova): `1 <= N <= 10` i `1 <= а[i] <= 100 000`
* Podzadatak 2 (20 bodova): `1 <= N <= 1000`
* Podzadatak 3 (75 bodova): Bez dodatnih ograničenja

## Izlaz
Najveći mogući broj koji bi profesor mogao vidjeti.

## Primjeri
### Ulaz 1
```
2 100
100 100
```
### Izlaz 1
```
794576212
```

*Profesor je mogao da ode ne pauzu tokom prvog množenja, pa bi imao situaciju:*

**(100 ∗ 100)<sup>100</sup> (𝑚𝑜𝑑 10<sup>9</sup> + 7)**

### Ulaz 2
```
3 2
3 2 3
```
### Izlaz 2
```
262144
```

*Najveći broj bi se dobio ukoliko profesor ne bi otišao na pauzu:*

**((2<sup>3</sup>)<sup>2</sup>)<sup>3</sup> (𝑚𝑜𝑑 10<sup>9</sup> + 7)**