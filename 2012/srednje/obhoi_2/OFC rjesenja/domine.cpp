#include <cstdio>
#include<iostream>
#define max(a,b) ((a)>(b)?  a: b)

int main(){
  freopen("domine.in","r",stdin);
  freopen("domine.out","w",stdout);
  
  int dominos;
  int range=0;
  int tmph;
  scanf("%d",&dominos);
  scanf("%d",&range);          
  int answ;
  for(answ=1;answ<dominos;answ++){
          range--;
          if(range<=0) break;
          scanf("%d",&tmph);
          range=max(range,tmph);
          }
  printf("%d",answ);
  return 0;    
}
