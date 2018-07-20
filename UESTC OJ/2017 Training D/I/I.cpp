#include <cstdio>
#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;
const int maxn=9;
int path[1000][maxn],step[maxn];
int ans;

bool check(int x,int y) {
	int i,j;
	for (i=0;i<x;i++) {
		if (abs(x-i)==abs(y-step[i])||y==step[i]) return false;
	}
	return true;
}

void dfs(int n) {
	if (n==maxn) {
		ans++;
		for (int i=0;i<=8;i++) path[ans][i]=step[i];
	} else {
		for (int i=0;i<=8;i++) {
			if (check(n,i)) {
				step[n]=i;
				dfs(n+1);
			}
		}
	}
}

int main() {
	ans=0;
	dfs(0);
	int i,j;
	cout << ans << endl;
	for (i=1;i<=ans;i++) {
		for (j=0;j<=8;j++) {
			cout << path[i][j]+1 << ' ';
		}
		cout << '\n';
	}
	return 0;
}
