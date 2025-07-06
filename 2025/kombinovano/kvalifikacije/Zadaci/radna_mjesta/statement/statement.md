# Radna mjesta

U prostorijama firme BHOI d.o.o. svih $N$ zaposlenika ima dodjeljeno jedno od $N$ radnih mjesta koja su raspoređena u krug. Svaki zaposlenik bira kada će raditi od kuće ili doći u ured. Čak i kada neko ne dođe u ured zna ko od kolega je došao.

Emin je primjetio pravilo kod dolaska sebe i svojih kolega u ured. Svačiji dolazak u ured sutra ovisi samo od današnjeg dolaska dvoje direktno susjednih kolega. Emin, kao i sve ostale kolege, će doći sutra u ured samo je tačno jedno od njegovih kolega susjeda došlo danas.

Svih $N$ radnih mjesta ima po 2 susjeda. Radna mjesta sa susjendim brojevima (npr. $4$ i $5$) su susjedna, a dodatno radna mjesta sa brojevima $N$ i $1$ su susjedna (pošto su raspoređena u krug). 

Dobit ćete opis današnjih dolazaka u ured - sa $1$ je označeno da zaposlenik na odgovarajućem radnom mjestu jeste došao u ured, dok je sa $0$ označeno da nije. Vaš zadatak je odrediti ko će doći, a ko neće, za $T$ dana.  

## Ulazni podaci

Prvi red ulaza sadrži dva broja: $N$, broj radnih mjesta (i zaposlenika) i $T$, broj dana za koji trebate predvidjeti dolaske u ured.\
Drugi red ulaza sadrži opis današnjih dolazaka u ured u formi niza $N$ uzastopnih $1$ i $0$ bez razmaka između njih.

### Ograničenja
$3 \leq N \leq 100 000$\
$1 \leq T \leq 10^{15}$

## Podzadaci

### Podzadatak 1 (7 bodova)
$N \leq 15$\
$T \leq 15$

### Podzadatak 2 (26 bodova)
$N \leq 4000$\
$T \leq 10^7$

### Podzadatak 3 (40 bodova)
$N \leq 15$

### Podzadatak 4 (27 boda)
Bez dodatnih ograničenja.

## Izlazni podaci

Potrebno je ispisati niz od $N$ znakova $1$ i $0$ kojim se opisuje ko hoće, a ko neće u ured za $T$ dana.  

## Primjeri
### Ulaz 1
```
6 1
000001
```
### Izlaz 1
```
100010
```
### Objašnjenje 1
Zaposlenik na radnom mjestu $1$ će doći sutra jer je njegov direktni susjed na radnom mjestu $N$ došao danas, a drugi susjed na radnom mjestu $2$ nije. Isto vrijedi za zaposlenika na radnom mjestu $5$. Zaposlenici na preostalim radnim mjestima neće doći jer nijedan od njihovih susjeda nije došao danas.

Izlazom je opisano da će zaposlenici na radnim mjestima $1$ i $5$ doći, dok preostali (na radnim mjestima $2$, $3$, $4$ i $6$) neće.

### Ulaz 2
```
10 5
1111111111
```
### Izlaz 2
```
0000000000
```
### Objašnjenje 2
Sutra niko neće doći jer su danas svakome oba susjeda došla. Ostalim danima niko neće doći jer dan prije nijedan od susjeda nije došao (doći će samo ako dan prije dođe tačno 1 susjed!).

### Ulaz 3
```
5 3
11010
```
### Izlaz 3
```
00101
```
### Objašnjenje 3
Danas: `11010`\
Za 1 dan: `11000`\
Za 2 dana: `11101`\
Za 3 dana: `00101`