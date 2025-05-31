using namespace std;

#define MAXN 1000
#define BROJ_CIFARA 300

int faktori[MAXN], broj_faktora;
char rezultat[BROJ_CIFARA + 1];

void init_faktore(int N)
{
    for(int i = 0; i < broj_faktora; i++)
        faktori[i] = N - i;
}

int nzf(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void skrati_faktore(int b)
{
    for(int i = 2; i <= b; i++)
    {
        int tekuci = i;
        for(int j = 0 ; j < broj_faktora; j++)
        {
            int faktor = nzf(faktori[j], tekuci);
            if(faktor > 1)
            {
                tekuci /= faktor;
                faktori[j] /= faktor;
                if(tekuci == 1) break;
            }
        }
    }
}

void jedan()
{
    for(int i = 0; i < BROJ_CIFARA; i++)
        rezultat[i] = '0';
    rezultat[BROJ_CIFARA - 1] = '1';
    rezultat[BROJ_CIFARA] = 0;
}

void mnozi_faktor(int f)
{
    int prenos = 0;
    for(int i = BROJ_CIFARA - 1; i >= 0; i--)
    {
        int r = (rezultat[i] - '0') * f + prenos;
        rezultat[i] = '0' + (r % 10);
        prenos = r / 10;
    }
}

int SumaCifara(int N, int M)
{
    if(N - M > M)
        M = N - M;
    broj_faktora = N - M;
    init_faktore(N);
    skrati_faktore(N - M);
    jedan();
    for(int i = 0; i < broj_faktora; i++)
    {
        if(faktori[i] > 1)
            mnozi_faktor(faktori[i]);
    }
    int s = 0;
    for (int i = 0; i < BROJ_CIFARA; i++)
        s += rezultat[i] - 48;
    return s;
}
