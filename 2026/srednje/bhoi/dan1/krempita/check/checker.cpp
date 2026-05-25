#include <algorithm>
#include <cctype>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

using Gate = pair<int, int>;
using Network = vector<Gate>;

#define VERDICT(score, text)                         \
    {                                                \
        cerr << text << "\n";                       \
        cout << fixed << setprecision(10) << score << "\n"; \
        return 0;                                    \
    }

static bool isSorted(const string &s) {
    for (int i = 1; i < (int)s.size(); ++i) {
        if (s[i - 1] > s[i]) return false;
    }
    return true;
}

static bool sortsString(string s, const Network &net) {
    for (auto [a, b] : net) {
        if (s[a] > s[b]) swap(s[a], s[b]);
    }
    return isSorted(s);
}

static vector<string> allBinaryStrings(int n) {
    vector<string> strings;
    if (n > 20) return strings;
    strings.reserve(1u << n);
    for (int mask = 0; mask < (1 << n); ++mask) {
        string s(n, '0');
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) s[n - 1 - i] = '1';
        }
        strings.push_back(s);
    }
    return strings;
}

static vector<string> bitonicBinaryStrings(int n) {
    vector<string> strings;
    for (int zerosLeft = 0; zerosLeft <= n; ++zerosLeft) {
        for (int ones = 0; zerosLeft + ones <= n; ++ones) {
            int zerosRight = n - zerosLeft - ones;
            strings.push_back(string(zerosLeft, '0') + string(ones, '1') + string(zerosRight, '0'));
        }
    }
    sort(strings.begin(), strings.end());
    strings.erase(unique(strings.begin(), strings.end()), strings.end());
    return strings;
}

static vector<string> structuredFullTests(int n) {
    vector<string> strings;
    strings.push_back(string(n, '0'));
    strings.push_back(string(n, '1'));

    for (int ones = 1; ones < n; ++ones) {
        strings.push_back(string(ones, '1') + string(n - ones, '0'));
        strings.push_back(string(n - ones, '0') + string(ones, '1'));
    }

    for (int l = 0; l < n; ++l) {
        string single(n, '0');
        single[l] = '1';
        strings.push_back(single);

        string singleZero(n, '1');
        singleZero[l] = '0';
        strings.push_back(singleZero);
    }

    unsigned long long x = 88172645463325252ull + n;
    for (int t = 0; t < 2000; ++t) {
        string s(n, '0');
        for (int i = 0; i < n; ++i) {
            x ^= x << 7;
            x ^= x >> 9;
            s[i] = (x & 1) ? '1' : '0';
        }
        strings.push_back(s);
    }

    sort(strings.begin(), strings.end());
    strings.erase(unique(strings.begin(), strings.end()), strings.end());
    return strings;
}

static bool validateNetwork(int n, const Network &net, int tc, string &message) {
    vector<string> tests;

    if (tc == 2) {
        tests = bitonicBinaryStrings(n);
    } else if (n <= 20) {
        tests = allBinaryStrings(n);
    } else {
        tests = structuredFullTests(n);
    }

    for (const string &s : tests) {
        if (!sortsString(s, net)) {
            message = "Mreza ne sortira string.";
            return false;
        }
    }

    return true;
}

static double f(long long x) {
    if (x < 45954) return 1.0;
    if (x <= 47151) return 1.0 - 0.1 * (x - 45954) / 1197.0;
    if (x <= 55854) return 0.9 - 0.2 * (x - 47151) / 8703.0;
    if (x <= 166650) return 0.7 - 0.55 * (x - 55854) / 110796.0;
    return 0.0;
}

int main(int argc, char **argv) {
    if (argc < 4) {
        VERDICT(0.0, "Checker ocekuje argumente: input official_output contestant_output.");
    }

    ifstream input(argv[1]), correct_out(argv[2]), contestant_out(argv[3]);

    int tc;
    if (!(correct_out >> tc)) {
        VERDICT(0.0, "Ne moze se procitati ID testnog primjera iz sluzbenog izlaza.");
    }
    if (tc < 0 || tc > 3) {
        VERDICT(0.0, "Neispravan ID testnog primjera u sluzbenom izlazu: " << tc << ".");
    }

    int T;
    if (!(input >> T)) VERDICT(0.0, "Ne moze se procitati T iz ulaza.");

    vector<int> n(T);
    for (int i = 0; i < T; ++i) {
        if (!(input >> n[i])) VERDICT(0.0, "Ne moze se procitati n iz ulaza.");
    }

    long long totalM = 0;
    for (int caseNo = 0; caseNo < T; ++caseNo) {
        int M;
        if (!(contestant_out >> M)) {
            VERDICT(0.0, "Nedostaje broj operacija za primjer " << caseNo + 1 << ".");
        }
        if (M < 0 || M > 10000) {
            VERDICT(0.0, "Broj operacija " << M << " nije u dozvoljenom rasponu.");
        }
        totalM += M;

        Network net;
        net.reserve(M);
        for (int i = 0; i < M; ++i) {
            int a, b;
            if (!(contestant_out >> a >> b)) {
                VERDICT(0.0, "Nedostaje operacija " << i + 1 << " za primjer " << caseNo + 1 << ".");
            }
            if (a < 0 || a >= n[caseNo] || b < 0 || b >= n[caseNo]) {
                VERDICT(0.0, "Operacija (" << a << ", " << b << ") izlazi iz raspona za n=" << n[caseNo] << ".");
            }
            net.emplace_back(a, b);
        }

        string message;
        if (!validateNetwork(n[caseNo], net, tc, message)) {
            VERDICT(0.0, message);
        }
    }

    string extra;
    if (contestant_out >> extra) {
        VERDICT(0.0, "Izlaz sadrzi visak podataka.");
    }

    double score = 1.0;
    if (tc == 1) {
        score = max(0.0, (22.0 - totalM) / 4.0);
    } else if (tc == 2 || tc == 3) {
        score = f(totalM);
    }
    score = min(1.0, max(0.0, score));

    VERDICT(score, "Tacno. Testni primjer: " << tc << ", ukupno operacija: " << totalM << ", relativni score: " << score << ".");
}
