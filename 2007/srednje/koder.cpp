#include <stdlib.h>
#include <stdio.h>

void s2int(char s[], int b[])
{
   int i, j;
   for (i=0; i<100; b[i]=0, i++);
   for (i=0; s[i]!=0; i++);
   for (i--, j=0 ; i>=0; b[j]=s[i]-'0', i--, j++); 
}

int lt(int n1[], int n2[])
{
   int i, manji;
   for (i=99; i>0; i--)
   {
      if (n1[i]<n2[i]) return 1;
      else if (n1[i]>n2[i]) return 0;
   }   
   return n1[0]<n2[0];
}

int le(int n1[], int n2[])
{
   int i, manji;
   for (i=99; i>0; i--)
   {
      if (n1[i]<n2[i]) return 1;
      else if (n1[i]>n2[i]) return 0;
   }   
   return n1[0]<=n2[0];
}

void duplo(int n[])
{
    int i, prenos, tmp;
    for (prenos=0, i=0; i<99; i++)
    {
       tmp = n[i] * 2;
       n[i] = tmp%10 + prenos;
       prenos = tmp / 10;
    }   
}

void minus(int n1[], int n2[], int rez[])
{
   int i, j, ponovo;
   for (i=0; i<=99; i++)
   {
      if (n2[i]<=n1[i]) 
         rez[i]=n1[i]-n2[i];
      else
      { 
         j=i+1;  
         do 
         {  
            ponovo=0;
            n1[j]--; 
            if (n1[j]==-1) 
            {
               n1[j]=9; j++; ponovo=1;
            }   
         }   
         while (ponovo);
         rez[i]=10+n1[i]-n2[i];
      }   
   }   
}

void pola(int n[])
{
    int i, prenos, tmp;
    for (prenos=0, i=99; i>=0; i--)
    {
       tmp = prenos*10 + n[i];
       n[i] = tmp/2;
       prenos = tmp%2;
    }   
}

void inc(int n[])
{
    int i;
    for (i=0; i<=99; i++)
    {
       n[i]++;
       if (n[i]<10) break;
       n[i]=0; 
    }   
}

int main()
{
    char ns[100];
    int n[100]={0}, p[100]={2}, kod[100]={0};
    int i, start; 
    FILE *fin = fopen("koder.in", "r");
    FILE *fout = fopen("koder.out", "w");
    
    fscanf(fin, "%s", ns);
    fscanf(fin, "%d", &start);
    
    s2int(ns,n);
               
    if (start==1)
    {
        while (lt(p,n)) duplo(p);
        pola(p);    
        minus(n,p,kod);
        duplo(kod);
    }
    else
    {
        while (le(p,n)) duplo(p);
        pola(p);
        minus(n,p,kod);
        duplo(kod);
        inc(kod);
    }

    for (i=99; !kod[i]; i--);
    for(; i>=0; i--) fprintf(fout, "%d", kod[i]);
     
    fclose(fin);
    fclose(fout);
}