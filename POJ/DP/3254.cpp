//״̬ѹ��DP 
#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;
const int mod=1e8;
const int maxn=12;
int dp[1<<maxn][maxn+1];
int map[maxn+1];
int state[1<<maxn];

int main() {
	int n,m,i,j,k;
	scanf("%d%d",&n,&m);
	int num=0;
	for (i=0;i<(1<<m);i++) 
		if ((i&(i<<1))==0)                //�ų����ڶ��ŵ������1��0���� 
		    state[++num]=i;
	
    for (i=1;i<=n;i++) 
    	for (j=1;j<=m;j++) {
    		scanf("%d",&k);
    		if (!k) 
			    map[i]+=(1<<(j-1));       //map==1���Էţ�0���ɷ� 
    	}
    memset(dp,0,sizeof(dp));
    for (j=1;j<=num;j++)
    	if ((state[j]&map[1])==0)         //״̬���ͼ����ͻ 
		    dp[j][1]=1;
    for (i=2;i<=n;i++) {
    	for (j=1;j<=num;j++) {
    		if ((state[j]&map[i])==0)
        		for (k=1;k<=num;k++)
    	        	if ((state[j]&state[k])==0) {     //����һ��״̬����ͻ 
    	        		dp[j][i]+=dp[k][i-1];
    	        		dp[j][i]%=mod;
    	        	}
    	} 
	}
	int ans=0; 
	for (j=1;j<=num;j++) {
		ans+=dp[j][n];
		ans%=mod;
	}
	printf("%d",ans);
	return 0;
}
