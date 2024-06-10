#include "testlib.h"
#include <fstream>
#include <assert.h>

float lerp(float a, float b, float f);

std::string expectedOutputs[] = {"nepravilno", "px", "po", "x", "o", "nerijeseno"};

bool callback(std::ifstream& in, int subtask, int testcase) {
    std::string output;
    in >> output;
    return output == expectedOutputs[subtask];
}

void testInit(int argc, char** argv) {
    registerGen(argc, argv, 1);
    outputCallback = callback;
}

void makeTest(std::ofstream& inputFile, int subtask, int testcase, float testPercent) {
    for (int i=0; i<9; i++) {
        inputFile << rnd.next((subtask == 5) ? "[XO]" : "[XO.]");
        if (i == 2 || i == 5) {
            inputFile << "\n";
        }
    }
}