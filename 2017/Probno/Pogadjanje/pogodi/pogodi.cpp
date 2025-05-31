//ovdje includeove ili using namespace std, ako vam treba

extern int ovajBroj(unsigned long long);

unsigned long long pogodi()
{
    //ovdje ide vas kod
    if(ovajBroj(0)==0)return 0;
    if(ovajBroj(5)==0)return 5;
    if(ovajBroj(3)==1)return 2;
    return 4;
}
