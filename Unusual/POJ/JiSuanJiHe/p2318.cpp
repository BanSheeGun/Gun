#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;
struct line
{
	ll u,l;
};

bool cmp(line a,line b){
	return a.u<b.u;
}

int sign(ll a){
	if (a>0) return 1;
	if (a<0) return -1;
	return 0;
}

ll x,y,n,m,x1,x2,y2,i,z;
ll y1;
line l[5010];
int ans[5010];

ll cm(ll a,ll b,ll c,ll d){
	return a*d-b*c;
}

int check(int k){
	ll v1x,v1y,v2x,v2y;
	v1x=l[k].u-l[k].l;
	v1y=y1-y2;
	v2x=x-l[k].l;
	v2y=y-y2;
	ll z1=cm(v1x,v1y,v2x,v2y);
	v1x=l[k+1].u-l[k+1].l;
	v1y=y1-y2;
	v2x=x-l[k+1].l;
	v2y=y-y2;
	ll z2=cm(v1x,v1y,v2x,v2y);
	int a=sign(z1),b=sign(z2);
	if (a>0&&b>0) return 1;
	if (a<0&&b<0) return -1;
	return 0;
}

ll find(int left,int right){
	int mid=(left+right)>>1;
	int t=check(mid);
	if (t==0) return mid;
	if (t<0) return find(mid+1,right);
	return find(left,mid-1);
}

int main(){
    scanf("%lld",&n);

	while (n!=0) {
		memset(ans,0,sizeof(ans));
		scanf("%lld%lld%lld%lld%lld",&m,&x1,&y1,&x2,&y2);

		l[0].u=x1;l[0].l=x1;
		l[n+1].u=x2;l[n+1].l=x2;
		for (i=1;i<=n;++i){
			scanf("%lld%lld",&l[i].u,&l[i].l);
		}
		sort(l,l+n+2,cmp);
		for (i=0;i<m;++i){
			scanf("%lld%lld",&x,&y);
			z=find(0,n);
			++ans[z];
		}

		for (i=0;i<=n;++i)
			printf("%lld: %d\n",i,ans[i]);
		scanf("%lld",&n);
		if (n!=0) putchar('\n');
	}

	return 0;
}
