#include <iostream>
#include <cstdio> 
#include <string>
using namespace std;

int main ()
{
	string s;
	int n,i,len;
	cin >> n;
	while (n!=0){
		cin >> s;
		len=s.length();
		int y=0; int r=0;
		for (i=0;i<len;i++){
			if (s[i]=='R') r++; else
			    if (s[i]=='Y') y++; else 
				    if (s[i]=='B') {
						    if (r==7) cout << "Red" << endl; else cout << "Yellow" << endl;
						    break;
				    }
				    if (s[i]=='L') {
						    if (y!=7) cout << "Red" << endl; else cout << "Yellow" << endl;
						    break;
					}
	    } 
	    cin >> n;
	}
	return 0;
}
