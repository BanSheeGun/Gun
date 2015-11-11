#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
double eps=1e-8;
double PI=acos(-1.0);
int t,tt;
double rr,r,x1,x2,y3,y2,ans,l;

double area(double r1,double r2,double d){
	if (r1+r2<d+eps) return 0;
	if (d<fabs(r1-r2)+eps){
		double r=min(r1,r2);
		return PI*r*r;
	}
	double x=(d*d+r1*r1-r2*r2)/(2*d);
	double t1=acos(x/r1);
	double t2=acos((d-x)/r2);
	return r1*r1*t1+r2*r2*t2-d*r1*sin(t1);
}
int main(){
	scanf("%d",&t);
	for (tt=1;tt<=t;++tt){
		scanf("%lf%lf",&r,&rr);
		scanf("%lf%lf",&x1,&y3);
		scanf("%lf%lf",&x2,&y2);
		l=sqrt((x1-x2)*(x1-x2)+(y3-y2)*(y3-y2));
		ans=area(rr,rr,l)+area(r,r,l)-2*area(rr,r,l);
		printf("Case #%d: %f\n",tt,ans);
	}
	return 0;
}
