#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <set>
#include <fstream>
#include <cmath>

std::random_device rd;
std::mt19937 gen(rd());

// Function to generate a random tree
std::vector<std::vector<int>> generateRandomTree(int n) {
    std::vector<std::vector<int>> tree(n);
    std::vector<int> prufer(n - 2);
    std::vector<int> degree(n, 1);
    std::set<int> leaves;

    // Create a Prüfer sequence
    for (int i = 0; i < n - 2; i++) {
        prufer[i] = std::uniform_int_distribution<>(0, n - 1)(gen);
        degree[prufer[i]]++;
    }

    // Initialize the set of leaves
    for (int i = 0; i < n; i++) {
        if (degree[i] == 1) {
            leaves.insert(i);
        }
    }

    // Connect the nodes according to the Prüfer sequence
    for (int i = 0; i < n - 2; i++) {
        int leaf = *leaves.begin();
        leaves.erase(leaves.begin());
        int node = prufer[i];
        tree[leaf].push_back(node);
        tree[node].push_back(leaf);
        if (--degree[node] == 1) {
            leaves.insert(node);
        }
        if(i%10000 == 0) {
            std::cout << i << '\n';
        }
    }

    // Connect the last two leaves
    int u = *leaves.begin();
    leaves.erase(leaves.begin());
    int v = *leaves.begin();
    tree[u].push_back(v);
    tree[v].push_back(u);

    return tree;
}

int main() {
    // std::ifstream fin("input.txt");
    int maxn = 1000000; // Maxumber of nodes in the tree
    int t = 9; // Number of test cases
    int first = 41; // First test case number
    for(int k = first; k < first+t; k++) { // Number of test cases
        std::ofstream fout("input" + std::to_string(k) + ".txt");

        int n = std::uniform_int_distribution<>(2, maxn)(gen);
        // n = 1000000;

        std::vector<std::vector<int>> tree = generateRandomTree(n);

        // Print the tree
        fout << n << '\n';
        // Two random nodes
        int a, b;
        a = std::uniform_int_distribution<>(0, n - 1)(gen);
        do {
            b = std::uniform_int_distribution<>(0, n - 1)(gen);
        } while (a == b);
        fout << a << ' ' << b << '\n';
        // Two random integers x and y, where x > y >= 0
        int x = std::uniform_int_distribution<>(1, std::sqrt(n))(gen);
        int y = std::uniform_int_distribution<>(0, x - 1)(gen);
        fout << x << ' ' << y << '\n';
        std::vector<std::string> vs;
        for (int u = 0; u < n; u++) {
            for (int v : tree[u]) {
                if(u < v) {
                    vs.push_back(std::to_string(u) + ' ' + std::to_string(v));
                }
            }
        }
        // vs = std::vector<std::string>();
        // for(int i=0;i<n-1;i++) {
        //     // randomly add i i+1 or i+1 i
        //     if(std::uniform_int_distribution<>(0, 1)(gen)) {
        //         vs.push_back(std::to_string(i) + ' ' + std::to_string(i+1));
        //     } else {
        //         vs.push_back(std::to_string(i+1) + ' ' + std::to_string(i));
        //     }
        // }
        std::shuffle(vs.begin(), vs.end(), gen);
        for (const std::string& s : vs) {
            fout << s << '\n';
        }
    }

    return 0;
}