#include <bits/stdc++.h>
using namespace std;

const long long MAX = 10000000000000000;

string ustr(int x) {
	string res;
	res += '0'+(x/10);
	res += '0'+(x % 10);
	return res;
}

void generateSubtask(int start, int number, long long MAXN, int MAXK, long long MAXV) {
	for(int i = 0; i < number; ++i) {
		ifstream is("in"+ustr(start+i)+".txt");
		ofstream os("out"+ustr(start+i)+".txt");
		long long n, k, m, modul;
		is >> n >> k >> m >> modul;
		os << "AjvarJeIstinskiPlavKadHaberZaspamaRIkurs\n";
		for(int j = 0; j < k; ++j) {
			long long p, x;
			is >> p >> x;
			os << x << endl;
		}
		os << "GdjeImaAjvaraImaIIstine\n";
	}
}

int main() {
	generateSubtask(0,5,100,50,1000);
	generateSubtask(5,5,50000,50,MAX);
	generateSubtask(10,5,1000000000,50,MAX);
	generateSubtask(15,5,MAX,1,MAX);
	generateSubtask(20,5,MAX,10,MAX);
	generateSubtask(25,5,MAX,50,MAX);
	return 0;
}
