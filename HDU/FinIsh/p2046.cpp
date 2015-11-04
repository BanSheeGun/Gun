#include<iostream>
using namespace std;
int main(){
	long long f[51];
	f[1]=1;
	f[2]=2;
	int i;
	for (i=3;i<=50;++i){
		f[i]=f[i-1]+f[i-2];
	}
	int n;
	while (scanf("%d",&n) != EOF){
		printf("%lld\n",f[n]);
	}
	return 0;
}
