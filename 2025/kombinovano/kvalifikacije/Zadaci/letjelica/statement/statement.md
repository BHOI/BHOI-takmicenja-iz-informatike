# Letjelica

SveMirko se nedavno zaposlio u svemirskoj bazi. Njegov šef Vincent Van Zemaljac dao mu je zadatak da pripremi autonomnu letjelicu za istraživačku misiju.

SveMirko nije dobar u svom poslu, te je slučajno izbrisao sav kod koji navodi letjelicu gdje treba da ide. Jedine instrukcije koje su ostale u letjelici su:
- Letjelica se kreće u 3 dimenzije
- Na početku sata, nasumično izaberi jedan od 6 smjerova: gore, dole, lijevo, desno, naprijed, nazad.
- Narednih sat vremena, kreći se u izabranom smjeru brzinom od $1 \frac{km}{h}$. 

Dakle, ukoliko je koordinata letjelice na početku sata $(x, y, z)$, njena koordinata na početku narednog sata može biti $(x + 1, y, z), (x - 1, y, z), (x, y - 1, z), (x, y + 1, z), (x, y, z - 1), (x, y, z + 1)$.

Nažalost, SveMirko je shvatio svoju grešku tek nakon što je letjelica napustila svemirsku bazu. Kako ovo nije prvi put da SveMirko pravi greške na poslu, zna da će ga šef otpustiti ako ne uspije pronaći letjelicu i vratiti je u bazu. Svemirska baza ima radar koji za dati realan broj $d$ može saznati tačnu lokaciju letjelice samo ako je letjelica udaljena tačno $d$ kilometara od baze. Ako letjelica nije udaljena tačno $d$ kilometara od baze, radar će to saopštiti. Ukoliko SveMirko sazna tačne koordinate letjelice, može iskoristiti teleporter da je u sekundi vrati u bazu.

SveMirko zna da letjelica ima dovoljno goriva da se kreće tačno $N$ sati. Pomozite SveMirku tako što ćete mu za dati broj $N$ reći koliko će najviše puta morati iskoristiti radar da locira letjelicu.

## Ulazni podaci 

Pozitivan cijeli broj $N$, broj sati koje se letjelica kreće. Dakle, letjelica će u toku svog leta napraviti $N$ koraka.

### Ograničenja

$1 \leq N \leq 10^3$

## Testni primjeri

Ovaj zadatak ne koristi podzadatke za bodovanje, već pojedinačne testne primjere koji nose po jednak broj bodova.

Poznato vam je da u testnim primjerima koji vrijede $10\%$ bodova vrijedi $1 \leq N \leq 5$. 

U testnim primjerima koji nose dodatnih $30\%$ bodova vrijedi $1 \leq N \leq 20$.

## Izlazni podaci

Pozitivan cijeli broj $k$, najveći različit broj korištenja radara koji će SveMirko morati napraviti da bi odredio udaljenost letjelice. 

## Primjeri

### Ulaz 1
```
2
```

### Izlaz 1
```
3
```

### Objašnjenje 1

Ako je letjelica počela sa koordinata $(0, 0, 0)$, onda nakon dva koraka može biti na udaljenostima:
1. $d = 2$, ako je na jednoj od narednih koordinata  $(2, 0, 0)$, $(0, 2, 0)$, $(0, 0, 2)$, $(-2, 0, 0)$, $(0, -2, 0)$, $(0, 0, -2)$.
2. $d = \sqrt{2}$, ako je na jednoj od narednih koordinata $(1, 1, 0)$, $(-1, 1, 0)$, $(1, -1, 0)$, $(-1, -1, 0)$, $(0, 1, 1)$, $(0, -1, 1)$, $(0, 1, -1)$, $(0, -1, -1)$, $(1, 0, 1)$, $(-1, 0, 1)$, $(1, 0, -1)$, $(-1, 0, -1)$.
3. $d = 0$, ako je na koordinati $(0, 0, 0)$. To se moglo desiti ako je npr. letjelica na početku prvog sata odlučila ići lijevo, a na početku drugog koraka ići desno.

### Ulaz 2
```
3
```

### Izlaz 2
```
4
```

### Objašnjenje 2

### Ulaz 3
```
10
```

### Izlaz 3
```
32
```

### Objašnjenje 3
