// Autor rješenja je Mihael Mutić (hvala puno!)
#include <iostream>

using namespace std;

int main()
{
    int n,trenutni(0);
    cin>>n;int v[n],rez[n];
    for (int i=0;i<n;i++){rez[i]=0;cin>>v[i];}
    for (int i=0,k=n-1;i<k;i++){if (v[i+1]>v[trenutni])trenutni=i+1;
    rez[trenutni]+=1;
    }
    for (int j=0;j<n;j++){cout << rez[j] << " ";}
    return 0;
}
