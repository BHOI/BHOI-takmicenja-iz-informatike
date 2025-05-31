#include <iostream>

using namespace std;

int main()
{
    // Postoji formula za ovo, i to je n(n+1)(n+2)/6, ali posto ne mozemo od sviju vas da znate ili izvedete tu formulu, ne morate je koristiti da dobijete sve bodove
    // Ovo rjesenje koristi tu formulu

    long long n;

    cin >> n;

    cout << n*(n+1)*(n+2)/6;
}
