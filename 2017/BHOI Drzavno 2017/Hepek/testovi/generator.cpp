#include <bits/stdc++.h>
using namespace std;

const long long MAX = 10000000000000000;

long long llrand() {
    unsigned long long r = 0;
    for (int i = 0; i < 5; ++i) {
        r = (r << 15) | (rand() & 0x7FFF);
    }
	long long x = (r & 0xFFFFFFFFFFFFFFFFULL) % (MAX+1);
    return x;
}

string ustr(int x) {
	string res;
	res += '0'+(x/10);
	res += '0'+(x % 10);
	return res;
}

void generateSubtask(int start, int number, long long MAXN, int MAXK, long long MAXV) {
	for(int i = 0; i < number; ++i) {
		ofstream of("in"+ustr(start+i)+".txt");
		long long n = 1 + llrand() % MAXN;
		if(number - i <= 2) n = MAXN;
		int k = MAXK, m = 100-MAXK;
		if(n < 100) {
			k = 1 + llrand() % n;
			m = n - k;
		} 
		long long offset = 1 + llrand() % (2*MAXV / 3);
		while(offset < 5) offset = 1 + llrand() % (2*MAXV / 3);
		of << n << " " << k << " " << m << " " << offset-1 << endl;
		long long dif = MAXV - offset;
		long long *a = new long long[k+m];
		long long *pos = new long long[k+m];
		for(int j = 0; j < k+m; ++j) {
			a[j] = offset + llrand() % (dif+1); 
			while(true) {
				pos[j] = 1 + llrand() % n;
				bool flag = true;
				for(int k = 0; k < j; ++k) {
					if(pos[k] == pos[j]) {
						flag = false;
						break;
					}
				}
				if(flag) break; 		
			}
		}
		if(number - i <= 2) {
			int idx = -1;
			long long mini = MAXN+1;
			for(int j = 0; j < k+m; ++j) {
				if(pos[j] < mini) {
					mini = pos[j];
					idx = j;
				}
			}
			if(pos[idx] > offset / 2) pos[idx] = offset / 2; 
		}	
		sort(a, a+k+m, greater<long long>());
		for(int j = 0; j < k+m; ++j) of << pos[j] << " " << a[j] << "\n";
	} 
}

int main() {
	srand(time(NULL));
	generateSubtask(0,5,100,50,1000);
	generateSubtask(5,5,50000,50,MAX);
	generateSubtask(10,5,1000000000,50,MAX);
	generateSubtask(15,5,MAX,1,MAX);
	generateSubtask(20,5,MAX,10,MAX);
	generateSubtask(25,5,MAX,50,MAX);
	return 0;
}
