#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

struct Peak
{
    char name[16];
    int x, y, z;
};

int myAbs(int num)
{
    if (num < 0)
        return -num;
    else
        return num;
}

bool isOccluded(Peak peaks[], int nPeaks, int peak)
{
    for (int i = 0; i < nPeaks; i++)
    {
        if (peaks[i].z == peaks[peak].z && peaks[i].x == peaks[peak].x && peaks[i].y < peaks[peak].y)
            return true;
        if (i != peak && peaks[i].z > peaks[peak].z && 2*myAbs(peaks[i].x-peaks[peak].x) <= (peaks[i].z-peaks[peak].z))
            return true;
    }
    return false;
}

bool myCmp(const Peak &p1, const Peak& p2)
{
    return (p1.x < p2.x);
}

int main()
{
    freopen("himalaje.in", "r", stdin);
    freopen("himalaje.out", "w", stdout);
    int n;
    cin >> n;
    Peak peaks[n];
    vector<Peak> visiblePeaks;
    for (int i = 0; i < n; i++)
        cin >> peaks[i].name >> peaks[i].x >> peaks[i].y >> peaks[i].z;
    for (int i = 0; i < n; i++)
        if (!isOccluded(peaks, n, i))
            visiblePeaks.push_back(peaks[i]);
    sort(visiblePeaks.begin(), visiblePeaks.end(), myCmp);
    for (vector<Peak>::const_iterator iter = visiblePeaks.begin(); iter != visiblePeaks.end(); iter++)
        cout << iter->name << endl;
    fclose(stdin);
    fclose(stdout);
}
