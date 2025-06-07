#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    bool prvi = true;
    bool prost[30005];
    for (int i=0;i<30000;i++)
    {
        prost[i]=true;
    }
    for (int i=2;i<30000;)
    {
        for (int j=i*2; j<30005; j+=i)
        {
            prost[j] = false;
        }
        i++;
        while (prost[i] == false)
              i++;
    }
    
    cin>>n;
    for (int i=n;i>=2;i--)
    {
       if (!prost[i])
           continue;
       if (n%i==0)
       {
           if (prvi)
           {
              prvi = false;
              cout<<i;
           }
           else
           {
              cout<<" "<<i;
           }
       }
    }
    cout<<endl;
    return 0;
}
