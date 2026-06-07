# Brisanje

Esmir je na tablu napisao $N$ cijelih brojeva. Kaže da je neki broj na tabli suvišan ako se može dobiti kao zbir jednog ili više preostalih brojeva sa table (pri čemu se isti broj smije koristiti više puta, ali se broj koji se provjerava ne računa kao sabirak samom sebi). Esmir želi ukloniti sve suvišne brojeve sa table.

Koliko brojeva će Esmir ukloniti?

## Ulazni podaci

U prvom redu se nalazi cijeli broj $N$, broj brojeva na tabli.

U drugom redu se nalazi $N$ cijelih brojeva $a_1, a_2, \ldots, a_N$, brojevi napisani na tabli.

### Ograničenja

$1 \leq N \leq 100\;000$

$1 \leq a_i \leq 1\;000\;000$

## Podzadaci

### Podzadatak 1 (12 bodova)
Svi brojevi na tabli su stepeni broja $2$ (tj. oblika $2^k$ za neki $k \geq 0$).

### Podzadatak 2 (25 bodova)
$N \leq 20$

### Podzadatak 3 (20 bodova)
$a_i \leq 1\;000$

### Podzadatak 4 (43 boda)
Bez dodatnih ograničenja.

## Izlazni podaci

Na jedinoj liniji izlaza ispišite koliko brojeva Esmir može ukloniti sa table.

## Primjeri

### Ulaz 1
```
4
3 5 6 7
```

### Izlaz 1
```
1
```

### Objašnjenje 1

Broj $6$ je suvišan jer $6 = 3 + 3$. Ostali brojevi se ne mogu dobiti kao zbir drugih brojeva sa table ($3$ je najmanji, $5$ se ne može dobiti od samih trojki, a $7$ također ne).

### Ulaz 2
```
3
2 4 8
```

### Izlaz 2
```
2
```

### Objašnjenje 2

Broj $4$ je suvišan jer $4 = 2 + 2$. Broj $8$ je također suvišan jer $8 = 2 + 2 + 2 + 2$ (ili $8 = 4 + 4$, ali pošto je $4$ već uklonjen, koristimo samo $2$). Jedino broj $2$ ostaje na tabli.

### Ulaz 3
```
3
3 5 7
```

### Izlaz 3
```
0
```

### Objašnjenje 3

Nijedan broj se ne može dobiti kao zbir preostalih: $3$ je najmanji, $5 $ ≠ $ 3 + 3$, a $7 $ ≠ $ 3 + 3$ i $7 $ ≠ $ 5 + 5$ i $7 $ ≠ $ 3 + 5$ (jer je $3 + 5 = 8 $ ≠ $ 7$).

### Ulaz 4
```
2
5 5
```

### Izlaz 4
```
1
```

### Objašnjenje 4

Jedna petica je suvišna jer se može dobiti kao zbir jedne preostale petice ($5 = 5$).


