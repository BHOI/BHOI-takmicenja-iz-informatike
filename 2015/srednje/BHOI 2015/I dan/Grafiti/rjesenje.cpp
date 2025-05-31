#include <string>

using namespace std;

char* NajboljiGrafit(int V, int P[])
{
    string o = "";

    char charBuffer[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e',
    'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    int minv = P[0], index = 0;

    for (int i = 1; i < 62; i++)
        if (P[i] <= minv)
            minv = P[i], index = i;

    while(V >= minv)
        o += charBuffer[index], V -= minv;

    bool trig;
    for (int i = 0; i < o.size(); i++)
    {
        trig = true;
        for (int j = 61; j >= 0; j--)
        {
            if(charBuffer[j] < o[i])
                break;
            if(minv + V >= P[j])
            {
                V -= P[j] - minv;
                o[i] = charBuffer[j];
                trig = false;
                break;
            }
        }
        if(trig)
            break;
    }

    char* oc = new char[o.size() + 1];
    for (int i = 0; i < o.size(); i++)
        oc[i] = o[i];
    oc[o.size()] = '\0';

    return oc;
}
