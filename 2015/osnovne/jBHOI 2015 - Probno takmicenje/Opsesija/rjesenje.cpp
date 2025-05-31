#include <bits/stdc++.h>
using namespace std;

int primeCount(int a, int b){
    int root = sqrt(b);

    vector <bool> lowSieve(root+1, true);
    lowSieve[0] = lowSieve[1] = false;
    int secRoot = sqrt(root);

    for(int i = 2; i <= secRoot; ++i){
        if(lowSieve[i]){
            for(int j = i*i; j <= root; j += i)
                lowSieve[j] = false;
        }
    }

    vector <bool> highSieve(b-a+1, true);

    for(int i = 2; i <= root; ++i){
        if(lowSieve[i]){
            int start = a + (i - a % i) % i;
            for(int j = start; j <= b; j += i)
                if(i != j) highSieve[j-a] = false;
        }
    }

    if(a == 1) highSieve[0] = false;

    int primeCnt = 0;
    for(int i = 0; i <= b-a; ++i)

        primeCnt += highSieve[i];

    return primeCnt;
}

bool isPrime(int n){
    if(n == 1) return false;
    int root = sqrt(n);
    for(int i = 2; i <= root; ++i)
        if(n % i == 0) return false;
    return true;
}

int primeCount2(int a, int b){
    int primeCnt = 0;
    for(int i = a; i <= b; ++i)
        primeCnt += isPrime(i);
    return primeCnt;
}

int main(){
    const int MOD = 1e9 + 7;
    int a, b;
    cin >> a >> b;
    int primeCnt = primeCount(a, b);

    int fibL = 1, fibR = 1;

    for(int i = 0; i < primeCnt; ++i){
        swap(fibL, fibR);
        fibR = (fibL + fibR) % MOD;
    }

    cout << fibR << "\n";

    return 0;
}
