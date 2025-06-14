#include <iostream>
#include <map>
using namespace std;

int main()
{   
    int w, h, x, y, n;
    string d;
    cin >> w >> h >> x >> y >> d >> n;

    int min_x = 0, max_x = w-1, min_y = 0, max_y = h-1;

    while(true) {
        if(d == "*") {
            cout << "odgovor " << x << " " << y << endl;
            return 0;
        }
        if(d == "S") {
            min_x = x;
            max_x = x;
            max_y = y-1;
        }
        if(d == "J") {
            min_x = x;
            max_x = x;
            min_y = y+1;
        }
        if(d == "I") {
            min_y = y;
            max_y = y;
            min_x = x+1;
        }
        if(d == "Z") {
            min_y = y;
            max_y = y;
            max_x = x-1;
        }
        if(d == "SI") {
            min_x = x+1;
            max_y = y-1;
        }
        if(d == "JI") {
            min_x = x+1;
            min_y = y+1;
        }
        if(d == "JZ") {
            max_x = x-1;
            min_y = y+1;
        }
        if(d == "SZ") {
            max_x = x-1;
            max_y = y-1;
        }
        if(max_x == min_x && max_y == min_y) {
            cout << "odgovor " << min_x << " " << min_y << endl;
            return 0;
        }
        x = (min_x + max_x) / 2;
        y = (min_y + max_y) / 2;
        if(n-- == 0) {
            cout << "odgovor " << x << " " << y << endl;
            return 0;
        }
        cout << "idi " << x << " " << y << endl;
        cin >> d;
    }

    return 0;
}