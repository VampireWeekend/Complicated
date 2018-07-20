#include <cstdio>
#include <iostream>
#include <set>
#include <string.h>
using namespace std;
long long a[2];
int path[1001];

bool dfs(int i,int num) {
	if (i==50000) return true; else return dfs(i+1,(num%8)+1);
}

int main () {
	memset(path,-1,sizeof(path));
	for (int i=1;i<=1000;i++) cout << path[i] << ' ';
}

