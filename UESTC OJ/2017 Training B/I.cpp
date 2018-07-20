#include <cstdio>
#include <string.h>
#include <iostream>
using namespace std;
int a[1<<16],mark[1<<16];
int n,ans;

bool dfs(int depth,int num) {
	if (mark[num]) return false; 
	    else mark[num]=1;
	if (depth>(1<<n)){
		int j=num;
		for (int i=1;i<n;i++) {
			j=(j%(1<<(n-1)))*2+a[i];
			if (mark[j]) {
				mark[num]=0;
				return false;
			}
		}
		return true;
	} else {
		if (dfs(depth+1,(num%(1<<(n-1)))*2)) return true;
		a[depth]=1;
		if (dfs(depth+1,(num%(1<<(n-1)))*2+1)) return true;
		a[depth]=0;
	}
	mark[num]=0;
	return false;
}

int main() {
	int i;
	cin >> n;
	memset(a,0,sizeof(a));
	memset(mark,0,sizeof(mark));
	if (dfs(n+1,0))
    	for (i=1;i<=1<<n;i++) cout << a[i];
	return 0;
}
/*
4
0000100110101111
*/
