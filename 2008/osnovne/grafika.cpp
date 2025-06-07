#include <iostream>

using namespace std;

int main()
{
    int niz[80];
    int n=0, max=0;
    cin>>niz[n];
    while (niz[n])
    {
          max >?= niz[n];
          n++;
          cin>>niz[n];
          
    }
    for (int red=max;red>=1;red--)
    {
        bool kraj = false;
        for (int i=0;i<n && !kraj;i++)
        {
            kraj = true;
            for (int j=i;j<n;j++)
            {
                if (red <= niz[j])
                   kraj = false;
            }
            if (!kraj)
            {
                if (red <= niz[i])
                   cout<<"x";
                else
                   cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
