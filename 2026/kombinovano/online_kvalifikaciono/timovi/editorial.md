# Editorial: Timovi

## Ključna ideja

Uslov za tim je **stroga dvosmjerna dostižnost**: za svaka dva člana x i y, mora postojati put od x do y i put od y do x. Ovo je tačno definicija **jako povezane komponente (SCC)** u usmjerenom grafu.

Odgovor je veličina najveće SCC.

## Algoritam: Kosarajuov

Kosarajuov algoritam nalazi sve SCC u O(N + M):

1. **Prva faza:** DFS na originalnom grafu, zapamti čvorove po redoslijedu završavanja (u niz `order`).

2. **Druga faza:** DFS na **obrnutom grafu** (sve grane okrenute), obrađuj čvorove u **obrnutom redoslijedu završavanja** iz prve faze. Svaki DFS stablo u ovoj fazi je jedna SCC.

## Zašto obrnuti graf?

Svaki čvor koji je dostižan iz nekog čvora v u originalnom grafu i istovremeno dostižan do v u obrnutom grafu pripada istoj SCC kao v. Obrada u obrnutom redoslijedu završavanja garantuje da DFS u drugoj fazi ne "prelije" u drugu SCC.

## Alternativa: Tarjanov algoritam

Tarjanov algoritam postiže isto u jednom prolasku DFS-a koristeći low-link vrijednosti i stog, ali je nešto složeniji za implementaciju. Oba algoritma su O(N + M).
