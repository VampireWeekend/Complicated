#include <cstdio>
#include <iostream>
#include <math.h>
#include <iomanip>
#include <cmath>
typedef long double ld;
typedef double db;
using namespace std;
const ld pi=3.14159265358979323846L;

ld sqr(ld a) {
	return a*a;
}

ld distance(ld x1,ld y1,ld x2,ld y2) {
	return sqrt(sqr(x1-x2)+sqr(y1-y2));
}

int main() {
	int n,i;
	ld x1,x2,y1,y2,x3,y3,r1,r2,ans;
	cin >> n;
	cout << setiosflags(ios::fixed) << setprecision(6);
	for (i=1;i<=n;i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		ld d=distance(x1,y1,x2,y2);
		if (abs(r1-r2)<d&&d<r1+r2) {
			if (x1!=x2&&y1!=y2) {
			ld a=(sqr(r2)-sqr(r1)+sqr(y1)-sqr(y2))/2.0L/(x1-x2)+(x1+x2)/2.0L;
			ld b=(y2-y1)/(x1-x2);
			ld bb=b*(a-x1)-y1;
			bb*=2.0L;
			ld aa=sqr(b)+1,cc=sqr(y1)+sqr(a-x1)-sqr(r1);
			ld delta=sqr(bb)-4.0L*aa*cc;
			y3=(sqrt(delta)-bb)/(2.0L*aa);
			x3=a+b*y3;
		    } else if (x1==x2&&y1==y2) {
		    	ans=sqr(min(r1,r2))*pi; 
		    	cout << ans << endl;
		    	continue;
		    }
		     else {
		    	if (x1==x2) {
		    			y3=sqr(r1)-sqr(r2);
		    			y3/=(y2-y1);
		    			y3+=y2+y1;
		    			y3/=2.0L;
		    			x3=sqrt(sqr(r1)-sqr(y3-y1))+x1;
		    	} else {
		    		    x3=sqr(r1)-sqr(r2);
		    			x3/=(x2-x1);
		    			x3+=x2+x1;
		    			x3/=2.0L;
		    			y3=sqrt(sqr(r1)-sqr(x3-x1))+y1;
		    	}
		    }
			ld e=distance(x1,y1,x3,y3);
			ld f=distance(x2,y2,x3,y3);
			ld angle1=acos((sqr(d)+sqr(e)-sqr(f))/(2.0L*d*e));
			ld angle2=acos((sqr(d)+sqr(f)-sqr(e))/(2.0L*d*f));
			ld s1=sqr(r1)*angle1;
			ld s2=sqr(r2)*angle2;
			ld s3=d*e*sin(angle1);
			ans=s1+s2-s3;
		    cout << ans << endl;
		} else if (abs(r1-r2)>=d) cout << sqr(min(r1,r2))*pi << endl;
		else cout << "0.000000" << endl;
	}
	return 0;
} 
