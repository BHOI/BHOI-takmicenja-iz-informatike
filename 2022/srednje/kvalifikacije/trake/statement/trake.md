# Trake
Data vam je ploča za igru nije nužno pravougaonog oblika, ali se ipak sastoji od skupa međusobno povezanih jediničnih kvadratića. Tačnije, ploča za igru se sastoji od traka u obliku kolona poredanih jedna do druge s lijeva na desno. Svaka traka se sastoji od jednog ili više jediničnih kvadratića, a složene su tako da se dvije susjedne trake uvijek dodiruju barem duž jednog cijelog kvadratića. *Za vizuelni primjer pogledati sekciju "primjeri".*

U jednoj partiji igre, zadaju se početni i završni kvadratić te se traži udaljenost između ta dva kvadratića. Pritom, udaljenost definiramo kao broj koraka potreban da se dođe od jednog kvadratića do drugog ako je u svakom koraku dozvoljen skok na dodirujući kvadratić (gore, dolje, lijevo ili desno) koji se nalazi unutar ploče za igru.

Napišite program koji će za zadanu ploču, te za svaki zadani par početnih i završnih kvadratića odrediti njihovu udaljenost.

Kako bi mogli označiti pojedina polja, smatramo da se ploča za igru nalazi unutar kvadratne ploče koje se sastoji od redova označeni brojevima 1, 2, … odozgo prema dolje i kolona označeni brojevima 1, 2, … s lijeva na desno. Trake su označene brojevima od 1 do `N`. Traka `k` se nalazi u `k`-toj koloni ploče te je opisana sa dva broja `Ak` i `Bk` - red najgornjeg i najdonjeg kvadratića trake.

## Ulaz
U prvom redu nalaze se dva prirodna broja, `N` i `Q` - broj traka te broj parova početnih i završnih polja.

U `k`-tom od sljedećih redova nalaze se dva prirodna broja `Ak` i `Bk` - najgornji odnosno najdonji red kvadratića `k`-te trake. Za svake dvije dodirne trake postojat će barem jedan red takav da obje sadrže kvadratić u tom redu.

U svakom od sljedećih `Q` redova nalaze se po četiri prirodna broja `Rp`, `Cp`, `Rz`, `Cz` - red i kolona početnog te završnog kvadratića. Oba kvadratića će se nalaziti unutar ploče za igru.

### Ograničenja
```
1 <= N, Q <= 200 000
1 <= Ak <= Bk <= 1 000 000 000
1 <= Rp, Cp <= Rz, Cz <= 1 000 000 000
```
*U test podacima vrijednim 20% bodova vrijedi `N, Q <= 5000`.*

*U test podacima vrijednim dodatnih 40% bodova vrijedi `N <= 5000`.*

## Izlaz
Potrebno je ispisati `Q` redova. U `k`-ti red ispišite udaljenost između `k`-tog po redu para kvadratića sa ulaza.

*Napomena: Preporučujemo da koristite 64-bitni cjelobrojni tip podataka (long long)*.

