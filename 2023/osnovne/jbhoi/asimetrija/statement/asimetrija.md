# Asimetrija
Gialle se igra Yu-Go-Ih kartama i trenutno je u procesu formiranja svojih `K` dekova. Dek je grupa od jedne ili više karti. Raspodjela karti u **tačno** `K` dekova naziva se **formacija**. Sve njegove karte, kojih ima `N`, trenutno su poredane jedna do druge ispred njega. Obzirom da nema puno vremena za odabir dekova, on će dekove izabrati na poprilično jednostavan način: prvih nekoliko karti (možda i samo jednu) odabrat će za prvi dek, sljedećih nekoliko za drugi i tako do kraja.

Svaka karta ima svoju brojčanu oznaku `A[i]` koja predstavlja snagu te karte. Razliku između najjače i najslabije karte u deku nazivamo **asimetrijom deka**. Ukoliko dek sadrži samo jednu kartu, njegova asimetrija je `0`. **Asimetrija formacije** je najveća asimetrija među `K` formiranih dekova.

Vaš zadatak je odrediti koja je najmanja moguća asimetrija formacije koji Gialle može postići. Drugim riječima, među svim mogućim formacijama koje se mogu kreirati od `N` karata, koja je najmanja asimetrija čitave formacije?

## Ulaz
Prva linija ulaza sadrži dva prirodna broja broja `N` i `K` koji su opisani u tekstu zadatka. Sljedeća linija sadrži N prirodnih brojeva, ne većih od , koji predstavljaju snage karti.

### Ograničenja
```
1 <= K <= N <= 1 000 000
1 <= A[i] <= 1 000 000 000
```
- Podzadatak 1 (10 bodova) - `K = N`
- Podzadatak 2 (15 bodova) - `K = 1`
- Podzadatak 3 (17 bodova) - `K = N - 1`
- Podzadatak 4 (23 boda) - `1 <= K <= N <= 1 000`, `A <= A[i] <= 1 000`
- Podzadatak 5 (35 bodova) - Bez dodatnih ograničenja

## Output
Prva i jedina linija izlaza sadrži jedan cijeli broj - najmanju moguću asimetriju formacije koju Gialle može postići.

## Primjeri
### Ulaz 1
```
5 5
1 2 3 4 5
```
### Izlaz 1
```
0
```
### Objašnjenje 1
Obzirom da Gialle pravi 5 dekova od 5 karti, svaka karta je dek za sebe, te je asimetrija formacije 0.
### Ulaz 2
```
5 4
1 10 9 3 4
```
### Izlaz 2
```
1
```
### Objašnjenje 2
Gialle može formirati dekove na sljedeći način: `{1}`, `{10, 9}`, `{3}`, `{4}`. Asimetrija drugog deka je *1*, a ostalih dekova je *0*, tako da je asimetrija čitave formacije *1*. Ne postoji formacije kod koje je asimetrija manja od *1*.
### Ulaz 3
```
5 1
1 4 3 100 2
```
### Izlaz 3
```
99
```
### Objašnjenje 3
Obzirom da sve karte idu u jedan dek, asimetrija tog deka bit će *100 - 1 = 99* i ovo je jedina moguća formacija.