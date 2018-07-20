//线段树求矩形面积 
//扫描线法 
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct Tree {
	int l,r,lc,rc;
	double ly,ry,len; 
	int cover;
};
struct Line {
	double x,y1,y2;
	int flag;
};
Tree tree[605];
Line line[205];
double y[205];
int co;

bool cmp(Line a,Line b) {
	return a.x<b.x;
}

void build(int now,int l,int r) {
	tree[now].l=l;tree[now].r=r;
	tree[now].ly=y[l];tree[now].ry=y[r];
	tree[now].len=tree[now].cover=0;
	if (l+1!=r) {
		co++;
		tree[now].lc=co;
		build(co,l,(l+r)/2);
		co++;
		tree[now].rc=co;
		build(co,(l+r)/2,r);
	}
}

void cal(int now) {
	if (tree[now].cover>0) {
		tree[now].len=tree[now].ry-tree[now].ly;
    } else {
    	if (tree[now].l+1==tree[now].r)
        	tree[now].len=0;
        else tree[now].len=tree[tree[now].lc].len+tree[tree[now].rc].len;
    }
}

void update(int now,Line l) {
//	cout << now << ' ' << tree[now].cover << ' ' << tree[now].ly << ' ' << tree[now].ry << endl;
//	cout << l.x << ' ' << l.y1 << ' ' << l.y2 << endl;
	if (tree[now].ly==l.y1&&tree[now].ry==l.y2) {
		tree[now].cover+=l.flag;
		cal(now);
		return;
	} else if (tree[tree[now].lc].ry>=l.y2) update(tree[now].lc,l);
	else if (tree[tree[now].rc].ly<=l.y1) update(tree[now].rc,l); else{
		Line l1=l;
		l1.y2=tree[tree[now].lc].ry;
		update(tree[now].lc,l1);
		l1=l;
		l1.y1=tree[tree[now].rc].ly;
		update(tree[now].rc,l1);
	}
	cal(now);
}

int main() {
	int n,i;
	double x1,x2,y1,y2;
	scanf("%d",&n);
	int time=0;
	while (n) {
		time++;
		int num=0;
		for (i=1;i<=n;i++) {
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			num++;
			line[num].x=x1;
			line[num].y1=y1;
			line[num].y2=y2;
			line[num].flag=1;
			num++;
			line[num].x=x2;
			line[num].y1=y1;
			line[num].y2=y2;
			line[num].flag=-1;
			y[2*i-1]=y1;y[2*i]=y2;
		}
	    sort(line+1,line+2*n+1,cmp);
	    sort(y+1,y+2*n+1);
		co=1;
		build(1,1,2*n);
		update(1,line[1]);
		double ans=0;
		for (i=2;i<=2*n;i++) {
			ans+=tree[1].len*(line[i].x-line[i-1].x);
			update(1,line[i]);
		}
		printf("Test case #%d\nTotal explored area: %.2f\n\n",time,ans);
		scanf("%d",&n);
	}
	return 0;
}
