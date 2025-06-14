# Hoteli

Gosti na JBOI 2026 će biti smješteni u hotelima, a vaš zadatak je da pomognete organizatorima pronaći odgovarajuće hotele. Organizatore zanima, s obzirom na kapacitete hotela, koliko će daleko morati biti najudaljeniji gosti?

Ako su gosti u susjednim hotelima njihova udaljenost je 1, ako je moguće smjestiti sve goste u isti hotel onda će odgovor biti 0. Ako smjestite sve goste u dva hotela sa jednim praznim hotelom između njih odgovor će biti 2.

Zagarantovano je da postoji dovoljno kapaciteta za sve goste.

## Ulazni podaci
Prvi red ulaza sadrži $N$ i $M$, broj hotela u opticaju i broj gostiju, redom. Svi hoteli se nalaze na istoj ulici, jedan do drugog.

Drugi red ulaza sadrži $k_1$, $k_2$, $k_3$, ..., $k_N$, kapacitete hotela.

### Ograničenja
$1 \leq N \leq 100\;000$

$1 \leq M \leq k_1 + k_2 + ... + k_N$

$0 \leq k_1, k_2, ..., k_N \leq 1\;000\;000$

## Podzadaci

### Podzadatak 1 (6 bodova)
Kapacitet svakog hotela je jednak 100.

### Podzadatak 2 (11 bodova)
Odgovor će sigurno biti 0 ili 1.

### Podzadatak 3 (13 bodova)
$N \leq 10$

### Podzadatak 4 (15 bodova)
$N \leq 100$

### Podzadatak 5 (18 bodova)
$N \leq 2\;000$

### Podzadatak 6 (34 boda)
$k_1 + k_2 + ... + k_N \leq 1\;000\;000$

### Podzadatak 7 (3 boda)
Bez dodatnih ograničenja.

## Izlazni podaci
Potrebno je ispisati jedan broj - udaljenost dva najudaljenija hotela koja imaju goste JBOI-a, ako se odaberu hoteli tako da najudaljeniji gosti budu što bliže.


## Primjeri
### Ulaz 1
```
5 20
4 11 15 0 19
```
### Izlaz 1
```
1
```
### Objašnjenje 1
Smještanjem svih gostiju u drugi i treći hotel dobija se najveća udaljenosti između gostiju 1.

### Ulaz 2
```
4 30
20 30 15 30
```
### Izlaz 2
```
0
```
### Objašnjenje 2
Bez obzira na to da li je to hotel broj 2 ili 4, moguće je sve goste smjestiti u isti hotel.

### Ulaz 3 
```
8 50
35 2 5 7 1 2 44 1
```
### Izlaz 3
```
3
```
### Objašnjenje 3
Izborom hotela broj 4 (kapacitet 7) i hotela broj 7 (kapacitet 44) moguće je smjetiti sve goste, a udaljenost između najudaljenijih je 3.
