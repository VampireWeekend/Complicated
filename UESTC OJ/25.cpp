#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;

int main () {
	int n,i;
	cin >> n;
	char s[19][128];
	while (n!=0) {
		for (i=1;i<=n;i++) 
		    getline(cin,s[i]);
		for (i=1;i<=n/2;i++) cout << i << ' ';
		cout << "Score" << endl;
	
		int j=0;
		for (i=1;i<=n;i+=2) {
			int pos=s[i].rfind(' ');
			if (s[i].substr(pos-3,3)==" no") {
			    cout << "X ";
		    } else {
		    	cout << "O ";
		    	j++;
		    }
		}
		cout << j << endl;
		
		j=0;
		for (i=2;i<=n;i+=2) {
			int pos=s[i].rfind(' ');
			if (s[i].substr(pos-3,3)==" no") {
			    cout << "X ";
		    } else {
		    	cout << "O ";
		    	j++;
		    }
		}
		if (n%2==1) cout << "- ";
		cout << j << endl;
	}
	return 0;
}
