# AJOI
Upravo je završen drugi dan Antarktičke juniorske olimpijade iz informatike (AJOI) *2023*. Dakle, AJOI se radi dva dana i svaki dan učenici moraju riješiti po *3* zadatka. Svaki zadatak iznosi *100* bodova, mada učenici mogu dobijati i parcijalne bodove. Pretpostavimo da je svaki učenik dobio cijeli broj bodova na svakom zadatku. Medalje se određuju na osnovu ukupnog broja bodova na svim zadacima prateći sljedeći postupak:

1. Najmanje najboljih *1/12* od ukupnog broja takmičara dobiva zlatnu medalju. Neka je `x` broj učenika koji je osvojio zlatnu medalju. (Naprimjer: ako je broj takmičara *13*, onda je *1/12* od ukupnog broja takmičara jednak *1.083*. Najmanje *1.083* takmičara dobiva zlatnu medalju. Budući da *1.083* nije cijeli broj, onda možemo zaključiti da najmanje *2* takmičara dobiva zlatnu medalju). Kako bismo odredili tačan broj učenika koji je osvojio zlatnu medalju, potreban je dodatni uslov. Dakle, `x` je minimalan broj takav da najboljih `x` takmičara ima striktno više bodova od ostalih takmičara. Najboljih `x` takmičara osvaja zlatnu medalju.
2. Najmanje najboljih *1/4* od ukupnog broja takmičara dobiva zlatnu ili srebrenu medalju. Neka je `y` broj učenika koji je osvojio zlatnu ili srebrenu medalju. Kako bismo odredili tačan broj učenika koji je osvojio zlatnu ili srebrenu medalju, potreban je dodatni uslov. Dakle, `y` je minimalan broj takav da najboljih `y` takmičara ima striktno više bodova od ostalih takmičara. Najboljih `y` takmičara osvaja zlatnu ili srebrenu medalju.
3. Najmanje najboljih *1/2* od ukupnog broja takmičara dobiva neku medalju. Neka je `z` broj učenika koji je osvojio neku  medalju. Kako bismo odredili tačan broj učenika koji je osvojio neku medalju, potreban je dodatni uslov. Dakle, `z` je minimalan broj takav da najboljih `z` takmičara ima striktno više bodova od ostalih takmičara. Najboljih `z` takmičara osvaja neku medalju.
4. Ostali učenici nažalost ne dobijaju medalju.

Nakon što su završili izradu zadataka, morali su sačekati sat vremena kako bi dobili konačan ranking. Međutim, učenici nisu mogli čekati rezultate, te su odlučili da sami saznaju koju će medalju osvojiti. Naime, svaki učenik je napisao bodove na svakom od **6** zadataka u jedan Google Docs document koji mogu vidjeti svi takmičari. Nakon što su svi napisali svoje bodove, zanima ih koju su medalju osvojili. Dakle, vaš zadatak je napraviti program koji ispisuje za svakog učenika da li je osvojio medalju i ukoliko jest, da ispisuje koju je medalju osvojio. 

## Ulaz
Prva linija na ulazu sadrži jedan prirodan broj `N` – broj učenika na olimpijadi.
Zatim se unosi `N` linija. U `i`-toj liniji se unosi **6** brojeva koji predstavljaju broj bodova `i`-tog učenika na svakom od **6** zadataka.

### Ograničenja
```
12 <= N <= 100 000
0 <= broj bodova po zadatku <= 100
```
### Podzadaci
* Podzadatak 1 (5 bodova): Svi učenici su imali *100* bodova na svakom zadatku.
* Podzadatak 2 (14 bodova): Svi učenici su imali *0* ili *100* bodova na svakom zadatku.
* Podzadatak 3 (26 bodova): `12 <= N <= 2000`
* Podzadatak 4 (55 bodova): Bez dodatnih ograničenja.

## Izlaz
Izlaz sadrži `N` linija. Svaka linija počinje sa `Ucenik i:` gdje `i` predstavlja redni broj linije u izlazu. Zatim,

- Ukoliko je učenik `i` osvojio medalju odmah ispisujete u istoj liniji `DA`. Zatim, odvojite razmak i ispišete `zlato` ukoliko je osvojio zlato ili `srebro` ukoliko je osvojio srebro ili `bronza` ukoliko je osvojio bronzu.
- Ukoliko učenik `i` nije osvojio medalju samo odmah ispišete u istoj liniji `NE`.

Pogledati primjer za bolje razumijevanje.

## Primjeri
### Ulaz 1
```
12
100 100 100 100 100 100
20 20 30 40 10 20
30 30 100 92 12 28
15 24 31 26 23 35
98 100 12 1 13 14
14 13 100 92 92 1
14 12 11 10 8 5
16 100 100 100 100 1
100 100 100 100 100 100
100 100 100 100 100 100
100 100 100 100 100 100
1 1 1 1 1 1
```
### Izlaz 1
```
Ucenik 1:DA zlato
Ucenik 2:NE
Ucenik 3:NE
Ucenik 4:NE
Ucenik 5:NE
Ucenik 6:DA bronza
Ucenik 7:NE
Ucenik 8:DA bronza
Ucenik 9:DA zlato
Ucenik 10:DA zlato
Ucenik 11:DA zlato
Ucenik 12:NE
```
### Objašnjenje 1
Svaki učenik je ostvario sljedeći broj bodova:
* Učenik 1: 600
* Učenik 2: 140
* Učenik 3: 292
* Učenik 4: 154
* Učenik 5: 238
* Učenik 6: 312
* Učenik 7: 60
* Učenik 8: 417
* Učenik 9: 600
* Učenik 10: 600
* Učenik 11: 600
* Učenik 12: 6

