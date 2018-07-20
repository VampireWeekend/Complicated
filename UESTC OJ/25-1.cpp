#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;

int main () {
	int n,i;
	char s[19][128];
	while ((scanf("%d",&n)!=EOF)&&(n)) {
		getchar();
		for (i=1;i<=n;i++) 
		    gets(s[i]);
		for (i=1;i<=(n+1)/2;i++) cout << i << ' ';
		cout << "Score" << endl;
	
		int j=0;
		for (i=1;i<=n;i+=2) {
			int len=strlen(s[i]); 
			if (s[i][len-7] == 'n' && s[i][len-6] == 'o' && s[i][len-8] == ' ' && s[i][len-5] == ' ') {
			    cout << "X ";
		    } else {
		    	cout << "O ";
		    	j++;
		    }
		}
		cout << j << endl;
		
		j=0;
		for (i=2;i<=n;i+=2) {
			int len=strlen(s[i]); 
			if (s[i][len-7] == 'n' && s[i][len-6] == 'o' && s[i][len-8] == ' ' && s[i][len-5] == ' ') {
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
