#include<iostream>
#include<cstdio>
#include<cstring>
#include<memory.h>
#include<cmath>
using namespace std;
int main(){
	int tt,t,i,ans,n;
	scanf("%d",&t);
	for (tt=0;tt<t;++tt){
		scanf("%d",&n);
		double z=log(n)/log(10);
		z=(double)n*z;
		z-=(long long)(z);
		z=z*log(10);
		z=exp(z);
		printf("%d\n",(int)z);
	}
	return 0;
}
