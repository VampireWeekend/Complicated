#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int a[19],b[11],c[11];
int ans,len;

void dfs (int depth,int l,int r,int flag0,int flag1) {
	if (!b[l]) return;
	if (!c[r]) return;
	if (depth==len+1) ans++; else {
		b[r]=c[l]=0;
		if (a[depth]==0) {
			dfs(depth+1,1,9,flag0,flag1);
			dfs(depth+1,2,8,flag0,flag1);
			dfs(depth+1,3,7,flag0,flag1);
			dfs(depth+1,4,6,flag0,flag1);
			dfs(depth+1,6,4,flag0,flag1);
			dfs(depth+1,7,3,flag0,flag1);
			dfs(depth+1,8,2,flag0,flag1);
			dfs(depth+1,9,1,flag0,flag1);
	    } 
	    if (a[depth]==1) {
			dfs(depth+1,0,1,0,flag1);
			dfs(depth+1,2,9,flag0,0);
			if (!flag0&&!flag1) {
				dfs(depth+1,2,9,flag0,flag1);
			    dfs(depth+1,3,8,flag0,flag1);
		    	dfs(depth+1,4,7,flag0,flag1);
		    	dfs(depth+1,5,6,flag0,flag1);
		    	dfs(depth+1,6,5,flag0,flag1);
		    	dfs(depth+1,7,4,flag0,flag1);
		    	dfs(depth+1,8,3,flag0,flag1);
		    	dfs(depth+1,9,2,flag0,flag1);
			}	
	    } 
	    	if (a[depth]==0) {
			dfs(depth+1,1,9);
			dfs(depth+1,2,8);
			dfs(depth+1,3,7);
			dfs(depth+1,4,6);
			dfs(depth+1,6,4);
			dfs(depth+1,7,3);
			dfs(depth+1,8,2);
			dfs(depth+1,9,1);
	    } 
		b[r]=c[l]=1;
	}
}

int main() {
	string s;
	scanf("%s",s);
	len=s.length();
	for (i=0;i<=9;i++)
	    b[i]=c[i]=d[i]=1;
	for (i=0;i<s.length();i++) {
		a[s.length()-i]=s[i]-'0';
		b[a[s.length()-i]]=c[a[s.length()-i]]=0;
	}
	ans=0;
	dfs(1,10,10);
}
