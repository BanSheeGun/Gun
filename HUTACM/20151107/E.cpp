#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int t,tt;
double a,b,c,r,ans;

int main(){
	scanf("%d",&t);
	for (tt=1;tt<=t;++tt){
		scanf("%lf%lf%lf%lf",&a,&b,&c,&r);
		r=1/r+1;
		r=sqrt(1/r);
		ans=a*r;
		printf("Case %d: %lf\n",tt,ans);
	}
	return 0;
}
