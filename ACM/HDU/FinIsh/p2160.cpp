#include<iostream>
using namespace std;
int main(){
	long long f[21];
	int i,n,k;
	f[0]=0;
	f[1]=1;
	f[2]=2;
	for (i=3;i<=20;++i){
		f[i]=f[i-1]+f[i-2];
	}
	scanf("%d",&n);
	for (i=1;i<=n;++i){
		scanf("%d",&k);
		printf("%lld\n",f[k]);
	}
	return 0;
}
