#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int m,n,i,j,s,t,d;
	int a[101][101];
	int next[101][101];
	int dist[101];
   	bool inque[101];
   	int que[10001];
   	int k;
   	cin >> n >> m;
	while ((m!=0)&&(n!=0)) {
		for (i=1;i<=n;i++) {
        	dist[i]=270000000;
        	inque[i]=1; 
        	a[i][0]=0;
    	} 
    	//ÁÚ½Ó±í½¨Í¼ 
	    for (i=1;i<=m;i++){
	    	cin >> s >> t >> d;
	    	a[s][0]++;a[s][a[s][0]]=d;next[s][a[s][0]]=t;
	    	a[t][0]++;a[t][a[t][0]]=d;next[t][a[t][0]]=s;
        }
        //spfa
       	inque[1]=0;
    	dist[1]=0;
    	int front=1;que[1]=1;int rear=1;
    	while (front<=rear){
    		inque[que[front]]=1;
    		int now=que[front];
    		front++;
    		for (i=1;i<=a[now][0];i++){
    			int dest=next[now][i];
    			if (dist[dest]>dist[now]+a[now][i]) {
    				dist[dest]=dist[now]+a[now][i];
    				if (inque[dest]){
    					rear++;
					    que[rear]=dest;
					    inque[dest]=0;
    				}
    			}
    		}
		} 
    	//in&out
    	cout << dist[n] <<endl; 
    	cin >> n >> m;
	}
	return 0;
}
