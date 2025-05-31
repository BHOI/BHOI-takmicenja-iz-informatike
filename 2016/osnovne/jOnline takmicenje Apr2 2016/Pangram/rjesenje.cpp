#include <iostream>

using namespace std;

int main()
{
    int brojPonavljanja[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int velicina;
    string recenica;
    cin >> velicina;
    cin.ignore(1, '\n');
    getline(cin, recenica);
    for (int i = 0; i < velicina; i++)
        if (recenica[i] >= 'a' && recenica[i] <= 'z')
            brojPonavljanja[recenica[i] - 'a']++;
        else
            brojPonavljanja[recenica[i] - 'A']++;
    for (int i = 0; i < 26; i++)
        if (brojPonavljanja[i] == 0)
        {
            cout << "NE" << endl;
            return 0;
        }
    cout << "DA" << endl;
    return 0;
}
