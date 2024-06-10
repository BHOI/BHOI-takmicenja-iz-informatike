# Čestice
U bosanskohercegovačkim laboratorijama BiHLAB otkrivena je nova subatomska čestica, zagradon, koja se u prirodi pojavljuje sa jednom od dvije moguće orijentacije, lijevom ili desnom. Pored toga, zagradon se u svakom trenutku nalazi u jednom od tri energetska stanja: oblom, uglastom ili vitičastom.

Ovisno o energetskom stanju, bosanskohercegovački fizičari lijevo orijentisane zagradone obilježavaju redom znakovima *"\("*, *"\["* i *"\{"*, a desno orijentisane znakovima *"\)"*, *"\]"* i *"\}"*.

Kako bi proučavali te čestice, fizičari ih organizuju u nizove \(npr. *"(\[\}\)\{\]\["*), pri čemu je veoma važno da niz bude "smislen", tj. da se zagradoni u nizu mogu podijeliti u parnjake istog energetskog stanja, od kojih je onaj koji se u nizu pojavljuje ranije lijevo orijentisan, a drugi desno orijentisan, te između kojih se nalazi dio niza koji je ili prazan ili i sam smislen. (Spomenuti dio niza je kraći od originalnog pa definicija smislenog niza nije cirkularna.) Primjer smislenog niza je *"\(\[\]\{\[\]\}\)\{\}"*, a nesmislenog su *"\]\["* i *"\[\(\]\)"*.

Zagradoni se u prirodi nažalost rijetko pojavljuju u smislenim nizovima, ali srećom, stručnjaci u BiHLAB-u posjeduju uređaj zvani modifikator, uz pomoć kojeg je moguće promijeniti energetsko stanje jednog zagradona u bilo koje od ostala dva stanja (ali ne promijeniti njegovu orijentaciju). Njihov modifikator ima kapacitet da izvrši `K` operacija promjene stanja čestice. Međutim, zbog nestabilnosti subatomskih čestica proces nije moguće prekinuti nakon pokretanja te on mora izvršiti tačno `K` operacija u nizu, pri čemu se na svakom pojedinačnom zagradonu promjena može izvršiti najviše jedanput!

Vaš program treba moći učitati niz zagradona i odrediti je li moguće pretvoriti ga u smislen niz (jednom) upotrebom modifikatora. Budućnost bosanskohercegovačke kvantne fizike ovisi o vama!

## Ulaz
* Prva linija na ulazu sadrži cijele brojeve `N` i `K`.
* Druga linija na ulazu sadrži niz zagradona dužine `N`.

### Ograničenja
```
0 <= K <= N
2 <= N <= 200000
```

### Podzadaci
- Podzadatak 1 (20 bodova) - `N <= 20` 
- Podzadatak 2 (10 bodova) - `K = 1`
- Podzadatak 3 (30 bodova) - `N <= 20000`
- Podzadatak 4 (40 bodova) - nema daljih ograničenja.

## Izlaz
Jedina linija izlaza sadrži samo jedan string. Ako niz nije moguće učiniti smislenim primjenom tačno  operacija na različitim mjestima, taj string treba biti `nemoguce`.

Ako je moguće izvršiti takvu modifikaciju niza, taj string treba biti bilo koja smislena modifikacija koja odgovara opisu.

## Primjeri
### Ulaz 1
```
2 2
()
```
### Izlaz 1
```
[]
```
### Ulaz 2
```
4 2
({)}
```
### Izlaz 2
```
({})
```
### Ulaz 3
```
6 2
(((]]]
```
### Izlaz 3
```
nemoguce
```