## Primjeri
### Ulaz 1
```
4 3
2 3
1 4
3 4
2 3
2 1 3 2
3 1 3 4
2 1 2 4
```
<img style="width: 4cm" src="data:image/png;base64, iVBORw0KGgoAAAANSUhEUgAAAJcAAACUCAYAAACeC7vXAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAAHYcAAB2HAY/l8WUAAAU7SURBVHhe7dy/S5ZrHMfx7+PPBFMxdTMJxQiHVEzSwQYtEWywdHSoqSkJBzcnhwfRQFocJFJc/B8ikJSGnJzEpDQqJCh/W5p6zrluLolKfM7pnM99Def9gpu8vtPjfb8fuVu+iT/+YoBAmv8X+M8RF2SICzLEBRnigkzK/y0+efLEdnd3/SmMg4MDe/78ue3v71taWrjvw9HRkWVnZ1tjY6NlZWX5aRjfvn2L7kV6erqfhOE+w7179/zpRynjGhwctO7ubn8K4+3btzY1NWWzs7N27do1P43fzMyMXb161W7dumXl5eV+GsbY2JjV1dVZdXW1n4QxMTFhfX19/vSjlHENDw9bb2+vP4Xx+vVrGxkZsdLSUmttbfXT+D179iz6LO6beunSJT8NY2BgwG7cuGH19fV+EsZpffDOBRniggxxQYa4IENckCEuyBAXZIgLMsQFGeKCDHFBhrggQ1yQIS7IEBdkiAsyxAUZ4oIMcUGGuCBDXJAhLsgQF2SICzLEBRniggxxQYa4IENckCEuyBAXZE7dz7W8vGxDQ0PR9rpEIuGn8TveJlhQUGC5ubnRzyHs7OzY+vq65efnB91w6Gxvb0cbF90VikvHtdHZ2RltW/zZqXEtLi5aMpm0N2/eWEVFhZ/G7+XLl9bc3GwlJSXRZr9Q5ubm7MOHD9bU1GTnz5/30zAmJyftxYsXVlVV5Sfx29jYiL5oXV1d0SK6n6WMq7+/39rb2+3y5ct+Gr/Hjx9H+0jZLPhdT0+PbW1t2YMHD/wkfp8+fbLR0VG7e/fuiXHxzgUZ4oIMcUGGuCBDXJAhLsgQF2SICzLEBRniggxxQYa4IENckCEuyBAXZIgLMsQFGeKCDHFBhrggQ1yQIS7IEBdkiAsyxAUZ4oIMcUGGuCBDXJAhLsgQF2RS7ud6+PChlZWVWU5Ojp/Gz+2B+vLli+Xl5UVXKG6bn9ss6HaFHR4e+mkYWVlZ0VVcXOwn8XP34N27d9bW1vZ7y98GBwftypUrduHCBT+N39OnT6NfxN3I2tpaP43f/Py8ra6u2vT0tF28eNFP47eysmJ1dXXRysqbN2/6afzc8jn3bDo6Otgs+G8dbxZ0e0Dv3Lnjp/Fzkc/OztrXr1/ZLIj/J+KCDHFBhrggQ1yQIS7IEBdkiAsyxAUZ4oIMcUGGuCBDXJAhLsgQF2SICzLEBRniggxxQYa4IENckCEuyBAXZIgLMsQFGeKCDHFBhrggQ1yQIS7I/K24dnd3bWdnJ9jlFr/hV26F0kn3K87rNCn3cz169CiKK6Ts7GzLzc21s2fPWn5+vp/Gb3NzM7rOnDljRUVFfho/9zzW1taiuNy2w5DOnTtnLS0t/3z5m/vgyWQyerAhuZvotti5B1pVVeWn8VtYWLCPHz9aZmamNTQ0+Gn83KrIpaUly8jIsMLCQj8NwzVy//59Kykp8ZPvTo3LGR4ett7eXn8Kw23zGxkZYbOgd7xZ8Pr169HKyJBO64MXesgQF2SICzLEBRniggxxQYa4IENckCEuyBAXZIgLMsQFGeKCDHFBhrggQ1yQIS7IEBdkiAsyxAUZ4oIMcUGGuCBDXJAhLsgQF2SICzLEBRniggxxQYa4IJNyP9fAwIAVFBT4UxhubeXq6qq9evUqWngWysHBgVVWVtr79+9tb2/PT+N3/Dny8vKCL3/7/Pmz9ff3+9OPUsbl1iMeHh76UxhHR0c2Pj5uaWnh/9DOzc1ZTU1NtAAuJPdMbt++HXSNp5NIJKLVlSdJGRfwu3jnggxxQYa4IGL2J7ddaYcN/xKEAAAAAElFTkSuQmCC">
### Izlaz 1
```
2
3
5
```
### Ulaz 2
```
6 4
3 6
2 5
2 3
1 5
4 4
2 6
2 6 1 4
6 6 4 1
3 4 3 1
6 1 6 1
```
<img style="width: 4cm" src="data:image/png;base64, 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">
### Izlaz 2
```
7
9
3
0
```
