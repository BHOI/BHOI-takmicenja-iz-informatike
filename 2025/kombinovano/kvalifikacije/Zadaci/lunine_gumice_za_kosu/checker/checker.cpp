#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

#define VERDICT(isCorrect, text) { cerr << text << "\n"; cout << ((isCorrect) ? "1.0\n" : "0.0\n"); return 0; }

bool is_valid(const double correct_ans, const double contestant_ans) {
    return fabs(correct_ans - contestant_ans) <= 1e-5;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " <input_file> <correct_output_file> <contestant_output_file>";
        return 1;
    }

    ifstream correct(argv[2]);
    double correct_ans;
    correct >> correct_ans;

    ifstream contestant(argv[3]);
    double contestant_ans;
    contestant >> contestant_ans;

    if (is_valid(correct_ans, contestant_ans)) {
        VERDICT(true, "Tacno!");
    } 
    else {
        VERDICT(false, "Netacno!");    
    }
    return 0;
}
