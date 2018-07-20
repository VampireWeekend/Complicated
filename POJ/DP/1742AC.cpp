//�� F[i, j] ��ʾ������ǰ i ����Ʒ��������Ϊ j �ı�������໹ʣ
//�¼����� i ����Ʒ���á������ F[i, j] = ?1 ��˵������״̬�����У�������Ӧ����
//0 �� F[i, j] �� Mi��
#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
const int maxn=100005;
int dp[maxn],a[maxn],c[maxn],sum[maxn];

int main() {
	int n,m,i,j,k;
	scanf("%d%d",&n,&m);
	while (n&&m) {
		int ans=0;
		for (i=1;i<=n;i++) scanf("%d",&a[i]);
		for (i=1;i<=n;i++) scanf("%d",&c[i]);
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for (i=1;i<=n;i++) {
			memset(sum,0,sizeof(sum));
			for (j=0;j<=m-a[i];j++) {				
				if (dp[j]&&!dp[j+a[i]]&&sum[j]<c[i]) {
					dp[j+a[i]]=1;
					sum[j+a[i]]=sum[j]+1;
					ans++;
				}
			} 
		}
		printf("%d\n",ans);
		scanf("%d%d",&n,&m);
	}
	return 0;
}
