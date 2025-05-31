#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void die (char *msg) {
	puts (msg);
	exit(0);
}

const int MAXN = 1002;
string s[MAXN];

int main () {
	int n = 0;
	while (cin.good()) {
		getline (cin, s[n++]);	
	}

	n--;

	for (int i = 1; i < n; i++) {
		if (s[i].size() != s[0].size()) die ("NEISPRAVNA PORUKA");
	}

	bool border = false;

	if (s[0][0] == '+' && s[0][s[0].size() - 1] == '+' && s[n - 1][0] == '+' && s[n - 1][s[n - 1].size() - 1] == '+') {
		for (int i = 1; i < s[0].size() - 1; i++) {
			if (s[0][i] != '-')	die ("NEISPRAVNA PORUKA");
			if (s[n - 1][i] != '-') die ("NEISPRAVNA PORUKA");		
		}
		for (int i = 1; i < n - 1; i++) {
			if (s[i][0] != '|') die ("NEISPRAVNA PORUKA");		
			if (s[i][s[i].size() - 1] != '|') die ("NEISPRAVNA PORUKA");
		}

		border = true;
	}

	string e = "";

	if (border) {
		for (int i = 1; i < n - 1; i++)
			for (int j = 1; j < s[i].size() - 1; j++) {
				if (s[i][j] == '+' || s[i][j] == '-' || s[i][j] == '|') die ("NEISPRAVNA PORUKA");
				else if (s[i][j] == 'o') e += "1";
				else if (s[i][j] == '.') e += "0";			
			}	
	}
	else {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < s[i].size(); j++) {
				if (s[i][j] == '+' || s[i][j] == '-' || s[i][j] == '|') die ("NEISPRAVNA PORUKA");
				else if (s[i][j] == 'o') e += "1";
				else if (s[i][j] == '.') e += "0";			
			}	
	}

	if (e.size() % 7) die ("NEISPRAVNA PORUKA");

	//cout << e << endl;

	int ascii = 0;

	for (int i = 0; i < e.size(); i++) {
		ascii += (e[i] - '0') * (1 << (6 - (i % 7)));
	
		if ((i > 0) && (i + 1) % 7 == 0) {
			cout << (char) ascii;
			ascii =	0;	
		}	
	}

	//cout << endl;

	return 0;
}
