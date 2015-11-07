#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int a[1500000];
int ll[1500000];
int rr[1500000];
int lch[1500000];
int rch[1500000];
int n,m,t,tt,i,te,top,l,r,ans;

int creat(int root,int task){
	int mid;
	if (ll[root]==rr[root]) {
		a[root]=1;
		return 0;
	}
	mid=(ll[root]+rr[root])>>1;
	if (task<=mid) {
		if (lch[root]==0) {
			++top;
			lch[root]=top;
			ll[top]=ll[root];
			rr[top]=mid;
		}
		creat(lch[root],task);
	} else {
		if (rch[root]==0) {
			++top;
			rch[root]=top;
			ll[top]=mid+1;
			rr[top]=rr[root];
		}
		creat(rch[root],task);
	}
	a[root]=a[lch[root]]+a[rch[root]];
	return 0;
}

int find(int root,int l,int r){
	int mid,ans=0;
	mid=(ll[root]+rr[root])>>1;
	if (l<=ll[root]&&rr[root]<=r) return a[root];
	if (l<=mid){
		if (lch[root]!=0) ans+=find(lch[root],l,r);
	}
	if (r>mid){
		if (rch[root]!=0) ans+=find(rch[root],l,r);
	}
	return ans;
}

int main(){
	scanf("%d",&t);
	for (tt=1;tt<=t;++tt){
		memset(lch,0,sizeof(lch));
		memset(rch,0,sizeof(rch));
		memset(ll,0,sizeof(ll));
		memset(rr,0,sizeof(rr));
		memset(a,0,sizeof(a));
		ll[1]=0;rr[1]=100000000;
		top=1;
		scanf("%d%d",&n,&m);
		for (i=0;i<n;++i){
			scanf("%d",&te);
			creat(1,te);
		}
		printf("Case %d:\n",tt);

		for (i=0;i<m;++i){
			scanf("%d%d",&l,&r);
			ans=find(1,l,r);
			printf("%d\n",ans);
		}
	}
	return 0;
}
