// Neka je A proizvod prvih (Y+1) prostih brojeva. Fuke pobjeđuje ukoliko X! nije djeljiv s A,
// inače Mujke pobjeđuje. Neka je trenutni broj na ploči N. Nazovimo broj dobar ukoliko je on
// djeljiv s A. U jednom potezu, ne možemo ići s dobrog broja(N) na dobri broj(m), jer m=N-D a
// pošto N i m su djeljivi s A, onda mora i D biti djeljiv s A, ali D treba biti djeljiv s
// maksimalno Y prostih brojeva (a ako je D djeljiv s A, onda D će biti djeljiv s barem Y+1
// prostih brojeva). I također možemo ići s lošeg broja(N) na dobri broj(m),tako što ćemo
// oduzeti od N ostatak pri dijeljenju N sa A, tj. D = N%A. Tj. ako N= A*k+r gdje je r ostatak
// pri dijeljenju N sa A), 0<=r<A. Onda D=r.

// 1) Dokažimo da je D djeljivo s maksimalno Y prostih brojeva ako je D=N%A=r. Pretpostavimo da
// je D djeljivo s više od Y prostih brojeva (tj.sa barem Y+1 prostih brojeva). To znači da je
// D sigurno veće ili jednako od proizvoda prvih Y+1 prostih brojeva, tj. da je D sigurno veće
// ili jednako od A. Međutim D=r< A, pa treba D<A. Tako da ne može vrijediti D>A. Kontradikcija.

// Također D<=N što je ok (jer r<A*k+r)

// Pa m = N-D = N-N%A = A*k+r-r = A*k što znači da je m djeljiv s A pa je m dobar.

// Ako X! nije djeljiv s A, prvi igrač počinje s lošim brojem, i može uvijek namjestiti da
// zamijeni loš broj s dobrim brojem, i drugi igrač će morat dobar broj pretvoriti u loš broj
// (pošto smo dokazali da ne možemo ići s dobrog broja na dobri broj). I ovo će se ponavljati
// sve do kraja igre. Budući da je 0 dobar broj, prvi igrač će pobijediti (jer drugi igrač će
// uvijek morati zamijeniti dobar broj s lošim brojem).

// Ako X! je djeljiv s A, prvi igrač počinje s dobrim brojem, i morat će ga pretvorit u loš broj
// (pošto smo dokazali da ne možemo ići s dobrog broja na loš broj).  Pa drugi igrač će moći loš
// broj pretvoriti u dobar broj, i ovo će se ponavljati sve do kraja igre. Budući da je 0 dobar
// broj, drugi igrač će pobijediti (jer će on uvijek napisati dobar broj nakon njegovog poteza,
// dok će prvi igrač uvijek napisati loš broj nakon njegovog poteza).

// I onda trebamo provjeriti da li je X! djeljiv s A. Tj. da li X! je djeljivo s prvih (Y+1)
// prostih brojeva. Ukoliko su svi ti prosti brojevi manji ili jednaki X, onda je X! djeljivo s
// prvih (Y+1) prostih brojeva(jer X!=1*2*...*X).

// Dakle X! je djeljivo s prvih (Y+1) prostih brojeva, ako je broj prostih brojeva manjih ili
// jednakih X >= Y+1.
// Neka je bo[x] = broj prostih brojeva manjih ili jednakih x.
// Trebamo provjeriti da li bo[x]>=(Y+1). Ukoliko to vrijedi, ispišemo „Mujke“, inače ispišemo
// „Fuke“.

// Sad trebamo izračunat bo[x]. Odmah na početku možemo izračunati bo[i] za sve i od 1 do 1000000.
// Definišimo niz prost[i].
// I neka prost[i] = 0 ukoliko je i prost broj ili 1, a prost[i]=1 ukoliko i nije prost broj.
// I to možemo uraditi pomoću eratostenovog sita (dakle ako je i prost broj, onda svi brojevi
// djeljivi s i nisu prosti brojevi). 
// I onda bo[1]=0, bo[i]=bo[i-1]+prost[i] za svako i>=2 (dakle broj prostih brojeva manjih ili
// jednakih od i-1 i još vidimo je li i prost broj (zato imamo prost[i]).



#include <bits/stdc++.h>
using namespace std;
int prost[1000001];
int bo[1000001];
int main()
{
    prost[1] = 0;
    bo[1] = 0;
    for (int i = 2; i <= 1000000; i++)
    {
        bo[i] = bo[i - 1];
        if (prost[i] == 0)
        {
            bo[i]++;
            for (int j = i; j <= 1000000; j = j + i)
            {
                prost[j]++;
            }
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        scanf("%d", &x);
        scanf("%d", &y);

        if (bo[x] <= y)
        {
            printf("%s\n", "Fuke");
        }
        else
        {
            printf("%s\n", "Mujke");
        }
    }
}
