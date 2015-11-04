#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;


long long ans[1001];

int f(long long x,long long a){
	long long ans=1;
	int i;
	for (i=1;i<=a;++i)
		ans=ans*x;
	return ans;
}

bool check(long long n,long long i){
	if (!((n>0)&&(n<1000000000))) return 0;
	long long sum=0;
	long long m=n;
	while (m!=0){
		sum+=m%10;
		m/=10;
	}
	return (sum==i);
}

bool cmp(long long a,long long b){
	return a<b;
}

int main(){
	long long top,a,b,c,i;
	long long n;
	bool t;
	scanf("%lld%lld%lld",&a,&b,&c);
	top=0;
	for (i=1;i<=1000;++i) {
		n=b*f(i,a)+c;
		t=check(n,i);
		if (t) {
            ++top;
			ans[top-1]=n;
		}
	}
	sort(ans,ans+top,cmp);
	printf("%lld\n",top);
	if (top!=0) {
	for (i=0;i<top-1;++i)
		printf("%lld ",ans[i]);
	printf("%lld\n",ans[top-1]);}
	return 0;
}
