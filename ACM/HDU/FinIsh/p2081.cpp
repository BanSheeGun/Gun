#include<iostream>
using namespace std;
int main(){
	int n,i;
	long long a;
	scanf("%d",&n);
	for (i=1;i<=n;++i){
		scanf("%lld",&a);
		printf("%lld\n",600000+a % 100000);
	}
}
