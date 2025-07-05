#include <iostream>

using namespace std;

int main()
{
    //-40 do 60 -> 101 razlicita temp.
    int stat[101] = {0}; //inicijalizacija niza na 0
    while (true)
    {
        int temp;
        cin >> temp;
        if (temp >= -40 && temp <= 60) //provjera zadanog opsega
            stat[temp+40]++; //pomjeranje indeksa niza, jer ne moze biti negativan
        else
            break; //kraj unosa ako je temp. izvad opsega
    }
    for (int i = 0; i < 101; i++)
        if (stat[i] != 0) //ispisuju se samo one koje su se barem jednom pojavile
            cout << "Temperatura " << i - 40 << " zabiljezena je " << stat[i] << " put(a) u razmatranom periodu.\n";
    return 0;
}
