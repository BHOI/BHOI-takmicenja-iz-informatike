#include <iostream>
#include <cstdio>

int n;
double variance, average, a [1000100];

int main()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a [i];
        average += a [i];
    }

    average /= (double)n;

    for (int i = 0; i < n; i++)
    {
        double N = n;
        variance += ((a [i] - average) * (a [i] - average)) / (N - 1.0);
    }

    printf ("%.2lf\n", variance);

    return 0;
}
