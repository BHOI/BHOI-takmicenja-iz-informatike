#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc,char **arg)
{
    ifstream ofc(arg[2]), tak(arg[3]);
    /*FILE *ofc=fopen(arg[0],"r");
    FILE *tak=fopen(arg[1],"r");*/
    string ts,s;
    int c=0;
    vector<string> ve;
    while(tak>>ts){
        if (c==1){
            fprintf(stderr, "Pogrešan format ispisa.\n");
            printf("0.00\n");
            return 0;
        }
        c++;
    }
    while(ofc>>s)
    {
        ve.push_back(s);
    }
    if (binary_search(ve.begin(),ve.end(),ts)) {
        fprintf(stderr, "Rezultat je ispravan.\n");
        printf("1.00\n");
    } else {
        fprintf(stderr, "Rezultat nije ispravan.\n");
        printf("0.00\n");
    }
    return 0;
}

