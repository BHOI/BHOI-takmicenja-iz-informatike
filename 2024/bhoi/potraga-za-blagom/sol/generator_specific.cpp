#include <cstdint>
#include "testlib.h"
#include <fstream>
#include <string>
#include <assert.h>
#define main __main
#include "main.cpp"
using namespace std;

void testInit(int argc, char** argv) {
    registerGen(argc, argv, 1);
}

string getDir(int X, int Y, int XS, int YS) {
    string ret = "";
    if (Y < YS) ret += "J";
    if (Y > YS) ret += "S";
    if (X < XS) ret += "I";
    if (X > XS) ret += "Z";
    if (ret == "") ret = "*";
    return ret;
}

#define MAX_WH 100
#define MAX_N 10000

void makeTest(std::ofstream& inputFile, int subtask, int testcase, float testPercent) {
    int S, V, N, X0 = -1, Y0 = -1, XS = -1, YS = -1;
    S = rnd.next(2, MAX_WH);
    V = rnd.next(2, MAX_WH);
    N = -1;
    bool addToN = true;
    if (subtask == 0) {
        S = 1;
        N = MAX_N;
    }
    if (subtask == 1) {
        S = 1;
    }
    if (subtask == 2) {
        S = 1;
        addToN = false;
        if (testcase == 0) {
            V = 3;
            Y0 = 1;
            YS = 0;
        }
    }
    if (subtask == 3) {
        V = 1;
        N = MAX_N;
    }
    if (subtask == 4) {
        V = 1;
    }
    if (subtask == 5) {
        V = 1;
        addToN = false;
        if (testcase == 0) {
            S = 3;
            X0 = 1;
            XS = 0;
        }
    }
    if (subtask == 6) {
        N = S * V;
    }
    if (subtask == 7) {
        N = S + V;
    }
    if (subtask == 8) {
    }
    if (subtask == 9) {
        addToN = false;
        if (testcase == 0) {
            S = 3;
            X0 = 1;
            XS = 2;
            V = 3;
            Y0 = 1;
            YS = 0;
        }
    }
    if (X0 == -1) X0 = rnd.next(0, S-1);
    if (Y0 == -1) Y0 = rnd.next(0, V-1);
    if (XS == -1) XS = rnd.next(0, S-1);
    if (YS == -1) YS = rnd.next(0, V-1);
    if (N == -1) {
        State st;
        st.S = S;
        st.V = V;
        st.N = 0;
        st.X = X0;
        st.Y = Y0;
        do {
            st.D = getDir(st.X, st.Y, XS, YS);
            st = nextStep(st);
        } while (!st.isSolved());
        N = -st.N + addToN * 2;
    }
    assert(S >= 1);
    assert(S <= MAX_WH);
    assert(V >= 1);
    assert(V <= MAX_WH);
    assert(X0 >= 0);
    assert(X0 < S);
    assert(Y0 >= 0);
    assert(Y0 < V);
    assert(XS >= 0);
    assert(XS < S);
    assert(YS >= 0);
    assert(YS < V);
    assert(N >= 0);
    assert(N <= MAX_N);
    inputFile << S << " " << V << " " << X0 << " " << Y0 << " " << XS << " " << YS << " " << N;
}