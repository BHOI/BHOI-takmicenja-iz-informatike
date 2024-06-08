#include <iostream>
#include <limits>
#include <string>

using namespace std;

int calculate_max_figures(const std::string& s, const std::string& f) {
    int counts_s[26] = {0};
    int counts_f[26] = {0};

    for (char c : s) {
        counts_s[c - 'a']++;
    }
    for (char c : f) {
        counts_f[c - 'a']++;
    }

    int max_figures = numeric_limits<int>::max();
    for (int i = 0; i < 26; ++i) {
        if (counts_f[i] > 0) {
            if (counts_s[i] == 0) {
                return 0; // Ako neki karakter iz figure nedostaje u setu
            }
            max_figures = std::min(max_figures, counts_s[i] / counts_f[i]);
        }
    }

    return max_figures;
}

int main() {
    std::string s, f;
    cin >> s >> f;

    int result = calculate_max_figures(s, f);
    std::cout << result << std::endl;

    return 0;
}
