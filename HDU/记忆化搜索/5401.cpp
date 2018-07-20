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
//���仯���������������Ĵ𰸴������� 
map<pll,ll> q[maxn]; //�洢��i����j��k�ľ��� 
map<ll,ll> mp[maxn]; //�洢��i�������е㵽���Ϊk�Ľڵ�ľ��� 

ll getlen(int i,ll now,ll k) {  //�����i�����б��now�����k�ľ��� 
	if (now>k) swap(now,k);
	if (q[i].count(pll(now,k))) return q[i][pll(now,k)];
	if (k<size[a[i]]) //�������ڵ㶼�ڵ�a[i]�������У������ݹ� 
	    return q[i][pll(now,k)]=getlen(a[i],now,k);
	if (now>=size[a[i]]) //�������ڵ㶼�ڵ�b[i]�������У������ݹ� 
	    return q[i][pll(now,k)]=getlen(b[i],now-size[a[i]],k-size[a[i]]);
	//���ڵ㲻��ͬһ������������Ϊnow��a[i]����l[i]��b[i]�ٵ�k�ľ��� 
	return q[i][pll(now,k)]=(getlen(a[i],now,c[i])+l[i]+getlen(b[i],k-size[a[i]],d[i]))%mod;
}

ll getsum(int i,ll now) {   //�����i�������е㵽���Ϊnow�ľ���� 
	if (mp[i].count(now)) return mp[i][now];
	if (now<size[a[i]]) 
	    return mp[i][now]=(getsum(a[i],now)+
		(l[i]+getlen(a[i],now,c[i]))*msize[b[i]]%mod+
		getsum(b[i],d[i]))%mod;
	//�Ե�i������ͬ���ز�ֳ�������������now�������������е�ľ��롢
	//�����������нڵ�Դ𰸵Ĺ��� 
	//���У�����now���ڵ�a[i]����������������b[i]���нڵ�Դ𰸵Ĺ��� =
	//b[i]���нڵ㵽d[i]�ľ���+b[i]���нڵ㾭��l[i]��a[i]�ٵ�c[i]�ľ���
	//��now����b[i]����֮��Ȼ 
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
			//�ϲ�֮���Ϊ�����������ڲ��Ĵ𰸹���+·���˵�ֱ������������ϵĹ��� 
			//���У�·���˵�ֱ����������ϵĹ���= 
			//�����ӵı�l[i]�Ĺ���+�Է������ڵ���*c[i],d[i]�Žڵ㵽�����������нڵ����� 
			ans[i]%=mod;
			printf("%lld\n",ans[i]);
		}
	}
	return 0;
}

