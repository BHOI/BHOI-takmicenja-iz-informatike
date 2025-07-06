<style>
    .special_table + table, .special_table + table td {
        border: 1px solid black;
        break-inside: avoid;
    }
    .special_table + table td {
        min-width: 1.5cm;
        min-height: 1cm;
        text-align: center;
        padding-top: 0.6cm;
    }
</style>

# XO

*Iks oks* ili *križić kružić* (eng. *tic tac toe*) je jako popularna igra, pogotovo u školskim klupama. U ovom zadatku, dato vam je stanje igre a vi treba da odredite opišete to stanje. Status stanja može biti jedno od:

* **nepravilno** - *nije moguće po pravilima dovesti se u ovakvo stanje igre*
* **x** - *x je na potezu*
* **o** - *o je na potezu*
* **px** - *pobjeda za x*
* **po** - *pobjeda za o*
* **nerijeseno** - *sva polja su popunjena a pobjednika nemamo*

## Pravila igre
*U pitanju su standardna pravila igre. Ukoliko znate pravila možete ovaj dio teksta preskočiti.*

Igra se igra na devet polja poredanih u 3 reda i 3 kolone.

<div class="special_table"></div>
|   |   |   |
|---|---|---|
| . | . | . |
| . | . | . |
| . | . | . |

*Izgled igre na početku. Inače se tačke ne crtaju*

U igri mogu učestvovati uvijek samo 2 igrača. Njima su dodjeljeni znakovi **X** (iks/križić) ili **O** (oks/kružić). Igrači se smjenjuju na potezu postavljajući svoj znak u neko od slobodnih polja. Prvi na potezu je uvijek **X**.

Pobjednik je onaj igrač koji popuni svojim znakom jednu kolonu, jedan red ili jednu od dvije dijagonale.

<div class="special_table"></div>
|   |   |   |
|---|---|---|
| **X** | O | O |
| **X** | X | . |
| **X** | . | O |

*Primjer igre gdje je **X** pobjednik. Inače se tačke ne crtaju.*

## Ulaz
Na ulazu su vam data 3 stringa dužine 3 karaktera. Ovo predstavlja stanje igre. Svi stringovi mogu sadržati samo sljedeće karaktere:

* **X** - na ovo polje je igrač sa **X** odigrao potez.
* **O** - na ovo polje je igrač sa **O** odigrao potez.
* **.** (tačka) - na ovo polje do sad nije niko odigrao potez.

## Izlaz
Na standardnom izlazu ispisati jedno od 6 mogućih stanja igre (detalji su u opisu zadatka):

* nepravilno
* x
* o
* px
* po
* nerijeseno

*Obratite pažnju da ispišete tačno ovako kako piše u tekstu zadatka i to malim slovima.*

## Primjeri
### Ulaz 1
```
...
...
...
```
### Izlaz 1
```
x
```

*Do sad niko nije igrao tako da je __X__ na potezu*
### Ulaz 2
```
OX.
XO.
X.O
```
### Izlaz 2
```
po
```

*__O__ je pobjednik po dijagonali*
### Ulaz 3
```
OX.
.X.
.X.
```
### Izlaz 3
```
nepravilno
```
*Nije moguće da __X__ odigra 3 poteza a __O__ samo jedan*

### Ulaz 4
```
XXX
OOO
...
```
### Izlaz 4
```
nepravilno
```
*Nije moguće da pobjede i __X__ i __O__ jer se igra treba zavržiti nakon pobjede jednog od igrača*