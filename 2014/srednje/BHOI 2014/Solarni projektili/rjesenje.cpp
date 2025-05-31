#include <cmath>
#include <vector>

using namespace std;

struct Sudar
{
    int x, y, d, a;
};

struct Staza
{
    int x1, y1, x2, y2, a;
};

vector<Sudar> sudari;

int IzracuajNZD (int m1, int m2)
{
    while(m1 != 0 && m2!= 0)
    {
        if(m1 >= m2)
            m1 = m1 % m2;
        else
            m2 = m2 % m1;
    }
    return m1 + m2;
}

void IspitajSudar (int p0_x, int p0_y, int p1_x, int p1_y, int a1, int p2_x, int p2_y, int p3_x, int p3_y, int a2)
{
    int s1_x(p1_x - p0_x), s1_y(p1_y - p0_y), s2_x(p3_x - p2_x), s2_y(p3_y - p2_y);
    double s, t;
    s = (-s1_y * (p0_x - p2_x) + s1_x * (p0_y - p2_y)) / double(-s2_x * s1_y + s1_x * s2_y);
    t = ( s2_x * (p0_y - p2_y) - s2_y * (p0_x - p2_x)) / double(-s2_x * s1_y + s1_x * s2_y);
    if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
    {
        int i_x(p0_x + (t * s1_x)), i_y(p0_y + (t * s1_y)), d1(sqrt((p0_x - i_x) * (p0_x - i_x) + (p0_y - i_y) * (p0_y - i_y))), d2(sqrt((p2_x - i_x) * (p2_x - i_x) + (p2_y - i_y) * (p2_y - i_y)));
        if(d1 * a2 == d2 * a1)
        {
            Sudar sudar;
            sudar.x = i_x;
            sudar.y = i_y;
            int NZD = IzracuajNZD (d1, a1);
            sudar.d = d1 / NZD;
            sudar.a = a1 / NZD;
            bool pronadjen = false;
            for (int i = 0; i < sudari.size(); i++)
                if(sudari[i].x == sudar.x && sudari[i].y == sudar.y && sudari[i].d == sudar.d && sudari[i].a == sudar.a)
                {
                    pronadjen = true;
                    break;
                }
            if(!pronadjen)
                    sudari.push_back(sudar);
        }
    }
}

int BrojSudara (int n, int* staze)
{
    sudari.resize(0);
    vector<Staza> formiraneStaze(n);
    for (int i = 0; i < n; i++)
    {
        formiraneStaze[i].x1 = staze[i * 5];
        formiraneStaze[i].y1 = staze[i * 5 + 1];
        formiraneStaze[i].x2 = staze[i * 5 + 2];
        formiraneStaze[i].y2 = staze[i * 5 + 3];
        formiraneStaze[i].a = staze[i * 5 + 4];
    }
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            IspitajSudar(formiraneStaze[i].x1, formiraneStaze[i].y1, formiraneStaze[i].x2, formiraneStaze[i].y2, formiraneStaze[i].a, formiraneStaze[j].x1, formiraneStaze[j].y1, formiraneStaze[j].x2, formiraneStaze[j].y2, formiraneStaze[j].a);
    return sudari.size();
}
