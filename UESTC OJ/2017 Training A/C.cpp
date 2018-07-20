//Êý×é·Ö¿é
#include <cstdio>
#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;
const int maxn=100005;
const int maxk=400;
ll p;
int head[maxk],tail[maxk],pos[maxn];
ll kuai[maxn],sum[maxk],plusv[maxk],mult[maxk];
int num;

void build(int n) {
	int i,j,m;
	num=m=sqrt(n);
	if (n%num!=0) num++; 
	for (i=1;i<=num;i++) {
		head[i]=(i-1)*m+1;
		tail[i]=i*m;
	}
	tail[num]=n;
	for (i=1;i<=num;i++) {
		plusv[i]=sum[i]=0;
		mult[i]=1;
		for (j=head[i];j<=tail[i];j++) {
			scanf("%lld",&kuai[j]);
			kuai[j]%=p;
			sum[i]+=kuai[j];
			sum[i]%=p;
			pos[j]=i;
		}
	}
}

void multiple(int l,int r,ll c) {
	int i;
	if (pos[l]!=pos[r]) {
		for (i=l;i<=tail[pos[l]];i++) {
			sum[pos[l]]-=kuai[i];
			kuai[i]*=c;
			kuai[i]%=p;
			sum[pos[l]]+=kuai[i];
		}
		sum[pos[l]]%=p;
		for (i=pos[l]+1;i<pos[r];i++) {
			mult[i]*=c;
			mult[i]%=p;
			plusv[i]*=c;
			plusv[i]%=p;
		}
		for (i=head[pos[r]];i<=r;i++) {
			sum[pos[r]]-=kuai[i];
			kuai[i]*=c;
			kuai[i]%=p;
			sum[pos[r]]+=kuai[i];
		}
		sum[pos[r]]%=p;
	} else {
		for (i=l;i<=r;i++) {
			sum[pos[l]]-=kuai[i];
			kuai[i]*=c;
			kuai[i]%=p;
			sum[pos[l]]+=kuai[i];
		}
		sum[pos[l]]%=p;
	}
}

void add(int l,int r,ll c) {
	int i;
	if (pos[l]!=pos[r]) {
		for (i=l;i<=tail[pos[l]];i++) {
			kuai[i]+=c;
			kuai[i]%=p;
		}
		sum[pos[l]]+=(c*(tail[pos[l]]-l+1));
		sum[pos[l]]%=p;
		for (i=pos[l]+1;i<pos[r];i++) {
			plusv[i]+=c;
			plusv[i]%=p;
		}
		for (i=head[pos[r]];i<=r;i++) {
			kuai[i]+=c;
			kuai[i]%=p;
		}
		sum[pos[r]]+=(c*(r-head[pos[r]]+1));
		sum[pos[r]]%=p;
	} else {
		for (i=l;i<=r;i++) {
			kuai[i]+=c;
			kuai[i]%=p;
		}
		sum[pos[l]]+=(c*(r-l+1));
		sum[pos[l]]%=p;
	}
}

ll findsum(int l,int r) {
	int i,ans=0;
	if (pos[l]!=pos[r]) {
		for (i=l;i<=tail[pos[l]];i++) {
			ans+=(kuai[i]*mult[pos[l]]+plusv[pos[l]]);
			ans%=p;
		}
		for (i=pos[l]+1;i<pos[r];i++) {
			ans+=(sum[i]*mult[i]+plusv[i]);
			ans%=p;
		}
		for (i=head[pos[r]];i<=r;i++) {
			ans+=(kuai[i]*mult[pos[r]]+plusv[pos[r]]);
			ans%=p;
		}
	} else {
		for (i=l;i<=r;i++) {
			ans+=(kuai[i]*mult[pos[l]]+plusv[pos[l]]);
			ans%=p;
		}
	}
	return ans;
}

int main(){
	int n,m,l,op,r,k;
	ll c; 
	scanf("%d%lld",&n,&p);
    build(n);
	scanf("%d",&m);
	for (k=1;k<=m;k++) {
		scanf("%d",&op);
		if (op==1) {
			scanf("%d%d%lld",&l,&r,&c);
			multiple(l,r,c);
		} else if (op==2) {
			scanf("%d%d%lld",&l,&r,&c);
			add(l,r,c);
		} else {
			scanf("%d%d",&l,&r);
			ll ans=findsum(l,r);
			printf("%lld\n",ans);
		}
	}
	return 0;
} 
