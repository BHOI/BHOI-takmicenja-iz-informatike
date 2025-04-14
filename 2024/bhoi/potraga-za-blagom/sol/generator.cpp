#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <filesystem>
namespace fs = std::filesystem;

#define SEP "/"

#ifdef APPEND_ONE_MORE_BACKDIR
#define BACKDIR ".." SEP
#else
#define BACKDIR ""
#endif

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

#ifndef SOURCE_PATH
#define SOURCE_PATH_FULL ""
#else
#define SOURCE_PATH_FULL TOSTRING(SOURCE_PATH) SEP
#endif

void makeTest(std::ofstream& inputFile, int subtask, int testcase, float testPercent);
void testInit(int argc, char** argv);

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

bool hasSubtasks;
int globalCount;
bool manualSubtasks;
std::ofstream genFile;

void generateSubtask(int subtask, int testcase, float testPercent) {
    std::stringstream inputFileName;
    inputFileName << SOURCE_PATH_FULL;
    if (!manualSubtasks) {
        inputFileName << ".." SEP "input" SEP "input" << globalCount << ".txt";
    } else {
        inputFileName << ".." SEP "tests" SEP "subtask_" << subtask
                      << "_test_" << testcase << ".in";
    }
    std::ofstream inputFile(inputFileName.str(), std::ios_base::binary);

    makeTest(inputFile, subtask, testcase, testPercent);
    inputFile.close();

    std::stringstream outputFileName;
    outputFileName << SOURCE_PATH_FULL;
    
    if (!manualSubtasks) {
        outputFileName << ".." SEP "output" SEP "output" << globalCount << ".txt";
    } else {
        outputFileName << ".." SEP "tests" SEP "subtask_" << subtask
                      << "_test_" << testcase << ".out";
    }
    
    globalCount++;
    std::ofstream outputFile(outputFileName.str());
}

int main (int argc, char** argv) {
    testInit(argc, argv);
    std::string configFname = BACKDIR "../sol/config.txt";
    std::cout << "Read " << configFname << std::endl;
    if (!fs::exists(configFname)) {
        std::cout << 
            "Please make sure config.txt exists with number of "
            "subtasks (first number) followed by number of tasks "
            "in subtasks in each subtask (ex, 5 1 2 3 4 5 will "
            "have 5 subtasks, with 1, 2, 3 ... tasks in each "
            "subtask).";
        return 1;
    }
    std::ifstream config(configFname);
    std::string countType;
    config >> countType;
    if (fs::exists(SOURCE_PATH_FULL "../gen/GEN")) {
        fs::remove(SOURCE_PATH_FULL "../gen/GEN");
    }
    if (countType == "global_count") {
        hasSubtasks = false;
    } else if (countType == "subtask_count") {
        hasSubtasks = true;
        system("mkdir \"" SOURCE_PATH_FULL "\".." SEP "gen");
        genFile.open(SOURCE_PATH_FULL "../gen/GEN");
    } else if (countType == "manual_subtasks") {
        hasSubtasks = true;
        manualSubtasks = true;
    } else {
        std::cout << "Wrong count_type. Expected global_count, "
                  << "subtask_count or manual_subtasks. Found " << countType;
        return 1;
    }
    if (!manualSubtasks) {
        system("mkdir \"" SOURCE_PATH_FULL "\".." SEP "input");
        system("mkdir \"" SOURCE_PATH_FULL "\".." SEP "output");
    } else {
        system("mkdir \"" SOURCE_PATH_FULL "\".." SEP "tests");
    }
    unsigned subtasks;
    config >> subtasks;
    if (subtasks > 10) {
        std::cout << "WARNING: More than 10 subtasks detected. (" << subtasks << ")\n";
    }
    for (unsigned i=0; i<subtasks; i++) {
        genFile << "# ST: " << std::endl;
        unsigned tasks;
        config >> tasks;
        if (tasks > 30) {
            std::cout << "WARNING: More than 30 tasks detected (" << tasks << ")\n";
        }
        std::cout << "---- subtask " << (i + 1) << "/" << subtasks << "\n";
        for (unsigned j=0; j<tasks; j++) {
            genFile << globalCount + 1;
            if ((i != subtasks -1) || (j != tasks-1)) {
                genFile << std::endl;
            }
            std::cout << (j + 1) << "/" << tasks << "\n";
            generateSubtask(i, j, (float)j / (float)(tasks - 1));
        }
    }
    if (hasSubtasks && !manualSubtasks) {
        std::cout << "DONT FORGET TO EDIT gen/GEN FILE !!!!!!\n";
    }
}
