//#include "grader.h"
#include <iostream>
#include <set>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int n, m, br(0);
    cin >> n >> m;

    vector <int> v1(n), v2(n);
    set <int> inOddPlaces;

    for(int i=0;i<n;i++)
    {
        cin >> v1[i];
        v2[i]=v1[i];
    }

    sort(v2.begin(), v2.end());

    for(int i=0;i<n;i+=2)
    {
        inOddPlaces.insert(v2[i]);
    }

    for(int i=0;i<n;i+=2)
    {
        if(!inOddPlaces.count(v1[i]))
        {
            br++;
        }
    }

//    cout << br;

    if(br<=m)
    {
        cout << "DA";
    }
    else
    {
        cout << "NE";
    }

    return 0;
}
