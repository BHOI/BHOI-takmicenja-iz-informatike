# Matrix
Danas su učenici izučavali matrice na času informatike. Na kraju časa professor je dao jedan izazov koji učenici treba da riješe. Kako bi profesor motivisao učenike, obećao je počastiti vaflama one koji uspješno riješe izazov. Dakle, učenici su dobili izazov da riješe jedan zadatak iz matrica.

Dobili su matricu matricu `A` sa `N` redova (numerisanih od *1* do `N`) i `M` kolona (numerisanih od *1* do `M`). Polje u redu `r` i koloni `k` označavamo kao `[r,k]`. Za svaki red `r` i kolonu `k`, polje `A[r,k]` sadrži cijeli broj .

Ova matrica ima dvije interesantne osobine:

* Brojevi u svakom redu formiraju neopadajući niz. Odnosno, za svako `i` vrijedi: `A[i, 1] <= A[i, 2] ... <= A[i, M]`
* Brojevi u svakoj koloni također formiraju neopadajući niz. Odnosno, za svako `j` vrijedi: `A[1, j] <= A[2, j] ... <= A[N, j]`

Također, učenici su dobili prirodan broj `K`. Kvadratnu podmatricu od matrice `A` nazivamo dobrom ukoliko je prosjek svih brojeva u toj podmatrici veći ili jednak `K`. Vaš zadatak je pronaći broj dobrih kvadratnih podmatrica od matrice `A`. Budući da učenici imaju veliku želju da odu na vafle s profesorom, vaša pomoć bi im itekako značila.

Napomena: Kvadratna podmatrica od matrice `A` je matrica sa istim brojem redova i kolona tako da matrica `A` sadrži tu kvadratnu ploču. Dakle, ta kvadratna podmatrica je dobivena iz zadane matrice brisanjem nekoliko (eventualno, nula ili svih) redova/kolona s početka i nekoliko (eventualno, nula ili svih) redova/kolona s kraja.

## Ulaz
Prva linija na ulazu sadrži tri cijela broja `N`, `M`, `K`.
* `N` označava broj redova u matrici `A`
* `M` označava broj kolona u matrici `A`
* `K` je broj opisan u tekstu zadatka

Zatim se unose elementi matrice. Dakle, `N` linija slijedi. Za svako validno `i`, `i`-ta od ovih linija sadrži brojeve `A[i, 1], A[i, 2], ... A[i, M]`.

### Ograničenja
```
1 <= N <= 1000
1 <= M <= 1000
1 <= K <= 1 000 000 000
1 <= A[r, k] <= 1 000 000 000 (tj. za svaki element matrice A)
```

### Podzadaci
* Podzadatak 1 (9 bodova): Svi brojevi u matrici A su jednaki
* Podzadatak 2 (10 bodova): `1 <= N, M <= 30`
* Podzadatak 3 (11 bodova): `1 <= N, M <= 90`
* Podzadatak 4 (24 bodova): `1 <= N, M <= 500`
* Podzadatak 5 (46 bodova): bez dodatnih ograničenja

## Izlaz
Izlaz sadrži samo jednu liniju koja sadrži cijeli broj koji predstavlja broj dobrih kvadratnih podmatrica od matrice `A`.

## Primjeri
### Ulaz 1
```
3 3 4
2 2 3
3 4 5
4 5 5
```
### Izlaz 1
```
7
```
### Objašnjenje 1
Razmotrimo sve moguće kvadratne podmatrice:

