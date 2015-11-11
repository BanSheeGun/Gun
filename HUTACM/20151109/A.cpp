#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;

struct s
{
	double a,b;
};

bool cmp(s a,s b){
	return a.a<b.a;
}

int tt,t,i,n;
s a[10100];
double ttt,ans;

int main(){
	scanf("%d",&t);
	for (tt=1;tt<=t;++tt){
		scanf("%d",&n);
		for (i=0;i<n;++i)
			scanf("%lf%lf",&a[i].a,&a[i].b);
		sort(a,a+n,cmp);
		ans=0;
		for (i=1;i<n;++i){
			ttt=(a[i].b-a[i-1].b)/(a[i].a-a[i-1].a);
			ttt=(ttt>0)? ttt:-ttt;
			ans=max(ans,ttt);
		}
		printf("Case #%d: %.2f\n",tt,ans);
	}
	return 0;
}