int phi(int n)
{
    int result = n;
    for (int p=2; p*p<=n; ++p)
    {
        if (n % p == 0)
        {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

long long prebrojPoluprave(int n){
    long long sol = 0;
    for(int i = 2; i <= n; i++)
        sol += phi(i);
    return (3 + sol * 2);
}
