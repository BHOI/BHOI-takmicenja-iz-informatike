#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <ctime>
#include <utility>

using namespace std;

#define TEST_CASE   20
#define BOUNDRY     10
#define MAXN       210
#define MAXN       210
#define MAX_LASERS 100

namespace competitive
{
class random
{
private:
    int seed_val;

public:

    mt19937 rng;
    std::uniform_int_distribution<int> get_rand;

    random ()
    {
        seed_val = time (0);
        rng.seed(seed_val);
    }

    int generate (int up_to)
    {
        return get_rand(rng) % up_to;
    }

    int generate (int from, int where)
    {
        return generate (where - from + 1) + from;
    }
};

string generate_string(int length)
{
    random r;
    string ret = "";

    for (int i = 0; i < length; i++)
        ret += (char)('a' + r.generate(26));
    return ret;
}

string to_string (int x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

string make_in_name(int number)
{
    return ((number < 10) ? "input0" : "input") + to_string(number) + ".txt";
}

string make_out_name(int number)
{
    return ((number < 10) ? "output0" : "output") + to_string(number) + ".txt";
}
}

competitive::random r;

int dirX [4] = { -1, 0, 1, 0 };
int dirY [4] = { 0, 1, 0, -1 };

struct point
{
    int x, y;

    point() { }
    point(int _x, int _y)
    {
        x = _x;
        y = _y;
    }

    void set(int _x, int _y)
    {
        x = _x;
        y = _y;
    }

    void print() const
    {
        printf ("x: %d y: %d\n", x, y);
    }
    void print()
    {
        printf ("x: %d y: %d\n", x, y);
    }

    void add(int i)
    {
        x += dirX [i];
        y += dirY [i];
    }

    bool operator== (const point &B) const
    {
        return x == B.x && y == B.y;
    }
};

int get_direction(int current_direction, char mirror)
{
    if (mirror == '/')
    {
        if (current_direction == 0)
            return 1;
        else if (current_direction == 1)
            return 0;
        else if (current_direction == 2)
            return 3;
        else
            return 2;
    }
    else if (mirror == '\\')
    {
        if (current_direction == 0)
            return 3;
        else if (current_direction == 1)
            return 2;
        else if (current_direction == 2)
            return 1;
        else
            return 0;
    }
    else
        return current_direction;
}

void print_field(int n, int m, char **field)
{
    for (int i = 1; i <= n; i++, putchar ('\n'))
        for (int j = 1; j <= m; j++)
            putchar (field [i] [j]);
    putchar ('\n');
}

bool check (const point &start, int direction, char (*field) [210])
{
    bool visited [210] [210] [4];
    memset (visited, false, sizeof visited);
    point current_location = start;
    int current_direction = direction;

    while (!visited [current_location.x] [current_location.y] [current_direction])
    {
        char current_char = field [current_location.x] [current_location.y];

        if (current_char != '.'  &&
                current_char != 'S'  &&
                current_char != 'E'  &&
                current_char != '\\' &&
                current_char != '/' ||
                current_char == 0)
            return false;

        if (field [current_location.x] [current_location.y] == 'E')
            return true;

        visited [current_location.x] [current_location.y] [current_direction] = true;
        current_location.add (current_direction);
        if (field [current_location.x] [current_location.y] == 0)
            return false;
        current_direction = get_direction (current_direction, field [current_location.x] [current_location.y]);
    }

    return false;
}

string solve(int n, int m, int direction, char (*field) [210])
{
    point start, end;
    vector <point> mirrors;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (field [i] [j] == 'S')
                start.set(i, j);
            else if (field [i] [j] == 'E')
                end.set(i, j);
            else if (field [i] [j] != '.')
                mirrors.emplace_back(i, j);
        }
    }

    if (check(start, direction, field))
        return "nije potrebno vrsiti izmjene";

    for (point mirror : mirrors)
    {
        if (field [mirror.x] [mirror.y] == '\\')
            field [mirror.x] [mirror.y] = '/';
        else
            field [mirror.x] [mirror.y] = '\\';

        if (check (start, direction, field))
        {
            stringstream ss;
            ss<<mirror.x<<" "<<mirror.y;
            return ss.str();
        }

        if (field [mirror.x] [mirror.y] == '\\')
            field [mirror.x] [mirror.y] = '/';
        else
            field [mirror.x] [mirror.y] = '\\';
    }

    return "nemoguce";
}

void set_data(int test_case, point &start, point &end, int &n, int &m, int &direction)
{
    if (test_case < 5)
    {
        n = 5;
        m = 5;
    }
    else if (test_case < 10)
    {
        n = 50;
        m = 50;
    }
    else
    {
        n = 200;
        m = 200;
    }

    if (test_case % 2 == 0)
    {
        direction = 1;
        start.set(n, 1);
        end.set(1, m);
    }
    else
    {
        direction = 3;
        start.set(1, m);
        end.set(n, 1);
    }
}

int main()
{
    int n, m, direction;

    char field [210] [210];

    for (int i = 0; i < 210; i++)
        for (int j = 0; j < 210; j++)
            field [i] [j] = 0;

    scanf ("%d %d %d", &n, &m, &direction); getchar();
    for (int i = 1; i <= n; i++, getchar())
        for (int j = 1; j <= m; j++)
            field [i] [j] = getchar();

    cout<<solve (n, m, direction, field)<<endl;


    return 0;
}


