# Oblakinator

Zli Dr. Heinz Doofenshmirtz je svojim novim izumom _Oblakinatorom_ odlučio pokrenuti svoj najzlobniji plan do sada - kišom će blago unezgoditi planove svojih najvećih neprijatelja koji se kupaju na plaži.

_Oblakinator_ može stvoriti dvije vrste oblaka - kumulonimbuse širine $W$ i nimbostratuse širine $2W$. Svaki od $N$ neprijatelji koje ovaj zlikovac želi unezgoditi se nalaze na istoj plaži na lokacijama $A_i$.

_Oblakinator_ je ograničen u broju oblaka koje može napraviti - može napraviti do $P$ kumulonimbusa i $Q$ nimbostratusa, ali povećanjem napajanja se $W$ može povećavati proizvoljno mnogo. Ipak, Dr. Doofenshmirtz je savjestan o negativnim efektima potrošnje suvišne količine električne energije i zamolio je vas da odredite minimalno $W$ potrebno kako bi unezgodio sve svoje neprijatelje. 

Kako bi nekoga unezgodno potrebno je da se preko njega nalazi barem jedan od pomenutih oblaka. Oblaci pokrivaju $W$, odnosno $2W$ uzastopnih metara plaže, i mogu se preklapati. Možete pretpostaviti da je plaža savršeno prava i lokacije neprijatelja se izražavaju u metrima udaljenim od lijevog kraja plaže. 

## Ulazni podaci
Prvi red sadrži 3 cijela broja $N$, $P$, i $Q$, broj neprijatelja, broj kumulonimbusa i broj nimbostratusa koje _Oblakinator_ može proizvesti, redom.

Idućih $N$ redova sadrži po jedan cijeli broj $A_i$, udaljenost neprijatelja od lijevog kraja plaže. 

### Ograničenja
$1 \leq N \leq 2\;000$

$1 \leq P \leq 100\;000$

$1 \leq Q \leq 100\;000$

$1 \leq A_i \leq 1\;000\;000\;000$

## Podzadaci

### Podzadatak 1 (6 bodova)
$P=1$

$Q=1$

### Podzadatak 2 (35 bodova)
$N \leq 100$

### Podzadatak 3 (17 bodova)
$Q=1$

### Podzadatak 4 (42 boda)
Bez dodatnih ograničenja.

## Izlazni podaci
Potrebno je ispisati jedan broj - minimalna vrijednost $W$ potrebna da Dr. Doofenshmirtz svim neprijateljima unezgodi dan.

## Primjeri
### Ulaz 1
```
4 1 1
3
7
8
10
```
### Izlaz 1
```
2
```
### Objašnjenje 1
Sa $W=2$ može se napraviti kumulonimbus (širine $2$) koji prekriva `3` i `4`, te nimbostratus koji prekriva `7`, `8`, `9` i `10`. Ovim su svi neprijatelji unezgođeni, a to nije moguće postići sa $W=1$.

### Ulaz 2
```
13 3 2
33
66
99
10
83
68
19
83
93
53
15
66
75
```
### Izlaz 2
```
9

```

