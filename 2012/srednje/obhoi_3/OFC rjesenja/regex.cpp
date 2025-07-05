/// 786

#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int MAX = 10005;

bool isspecial (char c) {
	return (c == '+' || c == '*');
}

int back[MAX];
int build (char *pattern) {
	back[0] = -1;
	int i;
	for (i = 0; pattern[i]&&!iswspace(pattern[i]); i++) {
		if (isspecial (pattern[i])) {
			back[i + 1] = i;
			continue;
		}

		back[i + 1] = back[i] + 1;
		while (back[i + 1] && !isspecial (pattern[back[i + 1] - 1]) && pattern[i] != pattern[back[i + 1] - 1])
			back[i + 1] = back[back[i + 1] - 1] + 1;
	}
	

	back[0] = 0;
	for (int j = 0; pattern[j]; j++)
		if (isspecial (pattern[j]))
			back[j + 1] = j + 1;
			
	return i;
}

int main (void) {
	char pattern[MAX], c;
	gets(pattern);
	int len=build (pattern);

	char buffer[50];
	gets(buffer);
	int n; sscanf(buffer,"%d",&n);
	
	while (n--) {	
		int pos = 0, start = 0, index = 0;

		c = getchar ();
		do {
			if(c == '\n' || c == EOF) break;
			if (pos == 0) start = index;
			if (pattern[pos] == '*') {
				pos++;
			}
			if (isspecial (pattern[pos]) || pattern[pos] == c) {
				pos++;
				if (pos == len) break;
			}
			else if (pos != back[pos]) {
				pos = back[pos];
				continue;
			}

			c = getchar ();
			index++;
		} while (!(c == '\n' || c == EOF));

		if (pos == len) {
			printf ("%d %d\n", start, index - start + 1);
			while (!(c == '\n' || c == EOF)) c=getchar();
		}
		else printf ("-1\n");
	}

	return 0;
}

