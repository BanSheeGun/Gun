#include<iostream>
using namespace std;
int main(){
	int n,i,a;
	long long f[31];
	f[0]=1;
	f[1]=1;
	for (i=2;i<=30;++i){
		f[i]=f[i-2]*2+f[i-1];
	} 
	scanf("%d",&n);
	for (i=1;i<=n;++i){
		scanf("%d",&a);
		printf("%d\n",f[a]);
	}
	return 0;
}
