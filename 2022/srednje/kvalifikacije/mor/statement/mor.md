# MOR
Flash memorija je vrsta elektroničke memorije koja ne gubi informacije kada se prekine napon. Vi ste nedavno patentirali i proizveli novu vrstu jeftine memorije koju ste nazvali MOR. MOR je naročito jeftina u proizvodnji, ali je složenija za rukovanje zbog svojih određenih ograničenja.

MOR memorija se sastoji od niza od `M` blokova, gdje se svaki blok sastoji od tačno `K` bitova. Kod MOR memorije nije uvijek moguće postaviti pojedini bit na željenu vrijednost već su dopuštene samo sljedeće operacije:

- Pojedini bit možemo postaviti na 0 te ova operacija traje 1 milisekundu.
- Sve bitove u pojedinom bloku možemo postaviti na 1 te ova operacija traje 100 milisekundi.

Napišite program koji će za zadano početno i traženo stanje memorije pronaći najmanje vrijeme potrebno da se memorija iz početnog stanja dovede u traženo.

## Ulaz
U prvom redu nalaze se dva prirodna broja, `M` i `K` međusobno odvojena razmakom - broj blokova i broj bitova u pojedinom bloku.

U drugom redu nalazi se niz od tačno `M*(K+1)-1` znakova - početno stanje memorije.

U trećem redu nalazi se niz od tačno `M*(K+1)-1` znakova - traženo stanje memorije.

Početno i traženo stanje memorije su nizovi znakova koji se sastoje od M blokova međusobno odvojenih znakom `|` (vertikalna crta, ASCII 124), a svaki blok se sastoji od tačno `K` znakova `0` ili `1` koje predstavljaju vrijednost određenog bita u bloku.

### Ograničenja
```
M, K <= 20
M * K <= 80
```

## Izlaz
U prvi i jedini red izlaza potrebno je ispisati najmanje moguće vrijeme u milisekundama potrebno da se memorija postavi u traženo stanje.

## Primjeri
### Ulaz 1
```
2 4
0110|1000
0000|0000
```
### Izlaz 1
```
3
```
### Ulaz 2
```
2 4
0110|1000
0000|0001
```
### Izlaz 2
```
105
```
### Ulaz 3
```
3 3
110|011|111
101|111|011
```
### Izlaz 3
```
202
```