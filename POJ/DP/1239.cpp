//LIS
#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
const int maxn=85;
char s[maxn];
int dp[maxn]; 
//cmp(i,j,k,l)�ж�i-jλ�����Ƿ����k-lλ���� 
bool cmp(int i,int j,int k,int l) {
	int x=i,y=k;
	while (s[x]=='0'&&x<=j) x++;
	while (s[y]=='0'&&y<=l) y++;
	if (j-x+1>l-y+1) return true;
	if (j-x+1<l-y+1) return false;
	for (;x<=j&&y<=l;x++,y++) {
		if (s[x]>s[y]) return true;
		if (s[x]<s[y]) return false;
	}
	return false;
}

int main() {
	int i,j;
	scanf("%s",s);
	while (!(s[0]=='0'&&strlen(s)==1)) {
		int len=strlen(s);
		dp[0]=1;
	    //��ǰ����DP���ҳ����һ��������Сֵ�������һ���������ܵ�С
	    //dp[i]��ʾ��iλ����ǰ����ĳ��� 
		for (i=1;i<len;i++) {
			dp[i]=i+1;
			for (j=i-1;j>=0;j--) {
				if (cmp(j+1,i,j-dp[j]+1,j)) {
					dp[i]=i-j;
					break;
				}
			}
		}
		//�Ӻ���ǰDP���ҳ���ǰ��һ���������ֵ������һ���������ܵĴ�
		//dp[i]��ʾ��iλ���������ĳ���
		dp[len-dp[len-1]]=dp[len-1];
		for (i=len-dp[len-1]-1;i>=0;i--) {
			dp[i]=len-dp[len-1]-i;
			if (s[i]=='0') {
				dp[i]=dp[i+1]+1;
				continue;
			}
			for (j=len-dp[len-1];j>i;j--) {
				if (cmp(j,j+dp[j]-1,i,j-1)) {
					dp[i]=j-i;
					break;
				}
			}
		}
		for (i=0;i<len;i+=dp[i]) {
			for (j=i;j<i+dp[i];j++) {
				printf("%c",s[j]);
			}
			if (j!=len) printf(",");
		}
		printf("\n");
		scanf("%s",s);
	}
	return 0;
}
