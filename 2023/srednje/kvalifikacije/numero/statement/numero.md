# Numero
U našim krajevima je brzo postala popularna nova igra *"Numero"*. Pravila igre su takva da jedan igrač kaže drugome pozitivan cijeli broj `X` koji se sastoji od `N` cifara `a[1], a[2], ... a[N]` i pozitivan cijeli broj `K` .

Neki broj `b[1], b[2], ... b[M]` se naziva *"numero"* ako važi `b[i] = b[i + k]` za svako `i`, takvo da `1 <= i <= M – K`.

Da bi pobijedio, drugi igrač mora odgovoriti najmanjim *"numero"* brojem `Y`, takvim da je `Y >= X`.

Nikola je odučio da vara i da unajmi Vas da mu napišete program koji bi mu ovo brzo odradio, tako da bi mogao da pobjedjuje djecu u skoli.

## Ulaz
Prva linija na ulazu sadrži dva pozitivna cijela broja `N` i `K` - broj cifara broja `X` i broj `K` koji je opisan gore.

Druga linija sadrži `N` pozitivnih cijelih brojeva `A[1], A[2], ... A[N]` koji označavaju cifre broja `X`.

### Ograničenja
```
K < N
2 <= N <= 200000
1 <= K < N
A[1] != 0 (prva cifra nikad nije nula)
0 <= A[i] <= 9
```

### Podzadaci
* Podzadatak 1 (20 bodova): `N <= 10`
* Podzadatak 2 (30 bodova): `K <= 2`
* Podzadatak 3 (50 bodova): Bez dodatnih ograničenja

## Izlaz
U prvoj liniji ispišite cijeli broj `M` – broj cifara broja `Y`

U drugoj liniji ispišite `M` cifara `B[1], B[2], ... B[M]` - cifre broja `Y`

## Primjeri
### Ulaz 1
```
3 2
353
```
### Izlaz 1
```
3
353
```
### Ulaz 2
```
4 2
1234
```
### Izlaz 2
```
4
1313
```