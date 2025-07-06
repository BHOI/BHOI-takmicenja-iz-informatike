# Igra na tabiji
Fuke i Mujke su odlučili da prošetaju jednog dana poslije škole do Fuketovog najdražeg mjesta – Bijela tabija. Nakon puno mukotrpnog hodanja, stigli su na Bijelu tabiju gdje su napravili predah kako bi uživali u prekrasnoj prirodi. Uz užitak u prekrasnoj prirodi, odlučili su taj predah provesti igrajući jednu igru. Dakle,

1. Broj `X!` je napisan na papiru *(X! = 1 * 2 * ... * (X-1) * X)*
2. Fuke i Mujke naizmjenično igraju poteze, gdje Fuke igra prvi
3. U svakom potezu, trenutni igrač izabere prirodan broj `D` koji je djeljiv sa maksimalno `Y` prostih brojeva, i koji nije veći od trenutnog broja na papiru
4. Ukoliko je broj na papiru bio `A`, on se obriše i zamijeni se brojem `A-D`
5. Kada jedan igrač napiše `0` na tabli, igra završava i taj igrač pobjeđuje.

Za date `X` i `Y`, pomozite im tako što ćete odrediti ko će biti pobjednik ove igre ako oba igrača igraju optimalno.

Napomena:

Broj nazivamo prostim ukoliko mu je broj djelilaca tačno **2** (npr: **2**, **3**, **5**, **7**, **11** su prosti brojevi). Broj **1** nije prost broj u ovom zadatku.

## Ulaz
Prva linija ulaza sadrži jedan prirodan broj `T` – broj testnih slučajeva.

Slijedi `T` idućih linija:

Svaka linija sadrži 2 prirodna broja `X` i `Y`.

### Ograničenja
```
1 <= T <= 100 000
1 <= X, Y <= 1 000 000
```
*Za 10% bodova važi `Y = 1`*.

*Za dodatnih 20% bodova važi `1 <= T <= 100` i `1 <= X <= 6`*.

## Izlaz
Za svaki testni slučaj, ispisati po jednu liniju koja će sadržati string `Fuke` ako Fuke pobjeđuje, ili string `Mujke` ako Mujke pobjeđuje. Obratiti pažnju na velika i mala slova, string mora biti identičan kao u postavci.

## Primjeri
### Ulaz 1
```
3
1 2
3 1
2021 42
```
### Izlaz 1
```
Fuke
Mujke
Mujke
```
Prvi testni slučaj: 

Pošto `D = 1` je djeljivo s `0` prostih brojeva, Fuke će u prvom potezu izabrati `D = 1` pa će novonastali broj biti 0 i Fuke će pobijediti u tom potezu.

Drugi testni slučaj:

`X! = 6`. Fuke mora izabrati u prvom potezu `D` između `1` i `5` budući da je `6` djeljiv s 2 prosta broja (a `Y = 1`). Onda, Mujke može izabrati `6 – D`, tako da će novonastali broj biti `0`, i Mujke će pobijediti.
