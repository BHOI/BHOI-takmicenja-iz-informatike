# Tri Ključa Mudrosti

## Priča

Vama već dobro poznati dream-team, Anđela i njena mačka Luna, ovoga puta zadesila je još jedna situacija iz svijeta pjesama italijanskog benda _Rhapsody of Fire_.

Anđela i Luna krenule su na epsko putovanje kroz Začarana Carstva. Prema drevnoj legendi, carstvima vlada $N$ čarobnih mjesta (obilježeni brojevima $ \{0,1,...,N−1\} $), međusobno povezanih $N−1$ tajanstvenom stazom -- putevima toliko drevnim da su karte o njima odavno nestale u magli zaborava. Ono što je sigurno jeste da su tajanstvene staze obostrane, te da za za svako čarobno mjesto postoji najviše $18$ tajanstvenih staza, povezanih sa njim. 

Negdje duboko u začaranim šumama, prašnjavim dolinama i mračnim močvarama, skrivena su tri ključa mudrosti. No bez poznavanja staza, ni Anđela ni vojska princa Arvalda ne mogu ih pronaći.

Znate već i sami, Luna je daleko od obične mace. Ona može da osjeti starost čarobnih mjesta, te kada joj Anđela pokaže tri mjesta $u$, $v$ i $w$, Luna osjeti mjesto na kome su se ljudi iz ta tri mjesta okupljali -- jedino mjesto koje leži istovremeno na putu od $u$ do $v$, na putu od $u$ do $w$, te na putu od $v$ do $w$. Imajte na umu da je to možda nekada i čarobno mjesto $u$, $v$ ili $w$ -- ne mora značiti da su ljudi iz nekog mjesta uvijek putovali prema drugom.

Anđela zna da je ovo njena jedina šansa. Koristeći Lunin osjećaj, mora rekonstruisati cijelu mrežu staza Začaranog Carstva i mapira svih $N−1$ staza, jer samo tada može razumjeti tajne civilizacija davno prošlih. Ali ... greške su skupe! Anđela ne smije da pogriješi niti jednom, kada pokuša da mapira stazu.

## Zadatak
Ovo je **interaktivni zadatak**. Shodno tome, **ne koristi** se standardni ulaz/izlaz, već takmičar komunicira sa sistemom i pokušava da zaključi finalni odgovor. Ako bude koristili standardni ulaz/izlaz, nije garantovano da će vaš kod dobiti  poene nezavisno od toga da li je ispravan.

Implementirati funkciju ```solve(N)```, koja može pozivati:

- ```meetingPlace(u, v, w)``` -- Luna osjeća čvornu tačku mjesta $u$, $v$ i $w$. Vraća indeks čarobnog mjesta. Može biti pozvana najviše $100 000$ puta. Poziv je validan samo ako su $u$, $v$ i $w$ međusobno različiti indeksi iz skupa $ \{0,1,...,N−1\} $.
Ukoliko se prekorači dozvoljeni broj puta poziva funkcije, ili $u$, $v$ i $w$ nisu međusobno različiti, rješenje se odmah računa kao ```Wrong Answer```.
- ```mapPath(u, v)``` -- Anđela mapira stazu između mjesta $u$ i $v$. Svaka staza (ivica u grafu) mora biti prijavljena tačno jednom, i samo ako staza zaista postoji. U slučaju da staza zapravo ne postoji, rješenje se automatski računa kao ```Wrong Answer```.

## Upute za slanje zadatka
Na statement sekciji zadatka su tri fajla, ```grader.cpp```, ```grader.h``` i ```kljucevi.cpp```. Vi trebate modifikovati fajl ```kljucevi.cpp``` i taj fajl poslati. 

**Napomena:** Morate imati liniju ```#include "grader.h"```.

## Upute za korištenje gradera
Da testirate vaš kod trebate kompajlirati i pokrenuti testni grader. On je u fajlu ```grader.cpp```. Taj fajl traži implementaciju ```solve``` funkcije, tako da morate kopirati sve iz vašeg ```kljucevi.cpp``` fajla i zalijepiti na sami vrh ```grader.cpp``` fajla. Onda pokrenete ```grader.cpp``` kao što bi bilo koji drugi C++ fajl.

### Ulazni podaci za testni grader

Kada pokrenete ```grader.cpp```, morate unijeti podatke za unos.

U prvom redu ulaza učitava se broj $N$ -- broj čarobnih mjesta.

U narednih $N - 1$ redova učitavaju se dvije vrijednosti $u_i$ i $v_i$ ($0 \leq i \leq N - 2$) -- indeksi čarobih mjesta između kojih postoji put.

**Napomena:** Rješenje **ne treba** da čita podatke sa standardnog ulaza, niti da komunicira sa drugim dokumentima. Grader prima ulazne podatke.

### Izlazni podaci za testni grader

Kada program uspješno završi, testni grader ispisuje:
- Ukoliko je rješenje tačno, ispisuje ```Accepted```, te vraća broj poziva funkcije ```meetingPlace```.
- Ukoliko je rješenje netačno, ispisuje ```Wrong Answer```.

**Napomena:** Rješenje **se ne ispisuje** na standardni izlaz, već biva konstruisano kroz pozive funkcije ```mapPath```.

### Ograničenja

- $3 \leq N \leq 2 000$
- $0 \leq u_i \lt v_i \leq N - 1$ $(0 \leq i \leq N - 2)$
- Za svako čarobno mjesto, postoji najviše 18 čarobnih mjesta povezanih sa istim.

## Podzadaci

### Podzadatak 1 (3 bodova)

- $N \leq 7$

### Podzadatak 2 (11 bodova)

- $N \leq 50$

### Podzadatak 3 (23 boda)

- $N \leq 300$

### Podzadatak 4 (63 boda)

- Bez dodatnih ograničenja.

## Primjer (za testni gradera)

### Ulaz 1
```
5
0 1
0 2
1 3
1 4
```
### Pozivi funkcija 1
```
meetingPlace(0, 1, 2)   // vraća 0
meetingPlace(0, 3, 4)   // vraća 1
mapPath(1, 3)           // ne vraća ništa
mapPath(0, 2)           // ne vraća ništa
mapPath(1, 4)           // ne vraća ništa
mapPath(0, 1)           // ne vraća ništa
```

### Izlaz 1
```
Accepted: 2
```