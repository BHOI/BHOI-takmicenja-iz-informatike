#include <iostream>
 
using namespace std;
 
int main() {
    long long n;
	cin >> n;

	int i = 1;

	while(n > i) {
		n -= i;
		i++;
	}

	cout << n << endl;
    
    return 0;
}