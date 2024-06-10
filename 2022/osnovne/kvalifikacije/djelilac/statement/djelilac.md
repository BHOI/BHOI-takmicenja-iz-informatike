# Djelilac
Dat vam je niz brojeva. Potrebno je naći koji broj u tom nizu dijeli sve ostale brojeve, odnosno da ostatak dijeljenja sa bilo kojim drugim brojem u nizu uvijek bude 0. Tačnije, u nizu *A* naći broj *A<sub>i</sub>* takav da *A<sub>i</sub> mod A<sub>j</sub> = 0*, za bilo koje *j*.

***Pročitaj sekciju izlaz ključne slučajeve***

## Ulaz
Na standardnom ulaz dat je broj *N* koji govori koliko brojeva ima u nizu *A*.

Potom u sljedećoj liniji se nalaze svi brojevi tog niza, odnosno *A<sub>i</sub>*.

### Ograničenja
```
0 < N < 100 000
0 < A[i] < 1 000 000 000
```
*u 70% slučajeva je `N < 500`*

## Izlaz
Na standardnom izlazu ispisati samo jedan broj - koji je to broj koji dijeli sve ostale brojeve u nizu.

Ukoliko ima više takvih brojeva, ispisati bilo koji. Ukoliko takav broj ne postoji, ispisati -1.

## Primjeri
### Ulaz 1
```
3
2 2 4
```
### Izlaz 1
```
2
```
### Ulaz 2
```
5
2 1 3 1 6
```
### Izlaz 2
```
1
```
### Ulaz 3
```
3
2 3 5
```
### Izlaz 3
```
-1
```
