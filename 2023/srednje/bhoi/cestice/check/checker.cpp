#include <iostream>
#include <utility>
#include <sstream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

char other(char c)
{
    if (c == '(') return ')';
    if (c == ')') return '(';
    if (c == '[') return ']';
    if (c == ']') return '[';
    if (c == '{') return '}';
    if (c == '}') return '{';
    return '\0';
}

#define VERDICT(isCorrect, text) { cerr << text << "\n"; cout << ((isCorrect) ? "1.0\n" : "0.0\n"); return 0; }

int main(int argc, char **argv)
{
    ifstream input(argv[1]), correct_out(argv[2]), contestent_out(argv[3]);

    int n, k;
    string r, s, c;
    input >> n >> k >> r;
    contestent_out >> s;
    correct_out >> c;

    if (c == "nemoguce")
    {
        if (s != c) {
            VERDICT(false, "Rjesenje treba biti nemoguce");
        } else {
            VERDICT(true, "Rjesenje je nemoguce, sto je tacno");
        }
    }

    if (n != s.length())
    {
        VERDICT(false, "String rjesenja nema tacnu duzinu. " << n << " != " << s.length());
    }

    int d = 0;
    stack<int> S;
    for (int i = 0; i < n; i++)
    {
        d += (s[i] != r[i]);

        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            S.push(i);
            if (r[i] != '(' && r[i] != '[' && r[i] != '{')
            {
                VERDICT(false, "Netacno!");
            }
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            if (r[i] != ')' && r[i] != ']' && r[i] != '}')
            {
                VERDICT(false, "Netacno!");
            }

            if (S.empty()) VERDICT(false, "Netacno!");
            int j = S.top();
            S.pop();

            if (s[i] != other(s[j]))
            {
                VERDICT(false, "Netacno!");
            }
        }
        else
        {
            VERDICT(false, "Netacno!");
        }
    }
    if (!S.empty())
    {
        VERDICT(false, "Netacno!");
    }
    if (d != k)
    {
        VERDICT(false, "Netacno!");
    }

    VERDICT(true, "Tacno!");
    return 0;
}
