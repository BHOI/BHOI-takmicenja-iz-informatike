#include "grader.h"

void solve(int N) {
    if (meetingPlace(0, 1, 2) == 1)
        mapPath(0, 1);
    else
        mapPath(0, 2);
}
