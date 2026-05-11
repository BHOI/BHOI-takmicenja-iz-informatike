# Editorial: Svjetsko prvenstvo

## Ključna ideja

Svakom timu dodijelimo **poziciju u bracketu** (0-indeksiranu). Runda susreta određena je time koliko se te pozicije razlikuju.

## Pozicija u bracketu

Zamislimo bracket kao niz mjesta 0, 1, 2, ..., N-1 s lijeva na desno. Tim na poziciji i igra u prvoj rundi protiv tima na poziciji i XOR 1 (susjedna pozicija u paru). U drugoj rundi pobjednik pozicije i igra protiv pobjednika pozicije i XOR 2. U k-toj rundi igra se protiv para na poziciji i XOR 2^(k-1). Generalno, **dva tima se susreću u rundi koja odgovara poziciji najznačajnijeg bita u XOR-u njihovih pozicija**.

## Kako dodijeliti poziciju timu s rangom s?

Bracket je konstruisan rekurzivno. Tim s rangom s igra u prvoj rundi protiv tima s rangom N+1-s. Taj par čini "atom" bracketa. Unutar para, bolji tim (manji rang) dobija parnu poziciju, lošiji neparnu.

Nakon prve runde, pobjednici parova čine manji bracket od N/2 timova. Pozicija tima s rangom s u tom manjem bracketu je ista kao pozicija tima s rangom min(s, N+1-s) u bracketu veličine N/2. Rekurzivno se pozicija u manjem bracketu pretvara u poziciju u punom: množi se s 2 i dodaje 0 ili 1 ovisno o tome je li tim bolji ili lošiji u svom paru.

## Primjer za N=8

- Rang 1: pair_idx=1 (bolji), sub_pos za rang 1 u bracketu 4 = 0, pozicija = 2*0+0 = 0
- Rang 8: pair_idx=1 (lošiji), sub_pos = 0, pozicija = 2*0+1 = 1
- Rang 4: pair_idx=4 (bolji), sub_pos za rang 4 u bracketu 4 = 3, pozicija = 2*3+0 = 6
- Rang 5: pair_idx=4 (lošiji), pozicija = 2*3+1 = 7

Pozicije: 1->0, 8->1, 4->6, 5->7, 2->2, 7->3, 3->4, 6->5.

Rangovi 1 i 8 imaju pozicije 0 i 1, XOR = 1, najviši bit na poziciji 1 -> susrecu se u rundi 1. Rangovi 1 i 2 imaju pozicije 0 i 2, XOR = 2, najviši bit na poziciji 2 -> runda 2. Rangovi 1 i 4 imaju pozicije 0 i 6, XOR = 6, najviši bit na poziciji 3 -> runda 3. Odgovara primjerima iz zadatka.
