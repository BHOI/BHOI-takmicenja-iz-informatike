# Ping-Pong

Mace vole brze stvari. Čovječe, zamislite još i ako mogu da skakuću!
Luna je posebna maca, ali, svakako, voli i neke stvari koje i druge mace vole: ping-pong loptice!

Anđela voli da se igra sa Lunom, pogotovo ujutro kada Luni treba najviše pažnje. No, svako od nas odrasta i život često postane pretrpan obavezama, pa je Anđela morala da osmisli igru koja je dovoljno jednostavna, ali opet zabavna.

Luna obožava ping pong loptice. Štaviše, ne voli uvijek da dobije isti broj ping pong loptica da ganja unaokolo. Zato, Anđela če veće prije, kada Luna utone u san, postaviti $N$ kutijica sa lopticama, gdje $i-ta$ kutijica ima $l_i$ ping-pong loptica, a Luna će ujutro ići od kutijice do kutijice i krenuti da razbacuje loptice na sve strane! Haos!

Anđela, svakako, ne voli previše nereda, ali i poznaje Lunu odlično: Luna će redom razbacivati loptice iz kutijica koje se smjenjuju po količini po striktnom pravilu: Količine moraju da rastu-pa-padaju, ili padaju-pa-rastu, i tako naizmjenično.

Na primjer, sljedeće kutijice su validni izbori: $5 \ < \ 10 \ > \ 3 \ < \ 4$, $2 \ > 1$ i $10 \ > \ 3 \ < \ 4 \ > \ 1 \ < \ 9$.

Luna neće nužno izabrati sve kutijice - izabraće najduži podniz kutijica, tj. krenuće od neke kutijice u nizu i nastaviće dokle god je moguće, bez preskakanja kutijica.

Anđela vas je zamolila za pomoć - koji je najduži podniz kutijica koji zadovoljava gorepomenuti uslov?

## Ulazni podaci

Prvi red ulaza sadrži $N$, broj kutijica sa ping-pong lopticama.\
Drugi red ulaza sadrži $N$ brojeva $l_i$ $(0 \leq \ i \lt \ N)$, broj ping-pong loptica u svakoj kutijici.

### Ograničenja
$1 \ \leq \ N   \ \leq \ 5 \ \cdot 10^5$ \
$0 \ \leq \ l_i \ \leq \ 10^5$

## Podzadaci

### Podzadatak 1 (52 bodova)
$N \ \leq \ 2500$

### Podzadatak 2 (48 bodova)
Bez dodatnih ograničenja. 

## Izlazni podaci

Potrebno je ispisati dužinu najdužeg podniza, takvog da se broj kutijica smjenjuje, kao što je opisano u tekstu zadatka.

## Primjeri
### Ulaz 1
```
5
1 3 2 4 5
```
### Izlaz 1
```
4
```
### Objašnjenje 1
Najduži podniz, u kojem se mijenja znak, je: $1 \ \lt \ 3 \ \gt \ 2 \ \lt \ 4$

### Ulaz 2
```
3
1 2 3
```
### Izlaz 2
```
2
```
### Objašnjenje 2
Najduži podniz, u kojem se mijenja znak, je: $1 \ \lt \ 2$.\
Imajte na umu da postoji i drugi validan niz dužine 2: $2 \ \lt \ 3$.
