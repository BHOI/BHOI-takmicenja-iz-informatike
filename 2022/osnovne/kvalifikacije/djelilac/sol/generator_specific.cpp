#include "testlib.h"
#include <fstream>
#include <assert.h>

float lerp(float a, float b, float f);

void testInit(int argc, char** argv) {
    registerGen(argc, argv, 1);
}

// subtask 0 - -1
// subtask 1 - 1
// subtask 2 - small numbers
// subtask 3 - large numbers

#define MAX_NUM 999999999

void makeTest(std::ofstream& inputFile, int subtask, int testcase, float testPercent) {
    int maxn;
    if (subtask == 0 || subtask == 1 || subtask == 2) {
        maxn = lerp(100, 500, testPercent);
    }
    if (subtask == 3) {
        maxn = lerp(500, 100000, testPercent);
    }
    int n = rnd.next(maxn / 2, maxn);
    inputFile << n << "\n";
    unsigned long long theSolution = (subtask == 1) ? 1 : rnd.next(2, 10000);
    for (int i=0; i < n; i++) {
        unsigned long long out;
        if (subtask == 0) {
            out = rnd.next(1, 999999999);
        } else if (i == 0) {
            out = theSolution;
        } else {
            unsigned long long maxMul = MAX_NUM / theSolution - 1;
            out = theSolution * rnd.next(1ull, maxMul);
        }
        
        assert(out <= MAX_NUM);
        inputFile << out;
        if (i != n-1) {
            inputFile << " ";
        }
    }
}