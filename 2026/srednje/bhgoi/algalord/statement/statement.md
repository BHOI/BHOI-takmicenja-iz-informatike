# Algalord

Lukin omiljeni metal bend _Rhapsody of Fire_ odlučio je da Anđelu i njenu mačku Lunu ovaj put doda u tekstove svojih pjesama. Kako je svim obožavateljima benda poznato, Algalord je tvrđava od najvećeg značaja u univerzumu, i Luna će ovaj put da brani Algalord od zlog cara Nekrona!

Jednostavnije rečeno, Luna je stvarno magična maca. Njene moći joj omogućavaju da otvara kapije između raznih lokacija unutar samog Algalorda, što povećava odbranu same tvrđave. Algalord ima $N$ važnih lokacija (obilježenih prirodnim brojevima), koje su na početku ove priče nepovezane (tj. ne postoje otvorene kapije između njih).

Luna će otvoriti ukupno $Q$ kapija. Svaka kapija povezuje lokacije $u$ i $v$, i omogućava prolaz iz lokacije $u$ u lokaciju $v$. Važno je napomenuti da su kapije jednosmjerne — ako postoji kapija iz $u$ u $v$, nije nužno moguće vratiti se iz $v$ u $u$.

Za odbranu tvrđave ključno je da se heroji mogu efikasno kretati. Zbog toga posmatramo **magične regione**.

Kažemo da dvije lokacije pripadaju istom magičnom regionu ako je moguće krenuti iz jedne i stići do druge (kroz jednu ili više kapija), te se vratiti nazad drugim putem. Drugim riječima, unutar jednog magičnog regiona, svaka lokacija je dostižna iz svake druge lokacije.

Herojima ističe vrijeme, te ih zanima kako situacija napreduje, kako bi se mogli bolje organizovati. Zbog toga, vaš zadatak je jasan: nakon svakog otvaranja kapije, ispišite koliko trenutno postoji **magičnih regiona**.

## Ulazni podaci

Prvi red ulaza sadrži dva cijela broja $N$ i $Q$ — broj lokacija i broj kapija koje će Luna otvoriti.

U narednih $Q$ redova nalaze se parovi brojeva $u$ i $v$, koji opisuju kapiju iz $u$ u $v$.

### Ograničenja

$1 \leq N, Q \leq 10^5$

## Podzadaci

### Podzadatak 1 (30 bodova)
$N, Q \leq 1\;000$

### Podzadatak 2 (30 bodova)
$N, Q \leq 10\;000$

### Podzadatak 3 (40 bodova)
Bez dodatnih ograničenja.

## Izlazni podaci

Nakon svakog otvaranja kapije, ispisati broj **magičnih regiona**.

## Primjeri

### Ulaz 1
```
3 2
1 2
2 1
```

### Izlaz 1
```
3
2
```

### Objašnjenje 1

Na početku postoje 3 magična regiona — svaka lokacija čini region za sebe.

Nakon prve operacije dodaje se kapija $1 \to 2$, ali još uvijek nije moguće vratiti se iz $2$ u $1$, pa ove dvije lokacije ne čine isti region. Broj regiona ostaje $3$.

Nakon druge operacije dodaje se kapija $2 \to 1$, čime lokacije $1$ i $2$ postaju međusobno dostižne i formiraju jedan magični region. Ukupan broj regiona je sada $2$.

### Ulaz 2
```
3 3
1 2
2 3
3 1
```

### Izlaz 2
```
3
3
1
```
### Objašnjenje 2

Na početku postoje 3 magična regiona — svaka lokacija čini region za sebe.

Nakon prve operacije dodaje se kapija $1 \to 2$, ali još uvijek nije moguće vratiti se iz $2$ u $1$, pa ove dvije lokacije ne čine isti region. Broj regiona ostaje $3$.

Nakon druge operacije dodaje se kapija $2 \to 3$, ali i dalje ne postoji put $2 \to 1$, ili $3 \to 1$.

Nakon treće operacije, dodaje se kapija $3 \to 1$, te je sada moguće naći put od $3$ do $1$, te od $2$ do $1$ (i obrnuto), što stvara magični region. Sada su sve lokacije dio istog magičnog regiona.