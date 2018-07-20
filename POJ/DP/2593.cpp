//最大区间和变形
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn=100005;
int t,n,ans,i,q,k;
int a[maxn],l[maxn],r[maxn];

int max(int a,int b){
	if (a>b) return a; else return b;
}

int main() {
	scanf("%d",&n);
	while (n) {
		scanf("%d",&a[1]);
		k=l[1]=a[1];
		for (i=2;i<=n;i++){
			scanf("%d",&a[i]);
			k=max(k,0)+a[i];
			l[i]=max(k,l[i-1]);
		}
		ans=-1<<30;
		k=0;
		r[n+1]=-1<<30;
		for (i=n;i>=2;i--) {
			k=max(k,0)+a[i];
			r[i]=max(k,r[i+1]);
			ans=max(ans,r[i]+l[i-1]);
		}
		cout << ans << endl;
		scanf("%d",&n);
	}
} 
