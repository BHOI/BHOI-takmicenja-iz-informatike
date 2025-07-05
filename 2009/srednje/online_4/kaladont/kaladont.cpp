#include <iostream>
#include <fstream>

using namespace std;
int main()
{
    ifstream fin("kaladont_10.in");
    ofstream fout("kaladont_10.out");
    int hash[10000]={0},h,n,i,l;
    string word[120000];
    fin>>n;
    for (i=0;i<n;i++){
        fin>>word[i];
        h=int(word[i][0])*100+int(word[i][1]);
        hash[h]++;
    }
    for (i=0;i<n;i++){
        l=word[i].size();
        h=int(word[i][l-2])*100+int(word[i][l-1]);
        if (word[i][0]==word[i][l-2] && word[i][1]==word[i][l-1]){
            if (hash[h]==1) fout<<word[i]<<endl;
        }
        else if (hash[h]==0) fout<<word[i]<<endl;
    }
    return 0;
}
