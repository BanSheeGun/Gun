#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

bool cmp(long long a,long long b){
	return a<b;
}

long long a[300000];
int main(){
	long long n,i;
	scanf("%lld",&n);
	for (i=0;i<n;++i)  scanf("%lld",&a[i]);
	sort(a,a+n,cmp);
    long long ans,q=1,w=1;
    if (a[0]==a[n-1]) {
    	ans=n*(n-1)/2;
    } else {
    	while (a[q]==a[q-1]) ++q;
    	while (a[n-w-1]==a[n-w]) ++w;
    	ans=w*q;
    }
    printf("%lld %I64d\n",a[n-1]-a[0],ans);
	return 0;
}
