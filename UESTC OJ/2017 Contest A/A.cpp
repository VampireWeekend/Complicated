#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
string s[28];

int main() {
	s[1]="@";
	s[2]="8";
	s[3]="(";
	s[4]="|)";
	s[5]="3";
	s[6]="#";
	s[7]="6";
	s[8]="[-]";
	s[9]="|";
	s[10]="_|";
    s[11]="|<";
    s[12]="1";
    s[13]="[]\\/[]";
    s[14]="[]\\[]";
    s[15]="0";
    s[16]="|D";
    s[17]="(,)";
    s[18]="|Z";
    s[19]="$";
    s[20]="']['";
    s[21]="|_|";
    s[22]="\\/";
    s[23]="\\/\\/";
    s[24]="}{";
    s[25]="`/";
    s[26]="2";
    char c;
    while (scanf("%c",&c)!=EOF) {
    	if (c>='a'&&c<='z') cout << s[c-'a'+1]; else
    	    if (c>='A'&&c<='Z') cout << s[c-'A'+1]; else cout << c;
    }
	return 0;
}
