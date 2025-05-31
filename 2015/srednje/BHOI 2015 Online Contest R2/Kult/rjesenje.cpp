#include <iostream>
#include <set>
#include <cmath>
#include <cstdlib>

using namespace std;

long long getNumberOfAnswers(string sentences[], int length) {
    set<string> asked;
    int start = 0;
    string lastLine = "";

    for (int i = 0; i < length; i++) {
        start = 0;
        for (int j = 0; j < sentences[i].length(); j++) {
            char c = sentences[i].at(j);

            if (c == '?') {
                asked.insert(lastLine + sentences[i].substr(start, j - start));
                start = j + 2;
                lastLine = "";
            } else if (c == '!' || c == '.') {
                start = j + 2;
                lastLine = "";
            } else if (j + 1 == sentences[i].length()) {
                lastLine += sentences[i].substr(start);
            }
        }
    }

    long long result = (long long) 1 << asked.size();
    return result == 1 ? 0 : result;
}

int main() {

    int numOfStrings;
    cin >> numOfStrings;

    string* sent = new string [numOfStrings];

    getline(cin, sent[0]);
    for (int i = 0; i < numOfStrings; i++) 
        getline(cin, sent[i]);

    cout << getNumberOfAnswers(sent, numOfStrings) << endl;

    return 0;
}