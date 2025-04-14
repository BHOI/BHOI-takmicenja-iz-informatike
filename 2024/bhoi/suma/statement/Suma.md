# Šuma

Već je ponoć, a čarobnjak Haris mora proći kroz začaranu $N$-dimenzionalnu šumu kako bi stigao kući. Sa sobom ima kartu koja prikazuje tu šumu razdijeljenu na polja, gdje je svako polje određeno sa $N$ koordinata. Haris se nalazi na polju $(1,1,...,1)$, a želi doći na polje $(A_1,A_2,...,A_N)$. Na ukupno $Q$ polja raste drveće koje on mora zaobići. 

Kako se ne bi izgubio, Haris sa svakim korakom pažljivo napušta polje na kojem se nalazi i prelazi u susjedno polje, koje se od prethodnog razlikuje samo za 1 i to samo po jednoj koordinati. Štoviše, pošto se mnogo boji $N$-dimenzionalnih vukova, on želi doći kući što prije i kreće se „optimalno”, što znači da uvijek prelazi u polje čija je nova koordinata tačno za 1 *veća* od koordinate prethodnog polja. 

Putujući kroz tišinu, Haris pokušava skrenuti svoje misli sa jeze i mraka razmišljajući o ukupnom broju optimalnih putanja koje može odabrati da stigne do cilja. Međutim, on poznaje sebe i zna da će ga taj problem izludjeti ako ga ne riješi prije izlaska iz šume te će u tom slučaju zauvijek ostaviti razum u ukletim dimenzijama. Pomozite Harisu tako što ćete napisati program koji računa ukupan broj putanja, koje su ujedno i optimalne putanje, a kojima Haris može proći kroz šumu zaobilazeći polja s drvećem. Optimalna putanja je ona za koju je potreban broj koraka da bi se stiglo do cilja, minimalan.

## Ulazni podaci

Prvi red ulaza sadrži prirodan broj $N$, broj dimenzija šume. 
Drugi red sadrži redom brojeve $A_1, A_2, ..., A_N$, koordinate Harisovog odredišta. 
Treći red sadrži prirodan broj $Q$, broj polja na kojima se nalaze stabla. Slijedi $Q$ redova, od kojih $i$-ti red sadrži koordinate $i$-tog stabla, redom $S_{i,1}, S_{i,2}, ..., S_{i,N}$.

### Ograničenja

$1 \leq N \leq 500 \\$ 
$1 \leq S_{i,j} \leq A_j \leq 500 \\$
$1 \leq Q \leq 1000$


## Podzadaci

### Podzadatak 1 (10 bodova)
$N = 2$

### Podzadatak 2 (15 bodova)
$Q = 10$

### Podzadatak 3 (75 bodova)
Bez dodatnih ograničenja.

## Izlazni podaci

Prvi i jedini broj izlaza treba biti $R \mod 10^9 + 7$, gdje je $R$ ukupan broj optimalnih putanja koje zaobilaze polja sa drvećem.

***Napomena**: Kod računanja sa ostacima pri dijeljenju prostim brojem $p = 10^9 + 7$, svaki broj $0<x<p$ posjeduje jedinstven inverz $0 < \overline x < p$ takav da vrijedi $x \overline x \equiv 1 \mod p$.
Slijedi da, ako je $m = (u_1 ... u_s)/(v_1 ... v_t)$ cijeli broj takav da $p$ ne dijeli proizvod $v_1 ... v_t$, onda vrijedi $m \equiv u_1...u_s \overline v_1 ... \overline v_t \mod p$. Inverz broja možemo pronaći rekurzivno, jer je $\overline 1 = 1$, a zatim $\overline x \equiv y \cdot \overline{(xy-p)} \mod p$ za brojeve $1<x<p$, te $p < xy < p+x$. Jedan korak u rekurzivnom postupku se sastoji od pronalaska broja $y$, koji je jedinstven, a zatim ponavljanjem postupka za računanje inverza broja $xy-p$, sve dok ne bude ispunjeno $xy -p = 1$.*

## Primjer 1
### Ulaz 1
```
2
3 4
2
2 2
1 4
```
### Izlaz 1
```
3
```
### Objašnjenje 1
Dva moguća optimalna puta prolaze iznad drveta u sredini, a jedan ispod.

## Primjer 2
### Ulaz 2
```
2
5 5
3
2 2
3 3
4 4
```
### Izlaz 2
```
10
```
### Objašnjenje 2
Na dijagonali između početnog i ciljnog polja se nalaze 3 drveta. Prolazeći sa jedne strane ovog niza Haris ima 5 mogućih optimalnih putanja, kao i sa druge.

## Primjer 3
### Ulaz 3
```
4
3 4 4 4
4
3 1 2 2
3 4 2 4
2 3 1 3
2 2 4 4
```
### Izlaz 3
```
78720
```
