#include<iostream>
#include<cstdio>
#include<cstring>
#include<memory.h>
#include<cmath>
using namespace std;
int n;
long long f(long long n,long long k){
	long long q;
	if (k==1) return n;
    q=f(n,k/2);
    q=q*q;
    if (k%2==1) q=(long long)q*n;
    return q;
}
long long find(long long l,long long r,int i){
	long long mid=(l+r+1)/2;
	printf("%I64d %I64d %I64d \n",l,r,mid);
	if (l==r) {
		return l;
	}
	if (f(mid,i)>=n) {
		return find(l,mid-1,i);
	} else {
		return find(mid,r,i);
	}

}
int main(){
	long long n;
	long long i,ans,r,z; 
	double k;
	int t,tt;
	scanf("%d",&t);
	for (tt=1;tt<=t;++tt){
		scanf("%I64d%I64d",&n,&r);
		ans=0;
		z=(long long)sqrt(n);
		for (i=2;i<=r;++i){
			z=find(1,z,i);
			ans+=z-1;
		}
		printf("%I64d\n",n+ans+1);
	}
	return 0;
}
