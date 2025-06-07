// Autor rješenja je Mihael Mutić (hvala puno!)
#include <iostream>

using namespace std;

int main()
{
    int niz[5],najmanji=10001,najveci=0;
    for (int i=0;i<5;i++){cin>>niz[i];}
    for (int i=0;i<5;i++){
            if(niz[i]<najmanji)najmanji=niz[i];
            if(niz[i]>najveci)najveci=niz[i];
    }
    cout<<najmanji*najveci<<endl;
    return 0;
}
