# Lutke

Lamija i Sumeja su sestre i vole se igrati sa lutkama - kako je Sumeja starija ona daje Lamiji da ona vodi igru. Ispred Lamije je niz od $N$ lutki, pobrojane od $1$ do $N$, s lijeva na desno. Za svaku lutku $i$ poznata je njena ljepota na početku kao broj $L_i$. Što je veći broj, to je lutka ljepša!

Lamija će prvo iz niza ukloniti lutku $a$, nakon čega je mjesto $a$ prazno. Nakon toga Lamija će uvijek uklanjati najmanje lijepu lutku pored mjesta sa kojeg je jedna lutka već uklonjena. Ovo znači da će Lamija uvijek odabrati jednu od najviše dvije potencijalne lutke - uvijek će odabrati onu koja je manje lijepa.

Sumeja će može na neku lutku staviti _krunu_ zbog koje će ta lutka postati ljepša i sigurno će postati jedna od 10 najljepših preostalih lutki. Ni u jednom trenutku neće dvije lutke u nizu imati istu ljepotu.

Kao što vidite, ako Sumeja ne stavi krunu ni na jednu više lutku onda možemo znati tačno kojim redoslijedom će Lamija sklanjati lutke. Trebate pomoći Sumeji da zna - ako više ne stavi ni jednu krunu - koliko će drugih lutki Lamija skloniti prije nego što skloni određenu lutku.

Vaš zadatak je napisati program koji prima 2 vrste naredbi:
- _Stavi krunu na lutku_ $i$, čime se lutka $i$ postane $e$-ta najljepša;
- _Nakon koliko drugih lutki će Lamija skloniti lutku_ $b?$

Na naredbe drugog tipa treba odgovoriti. Moguće je da ljepota lutke u nekom trenutku ne bude cijeli broj.

## Ulazni podaci
Prvi red ulaza sadrži cijele brojeve $N$ i $a$, broj lutki i broj prve lutke koju će Lamija skloniti.

Druga linija sadrži $N$ različitih cijelih brojeva $D_i$, razdvojeni razmakom, koji predstavljaju početne ljepote lutki.

Treća linija sadrži $Q$, broj naredbi koje program treba obraditi.

Idućih $Q$ linija sadrži narebu u jednom od oblika:
- `E i e` (slovo `E`, cijeli broj $i$ i cijeli broj $e$), što označava da se stavlja kruna na lutku $i$ i da ona postaje $e$-ta najljepša.
- `F b` (slovo `F` i cijeli broj `b`), što predstavlja pitanje - koliko će lutki biti sklonjeno prije nego što Lamija skloni lutku $b$?

### Ograničenja
$1 \leq N \leq 250\;000$

$1 \leq Q \leq 500\;000$

$1 \leq a, b, i, D_i \leq N$

$1 \leq e \leq 10$

## Podzadaci

### Podzadatak 1 (17 bodova)
$N, Q \leq 10\;000$

### Podzadatak 2 (16 bodova)
$N \leq 25\;000$ i na ulazu se nalazi najviše 500 naredbi tipa `F`.

### Podzadatak 3 (21 bod)
$Q \leq 100\;000$ i na ulazu se nalazi najviše 100 naredbi tipa `E`.

### Podzadatak 4 (46 bodova)
Bez dodatnih ograničenja.

## Izlazni podaci

Za svaku naredbu tipa `F` potrebno je ispisati jedan cijeli broj - broj lutki koje će Lamija skloniti prije zadane.

## Primjeri
### Ulaz 1
```
5 3
5 1 2 4 3
17
F 1
F 2
F 3
F 4
F 5
E 2 1
F 1
F 2
F 3
F 4
F 5
E 5 2
F 1
F 2
F 3
F 4
F 5
```
### Izlaz 1
```
4
1
0
2
3
4
3
0
1
2
4
3
0
1
2
```
### Objašnjenje 1
Prije postavljanja prve krune sklonile bi se lutke redom: 3, 2, 4, 5, 1.

Nakon postavljanja prve krune druga lutka postaje najljepša, tako da bi se lutke sklonile redom: 3, 4, 5, 2, 1.

Druga kruna ne mijenja redoslijed sklanjanja lutki, tako da i nakon nje je redoslijed: 3, 4, 5, 2, 1.
