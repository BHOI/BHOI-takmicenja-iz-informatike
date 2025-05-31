#include <iostream>
#include <vector>
#include <utility>

extern std::string palindrom(const std::vector<std::pair<std::pair<int, int>, char>> &g);

int main()
{
    int n;
    int a, b;
    char c;

    std::vector<std::pair<std::pair<int, int>, char>> test;

    std::cin >> n;
    while (n--) {
        std::cin >> a >> b >> c;
        test.push_back({{a, b}, c});
    }

    std::cout << palindrom(test) << '\n';

    return 0;
}
