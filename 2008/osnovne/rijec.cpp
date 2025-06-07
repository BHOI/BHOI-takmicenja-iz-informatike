#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

bool suglasnici[128];

int tezina(string rijec)
{
    int retval = 0;
    for (int i=1;i<rijec.size();i++)
    {
        if (suglasnici[rijec[i]] && suglasnici[rijec[i-1]])
           retval++;
    }
    return retval;
}

int main()
{
    for (int i=0;i<128;i++)
        suglasnici[i] = true;
    suglasnici['a'] = false;
    suglasnici['e'] = false;
    suglasnici['i'] = false;
    suglasnici['o'] = false;
    suglasnici['u'] = false;

    int n=0;
    string rijeci[100];
    cin>>rijeci[0];
    while (rijeci[n]!="zadnja")
    {
          n++;
          cin>>rijeci[n];
    }
    
    for (int i=0;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if (tezina(rijeci[i])<tezina(rijeci[j]))
               swap(rijeci[i], rijeci[j]);
        }
    }
    
    cout<<rijeci[1]<<endl;

    return 0;
}
