#include <iostream>
#include <map>
using namespace std;

struct State {
    int S, V, N, X, Y;
    string D;
    int ansX = -1, ansY = -1;
    // left up down right - these are used for binary search limits
    int left = -1, right = -1;
    int up = -1, down = -1;
    bool isSolved() { return ansX != -1 && ansY != -1; }
    bool isInError() { return N == -1 && !isSolved(); }
};

map<string, pair<int, int>> dirs = {
    {"S", {0, -1}},
    {"SI", {1, -1}},
    {"I", {1, 0}},
    {"JI", {1, 1}},
    {"J", {0, 1}},
    {"JZ", {-1, 1}},
    {"Z", {-1, 0}},
    {"SZ", {-1, -1}},
    {"*", {0, 0}}
};

State nextStep(const State& previous) {
    State ret = previous;
    if (ret.D == "*") {
        ret.ansX = ret.X;
        ret.ansY = ret.Y;
        return ret;
    }

    auto dir = dirs[ret.D];
    int horz = dir.first;
    int vert = dir.second;
    if (ret.left == -1 || ret.right == -1) {
        if (horz == -1) { ret.left = 0; }
        if (horz == 1)  { ret.right = ret.S - 1; }
    }
    if (horz == -1) { ret.right = ret.X - 1; }
    if (horz == 1) { ret.left = ret.X + 1; }
    if (horz == 0)  { ret.left = ret.X; ret.right = ret.X; }

    if (ret.up == -1 || ret.down == -1) {
        if (vert == -1) { ret.up = 0; }
        if (vert == 1)  { ret.down = ret.V - 1; }
    }
    if (vert == -1) { ret.down = ret.Y - 1; }
    if (vert == 1) { ret.up = ret.Y + 1; }
    if (vert == 0)  { ret.up = ret.Y; ret.down = ret.Y; }

    if (ret.left == ret.right) { ret.ansX = ret.left; }
    if (ret.up == ret.down) { ret.ansY = ret.up; }
    ret.X = ret.left + (ret.right - ret.left) / 2;
    ret.Y = ret.up + (ret.down - ret.up) / 2;

    if (!ret.isSolved()) ret.N--;
    return ret;
}

int main()
{
    State state;
    cin >> state.S >> state.V >> state.X >> state.Y >> state.D >> state.N;
    while (true) {
        state = nextStep(state);
        if (state.isSolved()) {
            cout << "odgovor " << state.ansX << " " << state.ansY << endl;
            break;
        }
        if (state.isInError()) {
            cout << "ERROR_CANT_FINISH\n";
        }
        cout << "idi " << state.X << " " << state.Y << endl;
        cin >> state.D;
    }
    return 0;
}