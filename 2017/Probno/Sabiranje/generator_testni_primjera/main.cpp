#include "zad.h"
#ifndef LIB
#include "lib.h"
#endif

string ina="tests/input",oua="tests/output";

void inc(string &x)
{
    int I=x.size()-1;
    x[I]++;
    while(x[I]>'9')
    {
        x[I-1]++;
        x[I--]='0';
    }
}

void close_f()
{
    if(in!=NULL)fclose(in);in=NULL;
    if(out!=NULL)fclose(out);out=NULL;
}

void otvori_next()
{
    try
    {
        close_f();
        in=fopen(ina.c_str(),"w");
        if(in==NULL)throw "INPUT NIJE OTVOREN";
        out=fopen(oua.c_str(),"w");
        if(out==NULL)throw "OUTPUT NIJE OTVOREN";
        inc(ina);inc(oua);
    }
    catch (const char *p)
    {
        cerr<<"Upozorenje: "<<p<<endl;
    }
}

int main()
{
    Zadatak zad=Zadatak();
    int T=zad.br_tp;
    while(T)
    {
        ina+='0';oua+='0';
        T/=10;
    }
    T=zad.br_tp;
    try
    {
        _log=fopen("log.txt","w");
        if(_log==NULL)throw "LOG NIJE OTVOREN";
        for(int k=0;k<T;k++)
        {
            otvori_next();
            if(zad.gen_pri(k)==0)
                throw (string("Primjer ")+ina+string(" nije uspio")).c_str();
        }
    }
    catch (const char *p)
    {
        cerr<<"Upozorenje: "<<p<<endl;
    }
    close_f();
    fclose(_log);
//#ifdef ISPIS_N
//    for(int i=0;i<zad.gener.size();i++)
//    {
//        if(i%10==0)
//            printf("SUBTASK %d:\n",i/10+1);
//        printf("%d\n",zad.gener[i]);
//    }
//#endif // ISPIS_N
    return 0;
}
