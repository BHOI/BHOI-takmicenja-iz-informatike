# Muki Mopac razmjenjuje karte

Muki Mopac ima u ruci $n$ karata, gdje svaka karta ima napisan broj na sebi, i fiksiran cijeli broj $k$. On može izvršiti sljedeću operaciju bilo koji broj puta:

* Izabrati bilo kojih **tačno** $k$ karata iz svoje ruke koje sve imaju isti broj.
* Razmijeniti te karte za $k - 1$ karata, od kojih svaka može imati bilo koji broj koji on izabere (uključujući i broj koji je napisan na kartama koje je upravo razmijenio).

Koji je najmanji broj karata koji Muki Mopac može imati u svojoj ruci na kraju ovog procesa?

## Ulazni podaci

Prvi red se sastoji od dva cijela broja $n$ i $k$: broj karata koje Muki ima i broj karata koje razmjenjuje tokom svake operacije.

Drugi red sadrži $n$ cijelih brojeva $c_1, c_2, \ldots, c_n$:  brojeve napisane na kartama.

### Ograničenja

$1 \le n \le 1000$

$2 \le k \le 100$

$1 \le c_i \le 100$

## Izlazni podaci

Na jedinoj liniji izlaza potrebno je ispisati najmanji broj karata koji Mukiju može ostati u ruci nakon bilo kojeg broja operacija.


## Bodovanje

Vaš program će biti testiran sa nekoliko testnih primjera, pri čemu svi testni primjeri nose isti broj bodova. Testni primjeri koji se koriste za bodovanje vam nisu unaprijed poznati. Bodove za testni primjer ćete dobiti ako i samo ako na dati ulaz vaš program ispiše *tačno* očekivani izlaz, ništa više i ništa manje.

## Primjeri

### Ulaz 1
```
5 3
4 1 1 4 4
```

### Izlaz 1
```
2
```

### Objašnjenje 1

Muki ima tri karte s brojem 4. Može ih zamijeniti za $k - 1 = 2$ nove karte. Bira da obje nove karte imaju broj 1. Sada ima u ruci: $1, 1, 1, 1$ (četiri jedinice). Zatim zamjenjuje tri od četiri jedinice za dvije karte s brojem 1. Na kraju ostaju 2 karte s brojem 1. Nije moguće dobiti manje od 2 karte na kraju.

### Ulaz 2
```
10 4
1 1 1 1 1 1 1 1 1 1
```

### Izlaz 2
```
3
```

### Objašnjenje 2

Muki ima 10 karata s brojem 1 i $k = 4$. Svaka operacija zamjenjuje 4 iste karte za 3, smanjujući ukupan broj za 1. Može primijeniti operaciju dok god ima barem 4 karte s istim brojem: $10 \to 9 \to 8 \to 7 \to 6 \to 5 \to 4 \to 3$. Sa 3 karte više ne može izvršiti operaciju (treba mu tačno 4 iste), pa ostaje sa 3 karte.

### Ulaz 3
```
5 2
3 8 1 48 7
```

### Izlaz 3
```
5
```

### Objašnjenje 3

Sve karte imaju različite brojeve. Da bi izvršio operaciju, Muki treba tačno $k = 2$ karte s istim brojem, ali nema nijednog para. Nema mogućih operacija, pa ostaje sa svih 5 karata.
