#include <iostream>
#include <array>
#include <string>

bool cmp(const std::array<char, 4> &arr, char c5, char c6, char c7, char c8)
{
    if (arr[0] < c5)
        return true;
    if (c5 < arr[0])
        return false;
    if (arr[1] < c6)
        return true;
    if (c6 < arr[1])
        return false;
    if (arr[2] > c7)
        return true;
    if (c7 < arr[2])
        return false;
    if (arr[3] < c8)
        return true;
    return false;
}

std::array<std::array<std::array<std::array<int, 26>, 26>, 26>, 26> reps;

int main()
{
    std::string input;
    std::cin >> input;
    std::array<char, 4> sol;
    for (int j = 0; j < 4; j++)
        sol[j] = 'Z';
    int sol_reps = 0;
	
	//if (input.length() > 10000) {std::cout << '0';return 0;}

    for (int i = 0; i < input.length() - 3; i++)
    {
        //std::cerr << (int)input[i] << '\n';
        int *r = &reps.at(input[i] - 'A').at(input[i + 1] - 'A').at(input[i + 2] - 'A').at(input[i + 3] - 'A');
        (*r)++;

        if (*r > sol_reps)
        {
            for (int j = 0; j < 4; j++)
                sol[j] = input[i + j];
            sol_reps = *r;
        }
        else if (*r == sol_reps && !cmp(sol, input[i], input[i + 1], input[i + 2], input[i + 3]))
        {
            for (int j = 0; j < 4; j++)
                sol[j] = input[i + j];
        }

    }
    for (auto c : sol)
        std::cout << c;
    //std::cout << '\n' << sol_reps;
}
