#include "testlib.h"

float lerp(float a, float b, float f);

void testInit(int argc, char** argv) {
    registerGen(argc, argv, 1);
}

// subtask 0 - Y = 1
// subtask 1 - T = 100, X <= 6

void makeTest(std::ofstream& inputFile, int subtask, int testcase, float testPercent) {
    int maxt = (subtask == 1) ? 100 : 100000;
    int maxx = (subtask == 1) ? 6 : 1000000;
    int maxy = (subtask == 0) ? 1 : 1000000;
    int t = rnd.next(maxt / 2, maxt);
    inputFile << t << "\n";
    for (int i=0; i<t; i++) {
        int x = rnd.next(1, maxx);
        int y = rnd.next(1, maxy);
        inputFile << x << " " << y << "\n";
    }
}