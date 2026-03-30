# Tunguzija
Faruk ide na zasluženi godišnji odmor u Tunguziju. Ali, kao i uvijek gužve na granici su ogromne. Granična kontrola se sastoji od dva dijela. Izlaza iz Bosne i ulaza u Tunguziju. Kada auto završi sa kontrolom za Bosnu, instantno ide na kontrolu za Tunguziju.

Kada jedno auto dođe na svoj red na izlazu u Bosnu, treba mu $A$ dana da prođe dalje. Slično, kada je auto na ulazu u Tunguziju, potrebno je $B$ dana da prođe. Faruk zna da ima $K$ auto ispred njega i zanima ga koliko će dugo čekati da napokon uđe u Tunguziju i koliko će auta biti ispred njega kada završi sa kontrolom za izlaz iz Bosne.

# Opis unosa
Na ulaz se unose 3 broja: $ A,B $  i $K$. 

$ 1 \le A,B,K \le 10^9. $
# Opis ispisa
Ispisati dva broja. Broj dana koliko će Faruk čekati kada da uđe u Tunguziju i koliko auta će biti ispred njega kada prođe izlaz iz Bosne.

# Podzadaci
$ (A \le B) $ - 30 poena

$ (A,B,K \le 10^4) $ - 30 poena

nema dodatnih ograničenja - 40 poena
# Primjeri unosa i ispisa
### Primjer 1:
#### Unos
```
1 1 4
```
#### Ispis
```
6 0
```
### Primjer 2:
### Unos
```
1 2 4
```
### Ispis
```
11 2
```
## Objašnjenje primjera 
Primjer 1: Faruk mora sačekati 5 dana da uđe u Bosnu. U tom trenutku će sva auta biti već gotova sa kontrolom tako da mora samo sačekati dodatni dan da prođe kontrolu za Tunguziju.

Primjer 2: Slovo ``` F ``` predstavlja Faruka, slovo ``` B ``` predstavlja prvu granicu, slovo ``` T ``` predstavlja drugu granicu i ``` x ``` predstavlja auto.

Dan 0: ``` F x x x x B T ```

Dan 1: ``` F x x x B x T ```

Dan 2: ``` F x x B x x T ```

Dan 3: ``` F x B x x T x ``` 

Dan 4: ``` F B x x x T x ```

Dan 5: ``` B F x x T x x ```

Dan 6: ``` B F x x T x x ```

Dan 7: ``` B F x T x x x ```

Dan 8: ``` B F x T x x x ```

Dan 9: ``` B F T x x x x ```

Dan 10: ``` B F T x x x x ```

Dan 11: ``` B T F x x x x ```