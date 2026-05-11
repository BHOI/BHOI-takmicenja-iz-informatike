# Editorial: Trka

## Ključna ideja

Svako od troje takmičara koristi drugačiju metriku za mjerenje udaljenosti u 3D prostoru. Zadatak se svodi na prepoznavanje o kojoj metrici se radi i direktno računanje.

## Rješenje

Neka su razlike koordinata dx = |x2 - x1|, dy = |y2 - y1|, dz = |z2 - z1|.

**Vanja** svake sekunde može promijeniti sve tri koordinate za po 1 istovremeno, pa svake sekunde napreduje za 1 u svakom smjeru neovisno. Optimalno je sve tri koordinate ispravljati paralelno, pa mu treba max(dx, dy, dz) sekundi. Ovo je poznato kao **Čebiševljeva udaljenost**.

**Ivana** putuje pravom linijom, pa joj treba floor(sqrt(dx^2 + dy^2 + dz^2)) sekundi (**Euklidska udaljenost**, zaokružena na dolje).

**Tarik** svake sekunde mijenja tačno jednu koordinatu za 1, pa mora "potrošiti" dx + dy + dz sekundi. Ovo je **Menhetenska udaljenost**.

## Zamka

Kod računanja Euklidske udaljenosti, direktno kastovanje (long long)sqrt(...) može dati netačan rezultat zbog greške u floating-point aritmetici. Sigurniji pristup: uzmi floor(sqrt(...)) pa provjeri je li (euclidean + 1)^2 <= dist_sq i ako jeste, uvećaj za 1.
