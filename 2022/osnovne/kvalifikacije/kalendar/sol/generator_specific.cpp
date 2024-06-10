#include "testlib.h"
#include <fstream>
#include <assert.h>

void testInit(int argc, char** argv) {
    registerGen(argc, argv, 1);
}

void outputDate(std::ofstream& inputFile, int y, int m, int d) {
    assert(y >= 1900 && y <= 2038);
    assert(m >= 1 && m <= 12);
    assert(d >= 1 && d <= 28);
    inputFile << y << ":";
    if (m < 10) {
        inputFile << "0";
    }
    inputFile << m << ":";
    if (d < 10) {
        inputFile << "0";
    }
    inputFile << d;
}

void makeTest(std::ofstream& inputFile, int subtask, int testcase, float testPercent) {
    outputDate(inputFile, rnd.next(1900, 2038), rnd.next(1, 12), rnd.next(1, 28));
    inputFile << "\n";
    outputDate(inputFile, rnd.next(1900, 2038), rnd.next(1, 12), rnd.next(1, 28));
}