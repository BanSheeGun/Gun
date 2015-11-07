#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int a[100010];
int n,i,ans,m,t,tt,l,r;

int main(){
	scanf("%d",&t);
	for (tt=1;tt<=t;++tt){
		a[0]=0;
		m=0;
		scanf("%d",&n);
		scanf("%d",&a[1]);
		ans=a[1];
		l=0;r=1;
		m=a[m]>a[1]? 1:m;
		for (i=2;i<=n;++i){
			scanf("%d",&a[i]);
			a[i]+=a[i-1];
			if (ans<a[i]-a[m]){
				ans=a[i]-a[m];
				l=m;
				r=i;
			}
		    m=a[m]>a[i]? i:m;
		}
		printf("Case %d:\n",tt);
		printf("%d %d %d\n",ans,l+1,r);
		if (t!=tt) putchar('\n');
	}
	return 0;
}
