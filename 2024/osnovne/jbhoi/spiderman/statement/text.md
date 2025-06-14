# Spiderman

Spiderman se nalazi u Sarajevu prvi put u svom životu i želi da obiđe grad na poseban, njemu svojstven način. Ispred njega je N zgrada i on želi da skačući po zgradama dođe do zadnje zgrade.

Svaka zgrada ima svoju visinu Hi koja je pozitivan cijeli broj. Spiderman može da skoči na bilo koju zgradu koju vidi, a vidi svaku zgradu ispred sebe koja nije zaklonjena nekom drugom zgradom. Za zgradu kažemo da je zaklonjena ukoliko je prije nje neka zgrada koja ima visinu veću ili jednaku od nje, a koju Spiderman vidi ispred sebe. Nijedna zgrada koja se nalazi prije Spidermana ne utiče na zaklonjenost ostalih zgrada jer Spiderman gleda samo naprijed (desno).

Obratite pažnju da visina zgrade na kojoj se spiderman trenutno nalazi ne utiče na to na koju zgradu on može skočiti u sljedećem skoku. Sve što je bitno je da zgrada nije zaklonjena po definiciji iznad.

Cilj Spidermana je da dođe na posljednju zgradu. Pomozite mu da izračuna koliko najmanje skokova mu treba da postigne željeni cilj.

*Važno:* Neki podzadaci mogu imati veliku količinu brojeva na ulazu, te da biste ubrzali unos brojeva u vaš program savjetujemo da koristite slijedeće dvije linije na početku vaše `main()` funkcije:
```cpp
ios_base::sync_with_stdio(false);
cin.tie(NULL);
```

## Ulaz

Prva linija inputa sadrži cijeli broj N (`1 ≤ N ≤ 20.000.000`) koji predstavlja broj zgrada koje se nalaze ispred Spidermana.

Druga linija sadrži N cijelih brojeva Hi (`1 ≤ Hi ≤ 1.000.000.000`) koje predstavljaju visine zgrada u redoslijedu u kojem se nalaze ispred Spidermana.

## Uzlaz

U jedinoj liniji izlaza treba ispisati koliko najmanje skokova je potrebno da Spiderman dođe do posljednje zgrade.

## Podzadaci

### Podzadatak 1 (7 bodova)

Niz visina je strogo rastući, odnosno svaka zgrada je viša od prethodne.

### Podzadatak 2 (7 bodova)

Niz visina je strogo opadajući, odnosno svaka zgrada je niža od prethodne.

### Podzadatak 3 (37 bodova)

`1 ≤ N ≤ 5.000`

### Podzadatak 4 (23 boda)

`1 ≤ N ≤ 300.000`

### Podzadatak 5 (26 bodova)

Nema dodatnih ograničenja.

## Primjeri

### Ulaz 1

```
3
1 5 10
```

### Izlaz 1

```
1
```

### Objašnjenje 1

Spiderman vidi svaku zgradu ispred sebe, pa može odma skočiti na posljednju zgradu i postići cilj u jednom skoku.

### Ulaz 2

```
4
5 3 7 2
```

### Izlaz 2

```
2
```

### Objašnjenje 2

Spiderman može skočiti na zgradu visine 7, a zatim na zgradu visine 2. U dva skoka postigao je svoj cilj. Sa jednim skokom to nije moguće, obzirom da je posljednja zgrada zaklonjena od zgrade prije nje.

### Ulaz 3

```
6
20 15 10 5 2 1
```

### Izlaz 3

```
6
```

### Objašnjenje 3

Obzirom da svaka zgrada zaklanja sve zgrade nakon sebe, Spiderman mora skočiti na svaku zgradu da bi došao do zadnje.