#### Kvadratne podmatrice sa 1 redom i 1 kolonom:
- Ovdje ispod je matrica koja sadrži polje `(1,1)`. Prosjek u ovoj podmatrici je `2/1 = 2`. Ova podmatrica nije dobra budući da prosjek brojeva u toj podmatrici nije veći ili jednak `K = 4`.
```
2
```
- Ovdje ispod je matrica koja sadrži polje `(1,2)`. Prosjek u ovoj podmatrici je `2/1 = 2`. Ova podmatrica nije dobra budući da prosjek brojeva u toj podmatrici nije veći ili jednak `K = 4`.
```
2
```
- Ovdje ispod je matrica koja sadrži polje `(1,3)`. Prosjek u ovoj podmatrici je `3/1 = 3`. Ova podmatrica nije dobra budući da prosjek brojeva u toj podmatrici nije veći ili jednak `K = 4`.
```
3
```
- Ovdje ispod je matrica koja sadrži polje `(2,1)`. Prosjek u ovoj podmatrici je `3/1 = 3`. Ova podmatrica nije dobra budući da prosjek brojeva u toj podmatrici nije veći ili jednak `K = 4`.
```
3
```
- Ovdje ispod je matrica koja sadrži polje `(2,2)`. Prosjek u ovoj podmatrici je `4/1 = 4`. Ova podmatrica **jeste** dobra budući da prosjek brojeva u toj podmatrici je veći ili jednak `K = 4`.
```
4
```
- Ovdje ispod je matrica koja sadrži polje `(2,3)`. Prosjek u ovoj podmatrici je `5/1 = 5`. Ova podmatrica **jeste** dobra budući da prosjek brojeva u toj podmatrici je veći ili jednak `K = 4`.
```
5
```
- Ovdje ispod je matrica koja sadrži polje `(3,1)`. Prosjek u ovoj podmatrici je `4/1 = 4`. Ova podmatrica **jeste** dobra budući da prosjek brojeva u toj podmatrici je veći ili jednak `K = 4`.
```
4
```
- Ovdje ispod je matrica koja sadrži polje `(3,2)`. Prosjek u ovoj podmatrici je `5/1 = 5`. Ova podmatrica **jeste** dobra budući da prosjek brojeva u toj podmatrici je veći ili jednak `K = 4`.
```
5
```
- Ovdje ispod je matrica koja sadrži polje `(3,3)`. Prosjek u ovoj podmatrici je `5/1 = 5`. Ova podmatrica **jeste** dobra budući da prosjek brojeva u toj podmatrici je veći ili jednak `K = 4`.
```
5
```

#### Kvadratne podmatrice sa 2 reda i 2 kolone:
- Ovdje ispod je matrica koja sadrži polja `(1,1), (1,2) , (2,1), (2,2)`. Prosjek u ovoj podmatrici je `(2+2+3+4)/4 = 2`.75. Ova podmatrica nije dobra budući da prosjek brojeva u toj podmatrici nije veći ili jednak `K = 4`.
```
2 3
3 4
```
- Ovdje ispod je matrica koja sadrži polja `(1,2), (1,3), (2,2), (2,3)`. Prosjek u ovoj podmatrici je `(2+3+4+5)/4 = 3.5`. Ova podmatrica nije dobra budući da prosjek brojeva u toj podmatrici nije veći ili jednak `K = 4`.
```
2 3
4 5
```
- Ovdje ispod je matrica koja sadrži polja `(2,1), (2,2), (3,1), (3,2)`. Prosjek u ovoj podmatrici je `(3+4+4+5)/4 = 4`. Ova podmatrica **jeste** dobra budući da prosjek brojeva u toj podmatrici je veći ili jednak `K = 4`.
```
3 4
4 5
```
- Ovdje ispod je matrica koja sadrži polja `(2,2), (2,3), (3,2), (3,3)`. Prosjek u ovoj podmatrici je `(4+5+5+5)/4 = 4.75`. Ova podmatrica **jeste** dobra budući da prosjek brojeva u toj podmatrici je veći ili jednak `K = 4`.
```
4 5
5 5
```

#### Kvadratne podmatrice sa 2 reda i 2 kolone:

- Ovdje ispod je matrica koja sadrži sva polja matrice `A`. Prosjek u ovoj podmatrici je `(2+2+3+3+4+5+4+5+5)/9 = 3.67`. Ova podmatrica nije dobra budući da prosjek brojeva u toj podmatrici je veći ili jednak `K = 4`.
```
2 2 3
3 4 5
4 5 5
```

#### Ishod
Među svim razmatranim kvadratnim podmatricama, dobije se da je broj dobrih kvadratnih podmatrica od `A` jednak *7*.
