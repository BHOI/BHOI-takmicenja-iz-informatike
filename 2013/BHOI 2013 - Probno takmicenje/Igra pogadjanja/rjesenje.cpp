int Pokusaj(int k);

void ZapocniIgru(int a, int b) {
    int p;
    do {
        int k = ((long long)a+b)/2;
        p = Pokusaj(k);
        if (p > 0)
            b = k-1;
        else if (p < 0)
            a = k+1;
    } while (p != 0);
}

