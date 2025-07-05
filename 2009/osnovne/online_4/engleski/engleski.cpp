/// 786

#include <string>
#include <iostream>
using namespace std;

void prints (int a)
{
	string mali[] = {
		"zero", "one", "two", "three", "four", "five",
		"six", "seven", "eight", "nine"
	};
	string srednji[] = {
		"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
		"sixteen", "seventeen", "eighteen", "nineteen"
	};
	string veliki[] = {
		"", "", "twenty", "thirty", "forty",
		"fifty", "sixty", "seventy", "eighty", "ninety"
	};
	if (a >= 100) cout << mali[a / 100] << " hundred ";
	a %= 100;
	if (!a) return;
	if (a < 10) cout << mali[a] << " ";
	else if (a < 20) cout << srednji [a % 10] << " ";
	else if (a % 10 == 0) cout << veliki[a / 10] << " ";
	else cout << veliki[a / 10] << " " << mali[a % 10] << " ";
}

int main (void)
{
	//prints(9);
	int n;
	cin >> n;

	if (n < 0)
	{
		cout << "minus ";
		n = -n;
	}
	if (n >= 1000)
	{
		prints (n / 1000);
		cout << "thousand ";
	}
	if (n != 0) prints (n % 1000);
	else cout << "zero ";
	cout << endl;

	return 0;
}
