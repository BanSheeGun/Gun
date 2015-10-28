#include<iostream>

using namespace std;

int f(long long n){
	if (n==0) { return 1;}
	if (n==1){ return 2;}
	int m;
    m=f(n/2);
    m=m*m%100;
    if (n%2==0){return m;}
    return m*2%100;
}

int main(){
	int t,tt,i;
	long long n;
	scanf("%d",&t);
	while (t!=0){
		for (tt=1;tt<=t;++tt){
			scanf("%lld",&n);
			int ans;
			ans=f(n-1);
			ans=ans*(ans+1)%100;
			printf("Case %d: %d\n",tt,ans);
		}
		scanf("%d",&t);
		{printf("\n");}
	}
	return 0;
}
