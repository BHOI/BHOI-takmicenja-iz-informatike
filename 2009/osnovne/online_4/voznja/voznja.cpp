#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
int main()
{
    ifstream fin("voznja1.in");
    ofstream fout("voznja1.out");
    int bus[12][4];
    int n,i,j,k,r[48],s[48],result=-1;
    fin>>n;
    for (i=0;i<n;i++){
        fin>>r[i]>>s[i];
        r[i]--; s[i]--;
    }
    for (i=0;i<12;i++){
        for (j=0;j<4;j++){
            bus[i][j]=max(abs(i-r[0]), abs(j-s[0]));
            for (k=1;k<n;k++){
                bus[i][j]=min(bus[i][j], max(abs(i-r[k]), abs(j-s[k])));
            }
            result=max(result, bus[i][j]);
        }
    }
    fout<<result<<endl;
    return 0;
}
