#include<iostream>
#include<cstdio>
#include<cstring>
#include<memory.h>
#include<cmath>
using namespace std;
long long n;
int f(int k){
	int z;
	if (k==1){
		return n%10;
	}
	z=f(k/2);
	z=z*z%10;
	if (k%2==1) {
		z=z*n%10;
	} 
	return z;
}
int main(){
	long long ans;
	int tt,t,i;
	scanf("%d",&t);
	for (tt=0;tt<t;++tt){
		scanf("%I64d",&n);
		ans=f(n)%10;
		printf("%I64d\n",ans);
	}
	return 0;
}
