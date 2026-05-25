#include <bits/stdc++.h>

#define VERDICT(isCorrect, text)                         \
    {                                                    \
        cerr << ((isCorrect) ? (text) : "Wrong Answer") << "\n"; \
        cout << ((isCorrect) ? "1.0\n" : "0.0\n");     \
        return 0;                                        \
    }

using namespace std;

int main(int argc, char **argv)
{
    if (argc < 4)
        VERDICT(false, "Checker error: expected input, output and contestant output paths");

    ifstream input(argv[1]);
    ifstream contestant_out(argv[3]);

    if (!input)
        VERDICT(false, "Checker error: could not open input file");
    if (!contestant_out)
        VERDICT(false, "Checker error: could not open contestant output file");

    int n;
    if (!(input >> n))
        VERDICT(false, "Checker error: invalid input file");

    set<pair<int, int>> expected_edges;
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        if (!(input >> u >> v))
            VERDICT(false, "Checker error: invalid input edge list");
        if (u > v)
            swap(u, v);
        expected_edges.insert({u, v});
    }

    int status;
    if (!(contestant_out >> status))
        VERDICT(false, "Contestant output does not start with grader status");

    if (status == 0)
    {
        string message;
        getline(contestant_out >> ws, message);
        if (message.empty())
            message = "Grader reported wrong answer";
        VERDICT(false, message);
    }

    if (status != 1)
        VERDICT(false, "Invalid grader status in contestant output");

    int reported_count;
    if (!(contestant_out >> reported_count))
        VERDICT(false, "Missing reported edge count");
    if (reported_count != n - 1)
        VERDICT(false, "Wrong number of reported edges");

    set<pair<int, int>> reported_edges;
    for (int i = 0; i < reported_count; ++i)
    {
        int u, v;
        if (!(contestant_out >> u >> v))
            VERDICT(false, "Missing reported edge");
        if (u > v)
            swap(u, v);

        if (!(0 <= u && u < v && v < n))
            VERDICT(false, "Reported edge has invalid endpoints");
        if (!reported_edges.insert({u, v}).second)
            VERDICT(false, "Reported edge is duplicated");
    }

    if (reported_edges != expected_edges)
        VERDICT(false, "Reported edges do not match the input tree");

    string extra;
    if (contestant_out >> extra)
        VERDICT(false, "Extra output after reported edges");

    VERDICT(true, "Accepted");
}
