#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>

#ifndef lerp
float lerp(float a, float b, float f)
{
    return a + f * (b - a);
}
#endif

std::chrono::steady_clock::time_point timeMeasurementStart;

void startMeasuringTime() {
    timeMeasurementStart = std::chrono::steady_clock::now();
}

void stopMeasuringTime() {
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - timeMeasurementStart).count() << "ms" << std::endl;
}

#define MEASURE_TIME(code) {\
    startMeasuringTime();\
    code;\
    stopMeasuringTime();\
}

#include "generator_specific.cpp"

bool isGlobalCount;
int globalCount;

void generateSubtask(int subtask, int testcase, float testPercent) {
    std::stringstream inputFileName;
    if (isGlobalCount) {
        inputFileName << "../input/input" << globalCount << ".txt";
    } else {
        inputFileName << "testcases/" << subtask << "_" << testcase << ".in";
    }
    std::ofstream inputFile(inputFileName.str(), std::ios_base::binary);

    makeTest(inputFile, subtask, testcase, testPercent);
    inputFile.close();

    std::stringstream outputFileName;
    if (isGlobalCount) {
        outputFileName << "../output/output" << globalCount << ".txt";
    } else {
        outputFileName << "testcases/" << subtask << "_" << testcase << ".out";
    }
    
    globalCount++;
    std::string outputCommand = "./main <\"" + inputFileName.str() + "\" >\"" + outputFileName.str() + "\"";
    MEASURE_TIME(system(outputCommand.c_str()));
}

int main (int argc, char** argv) {
    testInit(argc, argv);
    std::ifstream config("config.txt");
    if (config.bad()) {
        std::cout << 
            "Please make sure config.txt exists with number of "
            "subtasks (first number) followed by number of tasks "
            "in subtasks in each subtask (ex, 5 1 2 3 4 5 will "
            "have 5 subtasks, with 1, 2, 3 ... tasks in each "
            "subtask).";
        return 1;
    }
    std::string countType;
    config >> countType;
    if (countType == "global_count") {
        isGlobalCount = true;
        system("mkdir ../input");
        system("mkdir ../output");
    } else if (countType == "subtask_count") {
        isGlobalCount = false;
        system("mkdir testcases");
    } else {
        std::cout << "Wrong count_type. Expected global_count or "
                  << "subtask_count. Found " << countType;
        return 1;
    }
    unsigned subtasks;
    config >> subtasks;
    if (subtasks > 10) {
        std::cout << "WARNING: More than 10 subtasks detected. (" << subtasks << ")\n";
    }
    for (unsigned i=0; i<subtasks; i++) {
        unsigned tasks;
        config >> tasks;
        if (tasks > 30) {
            std::cout << "WARNING: More than 30 tasks detected (" << tasks << ")\n";
        }
        std::cout << "---- subtask " << (i + 1) << "/" << subtasks << "\n";
        for (unsigned j=0; j<tasks; j++) {
            std::cout << (j + 1) << "/" << tasks << "\n";
            generateSubtask(i, j, (float)j / (float)(tasks - 1));
        }
    }
}