#include "testlib.h"
#include <fstream>
#include <string>
#include <assert.h>
#include <set>
#include <vector>
using namespace std;

void testInit(int argc, char** argv) {
    registerGen(argc, argv, 1);
}

#define MAXV 1'000'000'000

void makeTest(std::ofstream& inputFile, int subtask, int testcase, float testPercent) {
    int maxn = 20'000'000;
    if (subtask < 2) maxn = 300'000;
    if (subtask == 2) maxn = 5'000;
    if (subtask == 3) maxn = 300'000;
    int n = (testcase == 0 || (subtask == 3 && testcase == 1)) ? maxn : rnd.next(10, maxn);
    cout << "N = " << n << endl;
    vector<int> values;

    bool is_down_only = subtask == 1 || (subtask == 3 && testcase == 1);
    int last_value = is_down_only ? MAXV : 0;
    for (int i=0; i<n; i++) {
        if (subtask == 0) {
            values.push_back(last_value + rnd.next(1, 10));
        } else if (is_down_only) {
            values.push_back(last_value - rnd.next(1, 10));
        } else {
            values.push_back(rnd.next(1, 10'000));
        }
        last_value = values[values.size() - 1];
        assert(last_value <= MAXV);
        assert(last_value > 0);
    }
    assert(n > 0);
    inputFile << n << endl;
    for (int i=0; i<values.size(); i++) {
        if (i > 0 && subtask < 2) assert(values[i] != values[i-1]);
        inputFile << values[i];
        if (i != values.size() - 1) {
            inputFile << " ";
        }
    }
}