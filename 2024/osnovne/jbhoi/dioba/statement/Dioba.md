# Dioba

Nastavnica Fata želi da podijeli svako odjeljenje na po 2 tima kako bi se takmičili u programiranju. Ipak, kako se radi o 9. razredima, mnogi učenici i učenice su se sprijateljili i žele biti u istom timu, ili posvađali i žele biti na suprotnim timovima. Vaš zadatak je pomoći nastavnici Fati tako što joj kažete, za svaki odjeljenje, da li ga je uopšte moguće podijelti na 2 tima tako da se ispune sve želje učenika i učenica.

*Napomena: timovi ne moraju biti iste veličine, ali u oba tima je potrebno da se nalazi barem 1 učenik.*

## Ulazni podaci

Prvi red ulaza sadrži jedan broj, `R`, broj odjeljenja za koje je potrebno provjeriti da li je moguće napraviti 2 tima ispunjavajući želje učenika.

Nakon toga slijedi `R` opisa odjeljenja, gdje za svaki od njih će biti upisano sljedeće:
	- Prvi red svakog slučaja sadrži brojeve `N`, `K` i `S`. 
		- `N` označava broj učenika u odjeljenju, označeni brojevima od `1` do `N`.
		- `K` označava broj parova učenika koji žele da budu i istom timu
		- `S` označava broj parova učenika koji žele da budu u suprotnim timovima.
	- Idućih `K` redova sadrži po `2` broja, oni označavaju par učenika koji žele biti u istom timu. Isti parovi se mogu pojaviti više puta.
	- Idućih i posljednjih `S` redova za to odjeljenje sadrže po `2` broja, oni označavaju par učenika koji žele biti u suprotnim timovima. Isti parovi se mogu pojaviti više puta.

### Ograničenja
```
1 <= R <= 100
1 <= N <= 10^6
Zbir K i S za sva odjeljenja nije veći od 10^5.
Zbir N za sva odjeljenja nije veći od 10^6.
```

## Podzadaci

### Podzadatak 1 (26 bodova)

```
S = 0
```

### Podzadatak 2 (12 bodova)

```
1 <= N <= 10
K = 0
```

### Podzadatak 3 (21 bodova)

```
K = 0
```

### Podzadatak 4 (41 bodova)

Bez dodatnih ograničenja.

## Izlazni podaci

Za svako odjeljenje, u zasebnom redu, potrebno je ispisati `DA` ako je moguće napraviti 2 tima uz ispunjavanje svih navedenih želja učenika, odnosno `NE`, ako nije.

## Primjeri
### Ulaz 1
```
3
5 2 2
1 2
3 4
1 5
2 3
3 2 1
1 2
1 3
2 3
4 0 4
3 2
2 1
1 4
4 3
```
### Izlaz 1
```
DA
NE
DA
```
### Objašnjenje 1
U prvom odjeljenju se nalazi 5 učenika (učenici 1, 2, 3, 4 i 5). Učenici 1 i 2 žele biti u istom timu, 3 i 4 žele biti u istom timu, 1 i 5 žele biti u suprotnim timovima i 2 i 3 žele biti u suprotnim timovima. Sve ove želje se mogu ispuniti ako u jedan tim stavimo učenike 1 i 2, a u drugi tim učenike 3, 4 i 5.

U drugom odjeljenju učenici 1 i 2 žele biti zajedno, te 1 i 3 žele biti zajedno, ali pošto učenici 2 i 3 ne žele biti zajedno nije moguće ispuniti sve želje.

U trećem odjeljenju moguće je ispuniti sve želje tako što u jedan tim stavimo učenike 1 i 3, a u drugi tim stavimo učenike 2 i 4.

### Ulaz 2
```
3
5 5 0
1 2
5 3
1 4
2 5
5 3
4 1 3
1 4
2 3
3 4
2 1
6 4 2
6 2
3 5
3 4
4 5
1 2
1 4
```
### Izlaz 2
```
NE
NE
DA
```
### Objašenjenje 2
U prvom razredu se ne mogu napraviti 2 tima jer jedini način da se sve želje ispune je da svi učenici budu u istom timu sa svim ostalim.

U drugom razredu bi učenici 1, 2 i 3 svi trebali biti u različitim timovima, tako da je nemoguće ispuniti svačiju želju.

U trećem razredu se sve želje mogu ispuniti ako je učenik 1 u jednom timu, a svi ostali učenici u drugom timu.