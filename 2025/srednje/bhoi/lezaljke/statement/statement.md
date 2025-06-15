# Ležaljke

U pripremi za odlazak u prirodu sa društvom iz razreda Valida je otišla na izletište i zabilježila pozicije svih $N$ stabala koja su pogodna za ležaljku. Naime, za ležaljku su potrebna dva stabla koja su udaljena ne manje od $L$, a ne više od $H$ centimetara.

Valida će sa vama podijeliti cjelobrojne koordinate stabala $x_i$ i $y_i$, te postaviti $Q$ pitanja u obliku para brojeva $a_i$ i $b_i$, što označava par stabala. Vaš zadatak je napisati program koji će za zadane parove stabala odrediti da li možete postaviti ležaljku između njih.

Stabla su označena brojevima, gdje je prvo upisano stablo označeno brojem $0$, drugo brojem $1$ i tako dalje.

_Napomena_: Pod udaljenost podrazumjeva se Euklidska udaljenost. Za par stabala sa koordinatama $(x_1, y_1)$ i $(x_2, y_2)$ njihova Euklidska udaljenost $d$ je data sljedećom formulom:

$d = \sqrt{(x_1-x_2)^2 + (y_1-y_2)^2}$

## Ulazni podaci
Prvi red ulaza sadrži $N$, broj stabala.

Idućih $N$ redova sadrži $x_i$ i $y_i$, koordinate stabala.

Idući red sadrži brojeve $Q$, $L$ i $H$, broj pitanja, donja i gornja granica za razmak između stabala.

Idućih $Q$ redova sadrži brojeve $a_i$ i $b_i$ koji predstavljaju par stabala. Potrebno je odrediti da li je moguće postaviti ležaljku između stabala $a_i$ i $b_i$.

### Ograničenja
$2 \leq N \leq 10\;000$

$1 \leq x_i, y_i \leq 1\;000$ 

$1 \leq Q \leq 10\;000$

$1 \leq L \leq H \leq 1\;000$

$0 \leq a_i, b_i < N$

## Podzadaci

### Podzadatak 1 (17 bodova)
$N = 2$

$Q = 1$

Stabla sigurno neće biti udaljena tačno $L$ cm ili $H$ cm.

### Podzadatak 2 (35 bodova)
$Q = 1$

### Podzadatak 3 (48 bodova)
Bez dodatnih ograničenja.


## Izlazni podaci
Za svako pitanje sa ulaza potrebno je u odvojenom redu ispisati "DA" ili "NE", u ovisnosti od toga da li je moguće postaviti ležaljku između dva stabla.

## Primjeri
### Ulaz 1
```
2
3 4
1 0
1 5 10
0 1
```
### Izlaz 1
```
NE
```
### Objašnjenje 1
Stabla su udaljena ~4.47, što je manje od donje granice (5). Ovaj primjer odgovara svim podzadacima.

### Ulaz 2
```
6
2 5
3 5
2 4
5 5
0 2
0 6
3 1 3
0 1
2 1
4 5
```
### Izlaz 2
```
DA
DA
NE
```
### Objašnjenje 2
Prvo pitanje se odnosi na stabla na koordinatama $(2, 5)$ i $(3, 5)$. Ona su udaljena tačno 1, što spada u ograničenja.

Drugo pitanje se odnosi na stabla na koordinatama $(2, 4)$ i $(3, 5)$. Ona su udaljena ~1.41, što je između donje granice (1) i gornje granice (3).

Treće pitanje se odnosi na stabla na koordinatama $(0,2)$ i $(0,6)$. Ona su udaljena tačno 4, tako da su predaleko za ležaljke.

Ovaj primjer odgovara podzadatku 3.