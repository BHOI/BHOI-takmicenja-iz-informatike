#include<iostream>
using namespace std;

bool sretni[487];
//Najgori slucaj: 999999 ce rezlutirati sa 486 poslije prve iteracije

int kvadrirajCifre(int n)
{
    int r = 0;
    while(n!=0)
    {
        r+=(n%10)*(n%10);
        n/=10;
    }
    return r;
}

void initSretni()
{
    sretni[0]=false;
    sretni[1]=true;
    bool sretan;
    int broj;
    for(int i = 2; i < 487; ++i)
    {
        sretan = false;
        broj = i;
        for(int j = 0; j < 8; j++)
        {
            broj = kvadrirajCifre(broj);
            if(broj==1)
            {
                sretan = true;
                break;
            }
        }
        sretni[i] = sretan;
    }
}

bool sretanBroj(int n)
{
    if(n < 487)
        return sretni[n];
    else
        return sretni[kvadrirajCifre(n)];
}

int main()
{
    int a, b, rezultat = 0;
    initSretni();
    cin >> a >> b;
    for(;a<=b;++a)
        if(sretanBroj(a))
            ++rezultat;
    cout << rezultat;
    return 0;
}
