#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	ifstream fin("filter.in");
	ofstream fout("filter.out");
	long n,i,start=0;
	string text=" ";
	bool isNumber=1;
	fin>>n;
	fin.get();
	getline(fin, text);
	text+=" ";
	for (i=0;i<n+1;i++){
		if (!isdigit(text[i])){
			if (text[i]==' ' && isNumber && (i-start>0)){
				while (text[start]=='0' && (i-start>1)) start++;
				if (i-start>0) fout<<text.substr(start, i-start)<<endl;
			}
			isNumber=0;
		}
		if ((text[i]==' ') && isdigit(text[i+1])){
			isNumber=1;
			start=i+1;
		}
	}
	return 0;
}
