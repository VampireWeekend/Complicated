package com.five;

import java.io.*;
import java.util.Scanner;

public class Main {
	
	static int max(int a,int b) {
		if (a>b) return a; else return b;
	}
	
	public static void main (String[] args) {
	    int maxn,n,a,b,c,i,j,k,h=-1,t=-1;
	    maxn=(1<<21);
	    int dp[] = new int [maxn];
	    int q[] = new int [maxn];
	    int mark[] = new int [maxn];
	    int qi[] = new int [maxn];
		int val[] = new int [1500];
		int state[] = new int [1500];
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		int m=n*(n-1)*(n-2)/6,full=(1<<n)-1;
		if (n==3) {
			a = in.nextInt();
			a = in.nextInt();
			a = in.nextInt();
			a = in.nextInt();
			System.out.println(a);
		}else {
			for (i=0;i<m;i++) {
				a = in.nextInt();
				b = in.nextInt();
				c = in.nextInt();
				val[i] = in.nextInt();
				state[i]=(1<<(a-1))+(1<<(b-1))+(1<<(c-1));
				q[++t]=state[i];
				qi[state[i]]=t;
				dp[t]=val[i];
				mark[state[i]]=1;
			}
			for (i=2;i<=(n+3)/6;i++) { 
			    int num=t;
				for (j=h+1;j<=num;j++) {
					for (k=0;k<m;k++) {
						if ((q[j]&state[k])==0) {
							int s=q[j]|state[k];
							if (mark[s]==0) {
								mark[s]=1;
								q[++t]=s;
								qi[s]=t;
								dp[t]=dp[j]+val[k];
							} else
							dp[qi[s]]=max(dp[qi[s]],dp[j]+val[k]);
						}
					}
				}
				h=num;
			}
			int ans=0;
			for (i=h+1;i<=t;i++) 
				ans=max(ans,dp[qi[full-q[i]]]+dp[i]);
			System.out.println(ans);
		}
	}
}