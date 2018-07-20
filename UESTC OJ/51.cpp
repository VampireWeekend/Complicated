#include <cstdio>
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <string.h>
using namespace std;

int main () {
	string s;
	double price[21],f[21];
	int t,i,m,q,num,j;
	int z;
	double n;
	cin >> t;
	for (q=1;q<=t;q++) {
		cin >> n >> m;
		num=0;
		for (i=1;i<=n;i++) {
			cin >> s;
			int pos=s.rfind(" ");
			if ((s.find("spicy")<0)&&(s.find("sugar")<0)&&(s.find("pepper")<0)&&(s.find("duck")<0)) {
				num++;
				s.erase(0,pos+1);
				stringstream stream;
				stream << s;
				stream >> price[num];
				if (price[num]>m) num--;
				stream.clear();				
			}
		}
		memset(f,0,sizeof(f));
	/*	for (i=1;i<=num;i++) {
			for (j=20;j>=price[i];j--) {
				if (f[j]<f[j-price[i]]+price[i]) f[j]=f[j-price[i]]+price[i];
			}
		}*/
		
		cout << setioflags(ios::fixed) << setprecision(3);
		cout << f[20] << endl;
	}
}




