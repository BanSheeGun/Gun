#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

typedef long long ll;

struct Point
{
	double x,y;
};

Point inter(Point u1,Point u2,Point v1,Point v2){
	Point ret=u1;
	double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))
	        /((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
	ret.x+=(u2.x-u1.x)*t;
	ret.y+=(u2.y-u1.y)*t;
	return ret;
}

double det(double a,double b,double c,double d){
	return a*d-b*c;
}

int n,i,j;
double ans,s;
Point a[40],b[40],c[40],d[40];
Point aa,bb,cc,dd;

int main(){
	scanf("%d",&n);
	while (n!=0){
		ans=0;
		a[0].x=0;a[n+1].x=1;
		a[0].y=0;a[n+1].y=0;
		for (i=1;i<=n;++i) {
			scanf("%lf",&a[i].x);
			a[i].y=0;
		}
		b[0].x=0;b[n+1].x=1;
		b[0].y=1;b[n+1].y=1;
		for (i=1;i<=n;++i) {
			scanf("%lf",&b[i].x);
			b[i].y=1;
		}
		c[0].x=0;c[n+1].x=0;
		c[0].y=0;c[n+1].y=1;
		for (i=1;i<=n;++i) {
			scanf("%lf",&c[i].y);
			c[i].x=0;
		}
		d[0].x=1;d[n+1].x=1;
		d[0].y=0;d[n+1].y=1;
		for (i=1;i<=n;++i) {
			scanf("%lf",&d[i].y);
			d[i].x=1;
		}

		for (i=0;i<=n;++i){
			for (j=0;j<=n;++j){
				aa=inter(a[i],b[i],c[j],d[j]);
				bb=inter(a[i],b[i],c[j+1],d[j+1]);
				cc=inter(a[i+1],b[i+1],c[j+1],d[j+1]);
				dd=inter(a[i+1],b[i+1],c[j],d[j]);
				s=fabs(det(cc.x-aa.x,cc.y-aa.y,dd.x-aa.x,dd.y-aa.y));
				s+=fabs(det(cc.x-aa.x,cc.y-aa.y,bb.x-aa.x,bb.y-aa.y));
				ans=max(ans,s);
			}
		}
		ans=ans/2;
		printf("%.6f\n",ans);
		scanf("%d",&n);
	}
	return 0;
}
