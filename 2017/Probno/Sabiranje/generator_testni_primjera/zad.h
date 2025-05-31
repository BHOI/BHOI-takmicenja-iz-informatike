#ifndef LIB
#include "lib.h"
#endif
#define ISPIS_N
/*
Subtask 1: N<=1000, L=N/2, H=N/2        5 bodova
Subtask 2: N<=2^30-1,     21 bodova
Subtask 3: N<=10000    33 boda
Subtask 4: N<=2^30-1  41 boda
*/

int maxN[]{1000,(1<<30)-1,10000,(1<<30)-1};

class Zadatak
{
public:
    int br_tp;
    Zadatak(){
        br_tp=10;
        srand((unsigned)time(NULL));
    }
    int Subtask_No(int T)const
    {
        if(T<10)return 1;
        throw "Visak testova";
        return -1;
    }
    bool gen_pri(int T)
    {
        int a,b;
        fprintf(in,"%d %d\n",(a=rand()%(1<<30)),(b=rand()%(1<<30)));
        fprintf(out,"%d",a+b);
       /* if(Subtask_No(T)!=Subtask_No(T-1) || T==0
           )fprintf(_log,"Subtask\t#%d:\n",Subtask_No(T));
        fprintf(_log,"Test broj #%d: n: \t%d l: \t%d h: \t%d op: \t%d\n",T,n,l,h,op);
        printf("Test broj #%d: n: \t%d l: \t%d h: \t%d op: \t%d\n",T,n,l,h,op);
*//*
            int n=rand()%(maxN[Subtask_No(T)-1]-2)+3;
            if(T>37)n=maxN[3];
            fprintf(in,"%d\n",n);
            vector<int> svi(n);
            ve.clear();
            ve.resize(n);
            ispod.clear();
            ispod.resize(n);
            for(int i=0;i<n;i++)svi[i]=i+1;
            vector<int> parenti;
            napravi_drvo(n,svi,parenti,T);
            for(int k=0;k<n-1;k++)
            {
                fprintf(in,"%d%c",parenti[k]-1,(k==n-2)?'\n':' ');
                ve[parenti[k]-1].pb(k+1);
            }
            dfs(0,-1);
            for(int i=0;i<ispod.size();i++)
                fprintf(out,"%d%c",ispod[i],(i==n-1)?'\n':' ');
            //ispisi specifikacije testa koji je napravljen
            printf("Test broj #%d: N: \t%d\n",T,n);cout<<endl;
            if(Subtask_No(T)!=Subtask_No(T-1) || T==0
               )fprintf(_log,"Subtask\t#%d:\n",Subtask_No(T));
            fprintf(_log,"Test broj #%d: N: \t%d\n",T,n);
*/
   /*     }
        catch(const char *c){
            cout<<"U testu T: "<<T<<" "<<c<<endl;
            return 0;
        }*/
        return 1;
    }
};
