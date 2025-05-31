#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int FuadovKorak, FuadoveStepenice, CatilovKorak, CatiloveStepenice;

    cin >> FuadoveStepenice >> FuadovKorak >> CatiloveStepenice >> CatilovKorak;

    int FuadoviKoraci, CatiloviKoraci;

    if(FuadoveStepenice % FuadovKorak == 0)
    {
        FuadoviKoraci = FuadoveStepenice / FuadovKorak;
    }
    else
    {
        FuadoviKoraci = ( FuadoveStepenice / FuadovKorak ) + 1;
    }

    if(CatiloveStepenice % CatilovKorak == 0)
    {
        CatiloviKoraci = CatiloveStepenice / CatilovKorak;
    }
    else
    {
        CatiloviKoraci = ( CatiloveStepenice / CatilovKorak ) + 1;
    }

    if(FuadoviKoraci > CatiloviKoraci)
    {
        cout << "Catil " << FuadoviKoraci - CatiloviKoraci;
    }
    else if(FuadoviKoraci < CatiloviKoraci)
    {
        cout << "Fuad " << CatiloviKoraci - FuadoviKoraci;
    }
    else if(FuadoviKoraci == CatiloviKoraci)
    {
        cout << "Izjednaceno! " << FuadoviKoraci;
    }

    return 0;
}
