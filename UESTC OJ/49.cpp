#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int t,h,m,i;

int main() {
    cin >> t;
	for (i=1;i<=t;i++){
		scanf("%d:%d",&h,&m);
		if (h>=12) h-=12;
		int v=abs(h*60-m*11);
		if (v>360) v=720-v;
		if (v%2==0) cout << v/2 << endl; else cout << v << "/2" << endl;
	}	
	return 0;
}
