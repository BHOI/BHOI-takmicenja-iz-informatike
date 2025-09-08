#include <iostream>

using namespace std;

int main()
{
	int a, b;
	string s;

	cin >> a >> b >> s;
	if(a > b) swap(a, b);

	int br_u = 0, br_d = 0;

	for(int i = a; i < b; i++)
	{
		if(s[i] == 'D') {
			if(br_u > 0) {
				br_u--;
			} else {
				br_d++;
			}
		} else {
			br_u++;
		}
	}

	cout << br_u + br_d << endl;

	return 0;
}