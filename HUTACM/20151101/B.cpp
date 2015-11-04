#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

bool cmp(long long a,long long b){
	return a>b;
}

long long a[26];
long long b[27];
long long ans;
int main(){
	long long n,m,i,k,top;
	char c;
	scanf("%lld%lld",&n,&m);
	getchar();
	memset(a,0,sizeof(a));
	for (i=0;i<n;++i){
		c=getchar();
		k=(int)c-65;
		++(a[k]);
	}

	top=0;
	for (i=0;i<26;++i)
		if (a[i]!=0) {
			++top;
			b[top-1]=a[i];
		}
	sort(b,b+top,cmp);

	ans=0;i=-1;
	while (m>0){
		++i;
		if (b[i]<=m) {
			ans+=b[i]*b[i];
			m-=b[i];
		} else {
			ans+=m*m;
			m=0;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
