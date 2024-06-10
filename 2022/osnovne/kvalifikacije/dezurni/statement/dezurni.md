# Dežurni
U nekoj školi nastavnici su odlučili da raspored dežurnih učenika učine malo zanimljivijim, te su odlučili da ručno prilagode učenike. Svaki dan su na dežuri dva učenika. U ovoj školi jedan učenik može biti na dežuri više dana.

Također su vam poznata i dva imena učenika koji počinju sa dežurom prije implementacije ovih rasporeda.

Nastavnici su napisali za svaki dan dva imena: prvo ime je koji učenik prestaje biti na dežuri taj dan, a drugo ime je koji je novi učenik koji će biti na dežuri taj dan.

Vaš zadatak je da napišete za svaki dan dežure koja s to dva učenika koji trebaju biti na dežuri.

Obavezno obratiti pažnju da se pri ispisu ne mijenja redosljed učenika na dežuri. Na primjer, ako je na prvom mjestu bio učenik1, on i na sljedećem danu ostaje na prvom mjestu, ukoliko nije smijenjen od nastavnika. Ukoliko je ipak smijenjen, na primjer sa učenik2, onda učenik2 preuzima prvo mjesto.

## Ulaz
* Na prvoj liniji standardnog ulaza nalaze se dva imena: to su učenici koji su prije implementacije ovih rasporeda bili na dežuri
* Na drugoj liniji se nalazi broj `N` - za koliko dana su nastavnici napisali smjene učenika za dežuru
* U narednih `N` linija se nalaze po dva imena:
  * Prvo ime govori koji je učenik koji na taj dan **prestaje** biti dežurni
  * Drugo ime govori koji je učenik koji na taj dan **počinje** biti dežurni

### Ograničenja
```
1 <= N < 1000
```
* Dužina svakog imena između 1 i 10 karaktera, uključujući i dužine 1 i 10
* Svako ime ima samo karaktere engleske abecede

## Izlaz
Na izlazu ispisati `N + 1` linija, svaka da sadrži po 2 imena - koja su to dva učenika koji taj dan dežuraju. Prvi dan su uvijek oni učenici koji su dežurali prije implementacije novog rasporeda.

Obavezno voditi pažnju o redosljedu učenika pri ispisu (opisano u glavnom dijelu zadatka).

## Primjeri
### Ulaz 1
```
amar adem
4
amar ivana
adem mustafa
mustafa nick
nick jovana
```
### Izlaz 1
```
amar adem
ivana adem
ivana mustafa
ivana nick
ivana jovana
```
* Nakon dana 1, `amar` je smijenjen a `ivana` postaje novi dežurni.
* Nakon dana 2, `adem` je smijenjen a `mustafa` postaje novi dežurni.
* Nakon dana 3, `mustafa` je smijenjen a `nick` postaje novi dežurni.
* Nakon dana 4, `nick` je smijenjen a `jovana` postaje novi dežurni.

### Ulaz 2
```
jo chris
2
chris layla
jo martina
```
### Izlaz 2
```
jo chris
jo layla
martina layla
```