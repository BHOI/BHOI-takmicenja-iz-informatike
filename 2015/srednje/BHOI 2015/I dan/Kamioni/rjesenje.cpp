using namespace std;

int KoJeBlizi(int x1, int y1, int x2, int y2)
{
    unsigned long long l1 = (unsigned long long)x1 * x1 + (unsigned long long)y1 * y1;
    unsigned long long l2 = (unsigned long long)x2 * x2 + (unsigned long long)y2 * y2;
    if(l1 == l2)
        return 0;
    if(l1 < l2)
        return 1;
    return 2;
}
