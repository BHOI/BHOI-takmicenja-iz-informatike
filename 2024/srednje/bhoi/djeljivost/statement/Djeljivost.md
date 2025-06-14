# Djeljivost

Vjerovatno znate da u dekadnom brojnom sistemu (baza 10), broj je djeljiv sa 9 ako mu je zbir cifara djeljiv sa 9. No, da li ste znali da postoji generalnije pravilo? Na primjer, u oktalnom brojnom sistemu (baza 8) broj je djeljiv sa 7 ako mu je zbir cifara djeljiv sa 7. U heksadecimalnom brojnom sistemu (baza 16) broj je djeljiv sa 15 ako mu je zbir cifara djeljiv sa 15. 

Inače, za brojni sistem sa bazom $B$ vrijedi da je prirodan broj djeljiv sa $B-1$ ako mu je zbir cifara djeljiv sa $B-1$. Kako provjerimo djeljivost novonastalog broja? Ponavljamo postupak (zamjene broja sa zbirom njegovih cifara) dok ne dobijemo jednocifren broj. Ako je dobijeni jednocifren broj jednak $B-1$, onda je originalni broj djeljiv sa $B-1$. U suprotnom nije djeljiv.

Vaš zadatak je napisati program koji prima listu pitanja u formi baze $B$ i broja $X$ zapisanog u toj bazi, te određuje da li je broj $X$ djeljiv sa $B-1$. Baza $B$ neće biti veća od 16, a za cifre veće od 9 koristit će se slova A, B, C, D, E i F sa vrijednostima 10, 11, 12, 13, 14 i 15, redom.

***Napomena**: nije nužno koristiti opisani postupak za provjeru djeljivosti broja $X$ sa $B-1$, možete koristiti i druge načine provjere djeljivosti po želji.*

## Ulazni podaci

Prvi red ulaza sadrži jedan prirodan broj $N$, broj upita programu.
Svaki od narednih $N$ redova sadrži dva prirodna broja - $B$ i $X$, odnosno bazu i broj zapisan u toj bazi, za koje je potrebno odrediti da li je $X$ djeljivo sa $B-1$.

### Ograničenja

$1 < N \leq 100 \\$ 
$2 \leq B \leq 16 \\$
$1 \leq X \leq 10^9$


## Podzadaci

### Podzadatak 1 (23 bodova)
$X < B \leq 10$

### Podzadatak 2 (24 boda)
$B = 10$

### Podzadatak 3 (32 bodova)
Baza $B$ će uvijek biti jedan od brojeva $2$, $8$, $10$ ili $16$.

### Podzadatak 4 (9 bodova)
Neće biti potrebno više od jednog koraka opisanog postupka da se dođe do jednocifrenog broja.

### Podzadatak 5 (5 bodova)
$B \leq 10$

### Podzadatak 6 (7 bodova)
Bez dodatnih ograničenja.

## Izlazni podaci

Za svaki upit, u zasebnom redu, potrebno je ispisati `DA` ako je broj $X$, zapisan u brojnom sistemu sa bazom $B$, djeljiv sa $B-1$. Ukoliko nije, potrebno je umjesto toga ispisati `NE`.

## Primjeri
### Ulaz 1
```
3
10 27
2 10101011
8 5
```
### Izlaz 1
```
DA
DA
NE
```
### Objašnjenje 1
Za prvi upit potrebno je provjeriti da li je broj $27$, zapisan u dekadnom brojnom sistemu, djeljiv sa 9. Obzirom da jeste, potrebno je u prvom redu ispisati `DA`.

Za drugi upit potrebno je provjeriti da li je broj $171$, zapisan u binarnom brojnom sistemu kao $10101011$, djeljiv sa $1$. Kako je svaki cijeli broj djeljiv sa $1$ tako je u drugom redu potrebno ispisati `DA`.

Za treći upit potrebno je provjeriti da li je broj $5$, zapisan u oktalnom brojnom sistemu, djeljiv sa $7$. Kako nije, potrebno je ispisati `NE` u trećem redu. 

### Ulaz 2
```
5
16 6AE
12 3A
7 51
4 31203
13 C3B0
```
### Izlaz 2
```
DA
NE
DA
DA
NE
```
### Objašenjenje 2
Za prvi upit, praćenjem postupka rastavljamo $6AE$ na cifre $6$, $A$ i $E$, sabiremo ih u heksadecimalnom brojnom sistemu, čime dobijamo $1E$. Ponavljajući postupak, sabiranjem $1$ i $E$ dobijamo $F$, što predstavlja najveću cifru ovog brojnog sistema, odnosno jednako je $B-1$, čime zaključujemo da je originalni broj djeljiv sa $F$, odnosno $15$ u dekadnom brojnom sistemu.

Za drugi upit, zbir cifara $3$ i $A$ u brojnom sistemu sa bazom 12 daje $11$, odnosno ponavljanjem postupka dobijamo $2$. Kako ovaj rezultat nije jednak $B$ (odnosno $11$ u dekadnom brojnom sistemu) tako zaključujemo da $3A$ nije djeljivo sa $B$ u brojnom sistemu baze 12.

Za treći upit, sabiranjem cifara dobijamo $5+1=6$, što je očigledno djeljivo sa $6$, tako da je potrebno ispisati `DA`.

Za četvrti upit, broj u brojnom sistemu sa bazom $4$ je djeljiv sa $3$ ako mu je zbir cifara djeljiv sa $3$. To je tačno, tako da je potrebno ispisati `DA`.

Za peti upit, u brojnom sistemu sa bazom 13 vrijedi $C+3+B+0 = 20$, $2+0=2$. Kako smo došli do jednocifrenog broja, a taj broj nije $C$ (odnosno 12 u dekadnom brojnom sistemu), tako zaključujemo da originalni broj nije djeljiv sa $B-1$, te je potrebno ispisati `NE`.