# Labirint

Dat je labirint u obliku matrice dimenzija $H \times W$. Svako polje matrice je ili slobodno (`.`), ili zid (`#`). Jedno slobodno polje je označeno sa `S` (start), a jedno sa `C` (cilj).

Iz svakog slobodnog polja možete se pomaknuti u jedno od četiri susjedna polja (gore, dolje, lijevo, desno), ukoliko je to polje također slobodno i nalazi se unutar matrice.

Svaki pomak u nekom smjeru predstavlja korak. Ako se dva uzastopna koraka razlikuju u smjeru, to se smatra jednim **skretanjem**. Prvi korak se također računa kao skretanje (jer je to početna promjena smjera iz stanja mirovanja). Nije dozvoljeno izaći van granica labirinta.

Odredite minimalan broj skretanja na putu od `S` do `C`. Garantovano je da put uvijek postoji.

**Napomena:** Ulaz može biti velik. Preporučuje se korištenje brzog čitanja:
```cpp
ios::sync_with_stdio(false);
cin.tie(nullptr);
```

## Ulazni podaci

U prvom redu se nalaze dva cijela broja $H$ i $W$: broj redova i kolona matrice.

U sljedećih $H$ redova se nalazi po $W$ znakova: opis matrice.

### Ograničenja

$1 \leq H, W \leq 1\;000$

Matrica sadrži tačno jedno polje `S` i tačno jedno polje `C`.

Polja `S` i `C` su uvijek na različitim pozicijama.

Garantovano je da postoji put od `S` do `C`.

## Podzadaci

### Podzadatak 1 (14 bodova)
Nema zidova (sva polja su slobodna, osim oznaka `S` i `C`).

### Podzadatak 2 (45 bodova)
Postoji tačno jedan put od `S` do `C` koji ne prolazi istim poljem više puta.

### Podzadatak 3 (40 bodova)
Ima najviše $5$ zidova.

### Podzadatak 4 (34 boda)
$H, W \leq 10$

### Podzadatak 5 (17 bodova)
Bez dodatnih ograničenja.

## Izlazni podaci

Na jedinoj liniji izlaza ispišite minimalan broj skretanja na putu od `S` do `C`.

## Primjeri

### Ulaz 1
```
3 5
S....
.....
....C
```

### Izlaz 1
```
2
```

### Objašnjenje 1

Jedan optimalan put: idemo desno 4 koraka, pa dolje 2 koraka. Prvo skretanje je početni korak (desno), drugo je promjena smjera (dolje). Ukupno 2 skretanja.

### Ulaz 2
```
3 3
S.#
..#
..C
```

### Izlaz 2
```
2
```

### Objašnjenje 2

Idemo dolje 2 koraka (1 skretanje za početni korak), pa desno 2 koraka (1 skretanje za promjenu smjera). Ukupno 2 skretanja.

### Ulaz 3
```
1 5
S...C
```

### Izlaz 3
```
1
```

### Objašnjenje 3

Start i cilj su u istom redu. Idemo desno 4 koraka. Jedino skretanje je početni korak.
