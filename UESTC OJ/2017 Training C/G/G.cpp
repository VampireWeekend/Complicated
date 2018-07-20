#include <cstdio>
#include <iostream>
#include <stack>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn=10005;
int a[maxn],pre[maxn*10],d[maxn],st[maxn],di[maxn];

int main() {
	int q,t,i,j,n,top;
	scanf("%d",&q);
	for (t=1;t<=q;t++) {
		scanf("%d",&n);
		memset(pre,0,sizeof(pre));
		memset(d,0x3f,sizeof(d));
		for (i=1;i<=n;i++)
			scanf("%d",&a[i]);
		d[0]=di[0]=-1;
		top=0;
		for (i=1;i<=n;i++) {
			int pos=lower_bound(d+1,d+n+1,a[i])-d;
		    if (pos>top) top++;
		   	pre[i]=di[pos-1];
			d[pos]=a[i];
			di[pos]=i;
		}
		printf("%d ",top);
		int x=di[top];
		stack<int> st;
		st.push(a[x]);
		while (pre[x]!=-1) {
			x=pre[x];
			st.push(a[x]);
		}
		while (!st.empty()){
			printf("%d ",st.top());
			st.pop();
		}
		printf("\n");
	}
	return 0;
}
