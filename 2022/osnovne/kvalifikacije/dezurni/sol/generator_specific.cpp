#include "testlib.h"
#include <fstream>
#include <string>
#include <assert.h>

float lerp(float a, float b, float f);

void testInit(int argc, char** argv) {
    registerGen(argc, argv, 1);
}

#define MAX_NUM 999999999

std::string getName() {
    return std::string(rnd.next("[a-z]{7-9}"));
}

void makeTest(std::ofstream& inputFile, int subtask, int testcase, float testPercent) {
    std::string names[2] = {getName(), getName()};
    int maxn = lerp(10, 999, testPercent);
    int n = rnd.next(maxn / 2, maxn);
    inputFile << names[0] << " " << names[1] << "\n";
    inputFile << n << "\n";
    for (int i=0; i<n; i++) {
        int swpIdx = rnd.next(0, 1);
        assert(swpIdx == 0 || swpIdx == 1);
        std::string newName = getName();
        inputFile << names[swpIdx] << " " << newName;
        names[swpIdx] = newName;
        if (i != n-1) {
            inputFile << "\n";
        }
    }
}