#include <iostream>
 
using namespace std;
 
int main() {
    long long n;
	cin >> n;

	int br = 1, tr = 1;

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=i; j++) {
			tr = j;
			br++;
			if(br > n) break;
		}
		if(br > n) break;
	}
	cout << tr << endl;
    
    return 0;
}