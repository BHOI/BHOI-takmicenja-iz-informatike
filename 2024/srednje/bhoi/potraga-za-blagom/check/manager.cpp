#include <iostream>
#include <fstream>
#include <signal.h>
using namespace std;

// #define DEBUG

#ifdef DEBUG
#define dbg cout
#else
ofstream dbg("output.txt");
#endif

string getDir(int X, int Y, int XS, int YS) {
    string ret = "";
    if (Y < YS) ret += "J";
    if (Y > YS) ret += "S";
    if (X < XS) ret += "I";
    if (X > XS) ret += "Z";
    if (ret == "") ret = "*";
    return ret;
}

#define ERROR_RET(err) cout << "0.0\n"; cerr << "translate:wrong\n"; dbg << err << "\n"; return 0;

int main(int argc, char **argv) {
	signal(SIGPIPE, SIG_IGN);
    int S, V, N, X0, Y0, XS, YS;
    dbg << "Opening input.txt\n";
    ifstream in("input.txt");
    in >> S >> V >> X0 >> Y0 >> XS >> YS >> N;
    string D = getDir(X0, Y0, XS, YS);
    dbg << "Field: " << S << "x" << V << "\t";
    dbg << "Start: " << X0 << "x" << Y0 << "\t";
    dbg << "Target: " << XS << "x" << YS << "\n";
    dbg << "N= " << N << "\tD= " << D << endl;
    dbg << "Opening fifo in " << argv[2] << "\n";
    dbg.flush();
	ofstream fifoIn(argv[2]);
    dbg << "Opening fifo out " << argv[1] << "\n";
    dbg.flush();
	ifstream fifoOut(argv[1]);
    fifoIn << S << " " << V << " " << X0 << " " << Y0 << " " << D << " " << N << endl;
    fifoIn.flush();

    string command;
    int X, Y;
    while (true) {
        fifoOut >> command;
        if (command == "idi") {
            fifoOut >> X >> Y;
            dbg << "idi " << X << " " << Y << endl;
            if (X < 0 || Y < 0 || X >= S || Y >= V) {
                ERROR_RET("Outside of bounds")
            }
            if (N <= 0) {
                ERROR_RET("Radar is broken")
            }
            D = getDir(X, Y, XS, YS);
            fifoIn << D << endl;
            fifoIn.flush();
            N--;
            dbg << "N= " << N << "\tD= " << D << endl;
        } else if (command == "odgovor") {
            fifoOut >> X >> Y;
            dbg << "odgovor " << X << " " << Y << endl;
            if (X != XS || Y != YS) {
                ERROR_RET("Wrong answer");
            } else {
                break;
            }
        } else {
            ERROR_RET("Invalid command: " << command);
        }
    }
    cout << "1.0\n";
    cerr << "translate:success\n";
    return 0;
}