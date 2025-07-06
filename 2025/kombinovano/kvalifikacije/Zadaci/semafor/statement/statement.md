# Semafor

Isfrustriran problemima sa bespotrebnim saobraćajnim gužvama, gradonačelnik Luka je odlučio uzeti stvari u svoje ruke. Prvo, odlučio je reorganizovati semafore tako da svako zna kada će na semaforu biti zeleno, a kada crveno svijetlo.

Da bi pojednostavio život svojim sugrađanima Luka je sve semafore u gradu promjenio tako da 10 sekundi prikazuju zeleno svijetlo, a 10 sekundi crveno.

Vaš zadatak je da napišete program koji će odrediti koje boje će biti upaljeno svijetlo na semaforu nakon $N$ sekundi, pod pretpostavkom da se svijetlo upravo pretvorilo iz crvenog u zeleno.

## Ulazni podaci

Prvi red ulaza sadrži $N$, broj sekundi za koji se treba odrediti boju svijetla na semaforu.

### Ograničenja
$1 \leq N \leq 10^{18}$

## Podzadaci

### Podzadatak 1 (28 bodova)
$N\leq10$

### Podzadatak 2 (18 bodova)

$N\leq10^9$,\
$N$ će biti djeljivo sa 100

### Podzadatak 3 (47 bodova)
$N\leq10^9$

### Podzadatak 4 (7 bodova)
Bez dodatnih ograničenja.

## Izlazni podaci

Potrebno je ispisati "CRVENO" (bez navodnika) ako će svijetlo biti crveno poslije $N$ sekundi, a "ZELENO" ukoliko će biti zeleno.

## Primjeri
### Ulaz 1
```
5
```
### Izlaz 1
```
ZELENO
```
### Objašnjenje 1
Još se nije promijenilo svijetlo sa zelenog na crveno.

### Ulaz 2
```
10
```
### Izlaz 2
```
CRVENO
```
### Objašnjenje 2
Nakon 10 sekundi svijetlo se promijenilo sa zelenog na crveno.

### Ulaz 3
```
128
```
### Izlaz 3
```
ZELENO
```