#include <cstdio>
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int maxn=7005;
int dp[maxn],dp2[maxn],a[maxn],b[maxn],r[maxn],r2[maxn];
struct node {
	int pos,pre;
	node(int pos,int pre): pos(pos),pre(pre) {}
};

int main() {
	int n,k1,k2,i,h=0,t=0,cnt,j;
	scanf("%d%d",&n,&k1);
	memset(dp,0,sizeof(dp));
	memset(dp2,0,sizeof(dp2));
	for (i=1;i<=k1;i++) {
		scanf("%d",&a[i]);
	}
	dp[0]=2;
	scanf("%d",&k2);
	int h2=0,t2=0;
	for (i=1;i<=k2;i++) {
		scanf("%d",&b[i]);
	}
	for (i=1;i<=n;i++) {
		r[i]=k1;r2[i]=k2;
	}
	dp2[0]=2;
	cnt=1;
	queue<node> q;
	q.push(node(0,1));
	q.push(node(0,2));
	while (!q.empty()) {
		int now=q.front().pos,p=q.front().pre;
		q.pop();
		if (p==1) {
			for (i=1;i<=k2;i++) {
				int pos=now-b[i];
				if (pos<0) pos+=n;
				if (!dp2[pos]) {
					if (dp[now]==2) {
						dp2[pos]=1;
						q.push(node(pos,2));
					} else {
						r2[pos]--;
						if (r2[pos]==0) {
							dp2[pos]=2;
							q.push(node(pos,2));
						}
					}
				}
			}
		} else {
			for (i=1;i<=k1;i++) {
				int pos=now-a[i];
				if (pos<0) pos+=n;
				if (!dp[pos]) {
					if (dp2[now]==2) {
						dp[pos]=1;
						q.push(node(pos,1));
					} else {
						r[pos]--;
						if (r[pos]==0) {
							dp[pos]=2;
							q.push(node(pos,1));
						}
					}
				}
			}
		}
	}
	for (i=1;i<=n-1;i++) {
		if (dp[i]==0) printf("Loop "); else
		    if (dp[i]==1) printf("Win "); else printf("Lose ");
	}
	printf("\n");
	for (i=1;i<=n-1;i++) {
		if (dp2[i]==0) printf("Loop "); else
		    if (dp2[i]==1) printf("Win "); else printf("Lose ");
	}
	return 0;
}
