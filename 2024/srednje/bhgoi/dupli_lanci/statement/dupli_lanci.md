# Dupli Lanci

Veliki čarobnjak Gandalf vam je dao zadatak da što većem broju naselja u Bosni i Hercegovini napravite poseban ukras.

Po njegovom savjetu ti ukrasi će biti parovi lanaca. Svaki lanac je dužine `N` se sastoji od crvenih i plavih karika. Na jednom od lanaca će vrijediti da je između dvije crvene karike (ako ih uopšte stavite) barem `K` plavih karika. Drugi lanac je drugačiji i on mora kršiti ovo pravilo.

Želite da svaki lanac koji napravite je jedinstven. Na lancima su označeni početak i kraj, tako da lanci `CP` i `PC` su drugačiji lanci, gdje C i P predstavljaju crvene i plave karike, redom.

Za zadanu dužinu lanca `N` i razmaka `K` vaš zadatak je odrediti koliko ovakvih parova lanaca možete napraviti. Pošto odgovor može biti vrlo velik, potrebno je ispisati ostatak pri djeljenju ovog broja sa `1000000007` (milijardu i sedam).

## Ulazni podaci

Prvi i jedini red ulaza sadrži dva broja, N i K, iz opisa zadatka, razdvojeni razmakom.

### Ograničenja
```
0 <= K <= 10^4
K < N <= 10^7
```

***Napomena**: obratite pažnju na vremensko i memorijsko ograničenje zadatka.*

## Podzadaci

### Podzadatak 1 (4 boda)
`1 <= K < N <= 3`

### Podzadatak 2 (22 bodova)
`5 <= K < N <= 20`

### Podzadatak 3 (10 bodova)
`0 <= K < N <= 20`

### Podzadatak 4 (22 bodova)
`0 <= K < N <= 10^4`

### Podzadatak 5 (42 bodova)
Bez dodatnih ograničenja.

## Izlazni podaci

Potrebno je ispisati jedan broj, ostatak pri djeljenju broja M sa milijardu i sedam.

## Primjeri
### Ulaz 1
```
3 1
```
### Izlaz 1
```
3
```
### Objašnjenje 1
Postoji ukupno 8 mogućih lanaca. Od njih, 5 prati pravilo (PPP, PPC, PCP, CPP, CPC), dok ostala 3 ga ne prati (PCC, CCP, CCC). Tako da je moguće napraviti maksimalno 3 para lanaca, poštujući pravila zadatka.

### Ulaz 2
```
20 19
```
### Izlaz 2
```
21
```
### Objašenjenje 2
Samo lanci sa 0 ili 1 crvenom karikom poštuju pravilo, a takvih lanaca je 21. Lanaca koji ne poštuju pravilo je više, tako da je moguće napraviti 21 par lanaca po opisu zadatka.

## Primjer 3
### Ulaz 3
```
8000 6
```
### Izlaz 3
```
621198682
```
## Primjer 4
### Ulaz 4
```
7654321 1234
```
### Izlaz 4
```
735435034
```