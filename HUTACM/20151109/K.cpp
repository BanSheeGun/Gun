#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;

int a[1000100];
int ans,n,i,t,tt,b;

int main(){
	scanf("%d",&t);
	for (tt=1;tt<=t;++tt){
		ans=0;
		scanf("%d",&n);
		for (i=1;i<=n;++i){
			scanf("%d",&a[i]);
		}
		b=a[n];
		for (i=n-1;i>0;--i){
			if (a[i]>b) ++ans;
			b=min(b,a[i]);
		}
		printf("Case #%d: %d\n",tt,ans);
	}
	return 0;
}
