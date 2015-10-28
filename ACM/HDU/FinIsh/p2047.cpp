#include<iostream>

using namespace std;

int main(){
	int n,i;
	long long a[41];
	long long b[41];
	a[1]=2;
	b[1]=1;
	for (i=2;i<=40;++i){
		a[i]=a[i-1]*2+b[i-1]*2;
		b[i]=a[i-1];
	}
	
	while (scanf("%d",&n)!= EOF){
		printf("%lld\n",a[n]+b[n]);
	}
	return 0;
}
