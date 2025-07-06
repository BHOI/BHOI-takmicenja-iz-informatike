#include "testlib.h"
#include <fstream>
#include <assert.h>
#define GENERATOR
#include "main.cpp"
#include <iomanip>

float lerp(float a, float b, float f);

void testInit(int argc, char** argv) {
    registerGen(argc, argv, 1);
    rnd.next(0, 1);
}

int solveGreedy(int n, int* kovanice, int kusur) {
    int i = n-1;
    int ret = 0;
    while(i >= 0) {
        if (kovanice[i] > kusur) {
            i--;
        } else {
            kusur -= kovanice[i];
            ret++;
        }
    }
    if (kusur != 0) {
        return -1;
    } else {
        return ret;
    }
}

double round2(double val) {
    return (double)(round(val * 100.0)) / 100.0;
}

int callSolve(std::function<int(int, int*, int)> solver, const std::set<double>& kovanice, double kusur) {
    int* kovanice_arr = new int[kovanice.size()];
    int i=0;
    for (double kovanica : kovanice) {
        kovanice_arr[i++] = round(kovanica*100);
    }
    int ret = solver(kovanice.size(), kovanice_arr, round(kusur*100));
    delete[] kovanice_arr;
    return ret;
}

#define MAX_COINS 50
#define MAX_PRICE 100000.0
#define MAX_COIN 100.0

void makeTest(std::ofstream& inputFile, int subtask, int testcase, float testPercent) {
    int maxn = lerp(5, MAX_COINS, testPercent);
    int minn = maxn/2;
    std::set<double> coins;
    double price;
    double user_money;
    while(true) {
        int n = rnd.next(minn, maxn);
        coins.clear();
        for (int i=0; i<n; i++) {
            coins.insert(round2(rnd.next(0.01, MAX_COIN)));
        }
        if (subtask == 1 && coins.size() < MAX_COINS - 1) {
            coins.insert(0.01);
        }
        price = 0.0;
        user_money = price;
        int num_additions = rnd.next(10, 100);
        for (int i=0; i<num_additions; i++) {
            double previous_money = user_money;
            int from = subtask == 0 ? coins.size() - 1 : 0;
            int to = coins.size() - 1;
            if (i == num_additions - 1 && subtask == 0) {
                from--;
                to--;
            }
            double coin = *std::next(
                coins.begin(), rnd.next(from, to)
            );
            user_money += coin;
            user_money = round2(user_money);
            if (user_money >= MAX_PRICE) {
                user_money = previous_money;
                break;
            }
            // std::cout << coin << std::endl;
        }
        double diff = round2(rnd.next(0.01, MAX_PRICE - user_money - 0.01));
        if (diff <= 0.01) {
            continue;
        }
        price = diff;
        user_money = round2(user_money + diff);
        if (testcase == 0) {
            user_money--;
        }
        // std::cout << price << " " << user_money << std::endl;
        int dp = callSolve(solve, coins, user_money - price);
        if (dp == -1 && testcase > 0) {
            std::cout << "Solution is -1\n";
            std::cout << coins.size() << " " << user_money << " " << price << std::endl;
            for (double coin : coins) {
                std::cout << coin << " ";
            }
            exit(1);
            continue;
        }
        int greedy = callSolve(solveGreedy, coins, user_money - price);
        // std::cout << greedy << " " << dp << std::endl;
        if ((subtask == 0) ^ (greedy != dp)) {
            break;
        } else {
            std::cout << "Retry ... " << dp << " != " << greedy << "\n";
        }
    }
    inputFile << coins.size() << " ";
    inputFile << std::fixed << std::setprecision(2);
    inputFile << user_money << " " << price << std::endl;
    for (double coin : coins) {
        inputFile << coin << " ";
    }
}