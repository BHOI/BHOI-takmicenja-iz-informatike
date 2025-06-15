# Povlačenje užeta

Povlačenje užeta (eng. _tug of rope_) je igra u kojoj dva tima... povlače uže. Povlače isto uže sa suprotnih strana i tim koji je snažniji uglavnom i pobijedi. Kako ste vi postavljeni za glavu komiteta zabave na JBOI 2026 vaša dužnost je rasporediti takmičare u dva tima tako da su timovi što sličniji po ukupnoj snazi. Snaga tima je jednaka zbiru snaga njegovih članova. Vama je poznata snaga svakog takmičara.

Kako se ukupno $2N$ takmičara prijavilo tako će se svaki tim sastojati od po $N$ članova. Uže ima $N$ mjesta na lijevoj strani i $N$ mjesta na desnoj strani. Kao što vam je poznato ovi takmičari su izbirljivi i svako ima jedno mjesto na lijevoj strani i jedno mjesto na desnoj strani na kojem su voljni biti. Takmičari su označeni brojevima od $1$ do $2N$.

Vaš zadatak je odgovoriti na sljedeće pitanje: da li je moguće rasporediti takmičare u timove tako da je svako na mjestu na kojem su voljni biti, dva takmičara nisu na istom mjestu i snage timova se ne razlikuju za više od $K$?

## Ulazni podaci
Prvi red ulaza se sastoji od cijelih brojeva $N$ i $K$, broja članova po timu i maksimalne dozvoljene razlike u snazi timova. 

Idućih $2N$ redova opisuje po jednog takmičara i sastoji se od cijelih brojeva $L_i$, $R_i$ i $S_i$, prihvatljivog mjesta na lijevoj strani užeta, prihvatljivog mjesta na desnoj strani užeta i snagu _i_-tog takmičara. 

### Ograničenja
$3 \leq N \leq 30\;000$

$0 \leq K \leq 20N$

$1 \leq L_i, R_i \leq N$

$1 \leq S_i \leq 20$

## Podzadaci

### Podzadatak 1 (18 bodova)
$N \leq 10$

### Podzadatak 2 (30 bodova)
$N \leq 2\;000$

### Podzadatak 3 (23 boda)
$S_i = 1$ 

### Podzadatak 4 (29 bodova)
Bez dodatnih ograničenja.

## Izlazni podaci
Potrebno je ispisati `YES` ili `NO`, u ovisnosti od toga da li je moguće rasporediti takmičare u dva tima poštujući navedena ograničenja.

## Primjeri
### Ulaz 1
```
4 1
1 1 1
2 1 2
2 2 8
1 2 2
3 3 5
3 3 2
4 4 1
4 4 2
```
### Izlaz 1
```
YES
```
### Objašnjenje 1
Možemo takmičare $1$, $3$, $6$ u $7$ rasporediti na lijevu stranu užeta, čime dobijemo ukupnu snagu $1+8+2+1=12$, a preostale takmičare $2$, $4$, $5$ i $8$ na desnu stranu, čime dobijemo snagu $2+2+5+2=11$. Dobijamo razliku između snaga tačno $1$.

### Ulaz 2
```
2 5
1 1 1
1 2 4
2 2 1
2 1 4
```
### Izlaz 2
```
NO
```
### Objašnjenje 2
Oba takmičara snage $4$ moraju biti na istom timu, dakle razlika u snazi timova mora biti najmanje $6$. 