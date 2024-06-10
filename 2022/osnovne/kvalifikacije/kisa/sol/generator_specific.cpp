#include "testlib.h"
#include <fstream>

float lerp(float a, float b, float f);

void testInit(int argc, char** argv) {
    registerGen(argc, argv, 1);
}

char** makeScreen(int w, int h) {
    char** ret = new char*[h];
    for (int i=0; i<h; i++) {
        ret[i] = new char[w + 1];
        memset(ret[i], '.', w);
        ret[i][w] = '\0';
    }
    return ret;
}

void deleteScreen(char** screen, int h) {
    for (int i=0; i<h; i++) {
        delete[] screen[i];
    }
    delete[] screen;
}

bool putDrop(char** screen, int x, int y, int w, int h, int dropH, bool firstSubtask) {
    if (firstSubtask) {
        if (y >= h - dropH) {
            return false;
        }
        for (int i=0; i<dropH; i++) {
            if (screen[y+i][x] == '#') {
                return false;
            }
        }
        if (y > 0 && screen[y-1][x] == '#') {
            return false;
        }
        if (y + dropH <= h - 1 && screen[y + dropH][x] == '#') {
            return false;
        }
    }
    for(int i=0; i<dropH; i++) {
        if (y + i < h) {
            screen[y+i][x] = '#';
        }
    }
    return true;
}

void makeTest(std::ofstream& inputFile, int subtask, int testcase, float testPercent) {
    int maxw = lerp(100, 999, testPercent);
    int maxh = lerp(100, 999, testPercent);
    int w = rnd.next(50, maxw);
    int h = rnd.next(50, maxh);
    inputFile << w << " " << h << "\n";
    int dropH = rnd.next(1, h - 1);
    int numDrops = rnd.next(5, (int)((float)w * h / dropH / 2));
    bool firstSubtask = subtask == 0;
    std::cout << w << "x" << h << " numDrops: " << numDrops;
    if (subtask == 0) {
       std::cout << " dropH: " << dropH;
    }
    auto screen = makeScreen(w, h);
    int actualDrops = 0;
    for (int i=0; i<numDrops; i++) {
        int x = rnd.next(0, w - 1);
        int y = rnd.next(0, h - 1);
        actualDrops += putDrop(screen, x, y, w, h, firstSubtask ? dropH : rnd.next(1, h), firstSubtask);
    }
    std::cout << " actualDrops: " << actualDrops << "\n";
    for (int i=0; i<h; i++) {
        inputFile << screen[i] << "\n";
    }
    deleteScreen(screen, h);
}