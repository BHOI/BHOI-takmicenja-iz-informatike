#include "testlib.h"
#include <fstream>
#include <string>
#include <assert.h>

#define main old_main
#include "main.cpp"

void testInit(int argc, char** argv) {
    registerGen(argc, argv, 1);
}

typedef tuple<int, int, int> TaskNumbers;

int solution(TaskNumbers t) {
    return solve(get<0>(t), get<1>(t), get<2>(t));
}

TaskNumbers subtaskN(int minSolution, int maxSolution, int maxN) {
    while(true) {
        int a = rnd.next(0, maxN);
        int b = rnd.next(0, maxN);
        int c = rnd.next(0, maxN);
        int sol = solve(a, b, c);
        if (sol >= minSolution && sol <= maxSolution) {
            return {a, b, c};
        }
    }
}

// subtask 1 -> solution is 0 or 1
TaskNumbers subtask0() {
    return subtaskN(0, 1, 10);
}

// subtask 2 -> solution is 2
TaskNumbers subtask1() {
    return subtaskN(2, 2, 10);
}

// subtask 3 -> solution is -1
TaskNumbers subtask2() {
    return subtaskN(-1, -1, 10);
}

// subtask 4 -> solution < 80000
TaskNumbers subtask3() {
    return subtaskN(40000, 80000, 40000);
}

// subtask 5 -> solution < 20000000
TaskNumbers subtask4() {
    return subtaskN(10000000, 20000000, 10000000);
}

void writeTestCase(std::ofstream& inputFile, TaskNumbers t) {
    inputFile << get<0>(t) << "\n" << get<1>(t) << "\n" << get<2>(t);
}

void makeTest(std::ofstream& inputFile, int subtask, int testcase, float testPercent) {
    TaskNumbers t;
    if (subtask == 0) {
        t = subtask0();
    }
    if (subtask == 1) {
        t = subtask1();
    }
    if (subtask == 2) {
        t = subtask2();
    }
    if (subtask == 3) {
        t = subtask3();
    }
    if (subtask == 4) {
        t = subtask4();
    }
    writeTestCase(inputFile, t);
}