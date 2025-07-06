# Skrivena poruka

Hamo je vrsni pisac kratkih priča, te voli stavljati skrivene poruke u svoje priče. Ahmo misli da će Hamo staviti skrivenu poruku u priču tako što će prva slova svih riječi koja počinju sa velikim slovom nešto ispisati.

Vaš zadatak je napisati program koji će ovu skrivenu poruku razotkriti. Ako nema skrivene poruke (nijedna riječ ne počinje sa velikim slovom) potrebno je ispisati "NEMA" (bez navodnika).

## Ulazni podaci

Prvi red ulaza sadrži $N$, broj riječi u isječku Hamine priče.
Drugi red ulaza sadrži N riječi, odvojenih razmakom. Neće biti interpunkcijskih znakova u upisu.

### Ograničenja
$1 \leq N \leq 500$\
Hamo voli kratke riječi, tako da riječi neće biti duže od 7 slova.
Hamo samo koristi velika i mala slova engleske abecede.

## Podzadaci

### Podzadatak 1 (9 bodova)
$N=3$, sve riječi počinju velikim slovom.

### Podzadatak 2 (16 bodova)
$N=3$

### Podzadatak 3 (6 bodova)
Sve riječi počinju velikim slovom.

### Podzadatak 4 (32 boda)
Tačno 1 riječ počinje velikim slovom.

### Podzadatak 5 (37 bodova)
Bez dodatnih ograničenja.

## Izlazni podaci

Potrebno je ispisati skrivenu poruku sačinjenu od početnih slova riječi koje počinju velikim slovom. Ako nema takvih riječi, potrebno je ispisati "NEMA". 

## Primjeri
### Ulaz 1
```
17
Pored toga AMA bAS niko ne zna sta LASER znaci cak ni profesori na Akademiji ili CERNu 
```
### Izlaz 1
```
PALAC
```
### Objašnjenje 1
Riječi sa velikim početnim slovom su "Pored", "AMA", "LASER", "Akademiji" i "CERNu".

### Ulaz 2
```
7
cvrci cvrci cvrcak na cvoru crne smrce
```
### Izlaz 2
```
NEMA
```
### Objašnjenje 2
Nijedna riječ isječka ne počinje velikim slovom.

### Ulaz 3
```
12
Nakon škole Ema Mia i Ana cekaju tramvaj da se vrate kuci
```
### Izlaz 3
```
NEMA
```
### Objašnjenje 3
Riječi sa velikim početnim slovom su "Nakon", "Ema", "Mia" i "Ana".