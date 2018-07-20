#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <deque>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#include <iomanip>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=25,maxk=(1<<20)+5,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
ll a[maxn],b[maxn];
ll ax[maxk],bx[maxk],aw[maxk],bw[maxk];
bool af[maxk],bf[maxk];   
ll cnt[maxk];
char s[maxn][maxn];

int main() {
	int n,m,na,nb,i,j;
	scanf("%d%d",&n,&m);
	for (i=0;i<n;i++) {
		scanf("%s",s[i]);
		for (j=0;j<m;j++) 
			if (s[i][j]=='1') aw[1<<i]|=1<<j,bw[1<<j]|=1<<i;
	}

	for (i=0;i<n;i++) 
		scanf("%lld",&a[i]);
	for (i=0;i<m;i++)
		scanf("%lld",&b[i]);
	cnt[0]=0;
	for (i=1;i<max(1<<n,1<<m);i++) 
		cnt[i]=cnt[i/2]+i%2;
	ll t;
	scanf("%lld",&t);
	na=nb=0;
	for (i=0;i<(1<<n);i++) {
		ll sum=0;
		af[i]=1;
		for (j=0;j<n;j++) {
			if ((i>>j)%2==1) {
				sum+=a[j];                    //当前状态的点的权值和
				aw[i]=aw[i]|aw[i^(1<<j)];     //对应另一组点的状态
				af[i]=af[i]&af[i^(1<<j)];     //状态合法性转移
			}
		}
		af[i]=af[i]&&(cnt[i]<=cnt[aw[i]]);
		if (af[i]) 
			ax[na++]=sum;
	}
	for (i=0;i<(1<<m);i++) {
		ll sum=0;
		bf[i]=1;
		for (j=0;j<m;j++) {
			if ((i>>j)%2==1) {
				sum+=b[j];
				bw[i]=bw[i]|bw[i^(1<<j)];
				bf[i]=bf[i]&bf[i^(1<<j)];
			}
		}
		bf[i]=bf[i]&&(cnt[i]<=cnt[bw[i]]);
		if (bf[i]) 
			bx[nb++]=sum;
	}
	sort(ax,ax+na);
	ll ans=0;
	for (i=0;i<nb;i++) {
		ans+=na-(lower_bound(ax,ax+na,t-bx[i])-ax);
	}
	printf("%lld\n",ans);
	return 0;
}
