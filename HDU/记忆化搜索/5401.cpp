#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#include <utility>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
#define pll pair<ll,ll>
typedef long long ll;
typedef long double ld;
using namespace std;
const int maxn=65,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=1e9+7;   
const ld pi=acos(-1.0L);
ll a[maxn],b[maxn],c[maxn],d[maxn],l[maxn],size[maxn],msize[maxn],ans[maxn];
//记忆化搜索，把搜索过的答案储存起来 
map<pll,ll> q[maxn]; //存储第i棵树j到k的距离 
map<ll,ll> mp[maxn]; //存储第i棵树所有点到编号为k的节点的距离 

ll getlen(int i,ll now,ll k) {  //计算第i棵树中编号now到编号k的距离 
	if (now>k) swap(now,k);
	if (q[i].count(pll(now,k))) return q[i][pll(now,k)];
	if (k<size[a[i]]) //若两个节点都在第a[i]棵树当中，继续递归 
	    return q[i][pll(now,k)]=getlen(a[i],now,k);
	if (now>=size[a[i]]) //若两个节点都在第b[i]棵树当中，继续递归 
	    return q[i][pll(now,k)]=getlen(b[i],now-size[a[i]],k-size[a[i]]);
	//若节点不在同一棵子树，距离为now到a[i]经过l[i]到b[i]再到k的距离 
	return q[i][pll(now,k)]=(getlen(a[i],now,c[i])+l[i]+getlen(b[i],k-size[a[i]],d[i]))%mod;
}

ll getsum(int i,ll now) {   //计算第i棵树所有点到编号为now的距离和 
	if (mp[i].count(now)) return mp[i][now];
	if (now<size[a[i]]) 
	    return mp[i][now]=(getsum(a[i],now)+
		(l[i]+getlen(a[i],now,c[i]))*msize[b[i]]%mod+
		getsum(b[i],d[i]))%mod;
	//对第i棵树，同样地拆分成两棵树，计算now到所属子树所有点的距离、
	//对面子树所有节点对答案的贡献 
	//其中，假设now属于第a[i]棵子树，对面子树b[i]所有节点对答案的贡献 =
	//b[i]所有节点到d[i]的距离+b[i]所有节点经过l[i]到a[i]再到c[i]的距离
	//若now属于b[i]，则反之亦然 
	else 
	    return mp[i][now]=(getsum(b[i],now-size[a[i]])+
		(l[i]+getlen(b[i],now-size[a[i]],d[i]))*msize[a[i]]+
		getsum(a[i],c[i]))%mod;
}

int main() {
    int n;
	while (scanf("%d",&n)!=EOF) {
		int i,j;
		for (i=0;i<=60;i++) {
			mp[i].clear();q[i].clear();
		}
		q[0][pll(0,0)]=0;
		mp[0][0]=0;
		size[0]=msize[0]=1;ans[0]=0; 
		for (i=1;i<=n;i++) {
			scanf("%lld%lld%lld%lld%lld",&a[i],&b[i],&c[i],&d[i],&l[i]);
			size[i]=size[a[i]]+size[b[i]];
			msize[i]=size[i]%mod;
			ans[i]=ans[a[i]]+ans[b[i]]+
			((l[i]*msize[a[i]])%mod)*msize[b[i]]%mod+
			msize[b[i]]*getsum(a[i],c[i])%mod+
			msize[a[i]]*getsum(b[i],d[i])%mod;
			//合并之后答案为两棵树各自内部的答案贡献+路径端点分别在两棵子树上的贡献 
			//其中，路径端点分别在两棵树上的贡献= 
			//新增加的边l[i]的贡献+对方子树节点数*c[i],d[i]号节点到各自子树所有节点距离和 
			ans[i]%=mod;
			printf("%lld\n",ans[i]);
		}
	}
	return 0;
}

