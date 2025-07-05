//http://bluefintuna.wordpress.com/2006/08/02/q10049-selfdescribing-sequence/
#include<iostream>
#include<cstdlib>
using namespace std;
int main(int argc, char *argv[])
{
    static int a[700000] = {0,1};
    for(int i = 2; i < 700000; i++)
        a[i] = 1+a[i-a[a[i-1]]];
   
    int n,sum;
    while(cin >> n)
    {
        if(n == 0)
            break;
       
        sum = 0;
        for(int i = 1; i < 700000; i++)
        {
            sum += a[i];
            if(sum >= n)
            {
                cout << i << endl;
                break;
            }
        }
    }   
    return 0;
}