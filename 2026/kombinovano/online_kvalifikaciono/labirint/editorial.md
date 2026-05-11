# Editorial: Labirint

## Ključna ideja

Minimizujemo broj **skretanja**, a ne broj koraka. Ključno je modelovati problem kao graf s odgovarajućim cijenama grana i primijeniti **0-1 BFS**.

## Modelovanje

Stanje je trojka (red, kolona, smjer dolaska). Smjer je jedan od 4 vrijednosti: gore, dolje, lijevo, desno.

Cijene prijelaza:
- Nastavak u **istom smjeru**: cijena 0 (nema skretanja).
- Kretanje u **drugom smjeru**: cijena 1 (jedno skretanje).

Odgovor je minimalna cijena medu svim stanjima (red_C, kolona_C, d) za cilj C.

## Početni uvjeti

Iz startnog polja S nema smjera dolaska. Budući da se **prvi korak broji kao skretanje**, inicijalizujemo BFS direktno postavljanjem svakog dostupnog susjeda S sa cijenom 1 za odgovarajući smjer. Na taj način ne trebamo poseban "null smjer" za start.

## Algoritam: 0-1 BFS

0-1 BFS koristi `deque` umjesto obične red ili prioritetnog reda:
- Prijelaz s cijenom 0: ubaci na **prednju** stranu deque-a.
- Prijelaz s cijenom 1: ubaci na **stražnju** stranu deque-a.

Ovo garantuje O(H * W * 4) vremensku složenost, kao i obični BFS.

## Zašto ne Dijkstra?

Dijkstra bi radila, ali je sporija (O(H * W * 4 * log(H * W))). Budući da su cijene samo 0 ili 1, 0-1 BFS je optimalan izbor.
