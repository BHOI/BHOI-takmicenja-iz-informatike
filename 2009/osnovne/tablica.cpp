#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int broj_cifara(int n)
{
    int res = 0;
    do
        res++;
    while (n /= 10);
    return res;
}

void ispisi_separator(int n_broj_cifara, int kv_broj_cifara, int kub_broj_cifara)
{
    cout << "+" << string(n_broj_cifara+2,'-') << "+" <<  string(kv_broj_cifara+2,'-') << "+" << string(kub_broj_cifara+2,'-') << "+" << endl;
}

void ispisi_podatke(int n_broj_cifara, int kv_broj_cifara, int kub_broj_cifara, int n, int kv, int kub)
{
    cout << "| " << setw(n_broj_cifara) << n << " | " << setw(kv_broj_cifara) << kv << " | " << setw(kub_broj_cifara) << kub << " |" << endl;
}

int main()
{
    int a, b;
    cin >> a >> b;
    if (a > b)
    {
        int t = a;
        a = b;
        b = t;
    }
    int n_broj_cifara = broj_cifara(b);
    int kv_broj_cifara = broj_cifara(b*b);
    int kub_broj_cifara = broj_cifara(b*b*b);
    ispisi_separator(n_broj_cifara, kv_broj_cifara, kub_broj_cifara);
    for (int i = a; i <= b; i++)
    {
        ispisi_podatke(n_broj_cifara, kv_broj_cifara, kub_broj_cifara, i, i*i, i*i*i);
        ispisi_separator(n_broj_cifara, kv_broj_cifara, kub_broj_cifara);
    }   
    return 0;
}
