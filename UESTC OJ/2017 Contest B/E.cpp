#include <cstdio>
#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

inline double min(double a,double b) {
	if (a<b) return a; else return b;
}

int main() {
	int t,q,i;
	double a,b,c,x,y,z,va,vb,vc,vx,vy,vz,ra,rx;
	scanf("%d",&q);
	for (t=1;t<=q;t++) {
		double xa,xb,xc,t,x1,x2,delta,u;
		scanf("%lf%lf%lf%lf%lf%lf%lf",&x,&y,&z,&rx,&vx,&vy,&vz);
		scanf("%lf%lf%lf%lf%lf%lf%lf",&a,&b,&c,&ra,&va,&vb,&vc);
		xa=(va-vx)*(va-vx)+(vb-vy)*(vb-vy)+(vc-vz)*(vc-vz);
		xb=(va-vx)*(a-x)+(vb-vy)*(b-y)+(vc-vz)*(c-z);
		xb*=2;
		xc=(a-x)*(a-x)+(b-y)*(b-y)+(c-z)*(c-z)-(ra+rx)*(ra+rx);
		delta=xb*xb-4*xa*xc;
		if (delta<0) {
			printf("No collision\n");
			continue;
		} else {
			double u=sqrt(delta);
			x1=(-xb+u)/(2*xa);
			x2=(-xb-u)/(2*xa);
			if (x1>0&&x2>0) {
				printf("%.3lf\n",min(x1,x2));
			} else 
		//	if (x1<0&&x2<0) 
			printf("No collision\n");
	//		else printf("0.000\n");
		}
	}
	return 0;
}
