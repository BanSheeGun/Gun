#include<iostream>
using namespace std;
int main(){
	int n,i,a;
	long long f[31];
	f[1]=1;f[2]=3;
	for (i=3;i<=30;++i){
		f[i]=f[i-1]+f[i-2]*2;
	}
	scanf("%d",&n);
	for (i=1;i<=n;++i){
		scanf("%d",&a);
		printf("%d\n",f[a]);
	}
	return 0;
}
