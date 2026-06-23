#include<iostream>
#define MAX_SIZE 45
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> lijeve(MAX_SIZE, 0), desne(MAX_SIZE, 0);

    for(int i = 0; i < N; i++) {      
        int a;
        char x;
        cin >> x >> a; // L 42
        if(x == 'L') lijeve[a]++;
        else desne[a]++;
    }

    int rezultat = 0;
    for(int i = 1; i < MAX_SIZE; i++)
        rezultat += min(lijeve[i], desne[i]);
    cout << rezultat << endl;
    return 0;
}
