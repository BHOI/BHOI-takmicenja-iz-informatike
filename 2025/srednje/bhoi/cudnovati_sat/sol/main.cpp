#include <iostream>
#include <vector>
#include <algorithm>

int sol(int h1, int m1, int s1, int h2, int m2, int s2) {
    std::vector<double> overlapTimes;
    overlapTimes.reserve(3000);

    // Hour-minute overlaps.
    for (int k = 0; k < 13; k++) {
        overlapTimes.push_back(double(k) * 43200 / 13);
        overlapTimes.push_back(overlapTimes.back() + 43200);
    }

    // Hour-second overlaps.
    for (int k = 0; k < 719; k++) {
        overlapTimes.push_back(double(k) * 43200 / 719);
        overlapTimes.push_back(overlapTimes.back() + 43200);
    }

    // Minute-second overlaps.
    for (int ho = 0; ho < 12; ho++) {
        for (int k = 0; k < 61; k++) {
            overlapTimes.push_back(double(k) * 3600 / 61 + 3600 * ho);
            overlapTimes.push_back(overlapTimes.back() + 43200);
        }
    }

    std::sort(overlapTimes.begin(), overlapTimes.end());

    int start = 3600 * h1 + 60 * m1 + s1;
    int end = 3600 * h2 + 60 * m2 + s2;

    return std::lower_bound(overlapTimes.begin(), overlapTimes.end(), end) - std::lower_bound(overlapTimes.begin(), overlapTimes.end(), start);
} 

int main(){
    int h1, m1, s1;
    int d;
    int h2, m2, s2;

    std::cin >> h1 >> m1 >> s1;
    std::cin >> d;
    std::cin >> h2 >> m2 >> s2;

    if (d > 0) {
        unsigned int c = (d - 1) * 2928;
        c += sol(h1, m1, s1, 23, 59, 59);
        c += sol(0, 0, 0, h2, m2, s2);
        std::cout << c << '\n';
    } else {
        std::cout << sol(h1, m1, s1, h2, m2, s2) << '\n';
    }
}