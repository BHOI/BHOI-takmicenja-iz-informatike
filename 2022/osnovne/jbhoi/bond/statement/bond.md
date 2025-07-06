# Bond
Tajni agent Bond, James Bond, je opet dobio zadatak da spasi svijet. Ovaj put mora pobijediti tajnog protivnika u jednoj matematičkoj igri. Dok on istražuje mjesto okršaja, zamolio je Tebe da mu napišeš program za ovu igru koju će on onda samo pokretati na svom novom iPad-u.

Kako se igra ova igra? Igrač dobije tačno šest prirodnih brojeva koji tokom igre ne mijenjaju svoju poziciju. Od prvih pet zadanih brojeva, korištenjem četiri osnovne matematičke operacije: + (sabiranje), - (oduzimanje), * (množenje), / (cjelobrojno dijeljenje), igrač treba složiti izraz čija će vrijednost nakon evaluacije biti jednaka šestom zadanom broju. Prilikom evaluacije izraza se ne poštuju prioriteti operatora već evaluacija izraza ide redom s lijeva na desno. Npr. 2+3*5=25. 

Za rješavanje ovog problema, Bond će moći koristiti 2 metode. To su:

1. traženi izraz se može složiti korištenjem samo jednog od operatora;
2. traženi izraz se slaže uz pomod svih operatora koji se mogu ponavljati;

Pomozi Bondu da opet spasi svijet. Izraz će uvijek biti moguće složiti na samo jedan način.

## Ulaz
Šest prirodnih brojeva A, B, C, D, E, F, svaki u svom redu;

### Ograničenja
```
1 <= A, B, C, D, E, F <= 100
```
*U primjerima vrijednima 40% bodova, Bond će problem moći rješiti korištenjem prve metode.*

## Izlaz
Traženi izraz iz zadatka zapisan u obliku A?B?C?D?E=F, gdje je ? jedan od operatora.

## Primjeri
### Ulaz 1
```
3
5
7
9
11
35
```
### Izlaz 1
```
3+5+7+9+11=35
```
*Bond je ovaj problem mogao riješiti korištenjem prve metode.*
### Ulaz 2
```
36
11
99
29
39
11
```
### Izlaz 2
```
36*11+99-29/39=11
```