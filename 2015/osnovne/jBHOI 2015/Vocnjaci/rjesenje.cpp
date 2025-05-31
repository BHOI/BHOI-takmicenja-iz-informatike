#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>

int main()
{
    int n, d;
    std::cin >> n >> d;
    std::vector<int> vect(n);
    for (int &i : vect)
        std::scanf("%d", &i);

    long long sol(0);

    for (int i = 0; i < n; i++)
        sol += std::abs(vect[n / 2] - vect[i]);
    std::cout << sol;
}
