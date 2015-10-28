#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long LL;  
  
LL n,m,p,MM,mi,ans;
LL pp[100001];
LL a[100001];   
LL t[100001];
LL mt[100001];
int i;
bool flag;

LL PowMod(LL a,LL b,LL MOD){  
    LL ret=1;  
    while(b){  
        if(b&1) ret=(ret*a)%MOD;  
        a=(a*a)%MOD;  
        b>>=1;  
    }  
    return ret;  
}  
LL fac[2000005];  
LL Get_Fact(LL p){  
    fac[0]=1;  
    for(int i=1;i<=p;i++)  
        fac[i]=(fac[i-1]*i)%p;  
}  
LL Lucas(LL n,LL m,LL p){  
    LL ret=1;  
    while(n&&m){  
        LL a=n%p,b=m%p;  
        if(a<b) return 0;  
        ret=(ret*fac[a]*PowMod(fac[b]*fac[a-b]%p,p-2,p))%p;  
        n/=p;  
        m/=p;  
    }  
    return ret;  
}  

LL f(LL n){
	LL ttt;
	if (n==0) return 1;
	if (n==1) return mi;
	ttt=f(n/2);
	ttt=ttt*ttt%p;
	if (n%2==1) ttt=ttt*mi%p;
	return ttt; 
}
LL chen(LL a,LL b){
	LL k=b;
    a=a%MM;
    LL ans=0;
    LL z=a;
    while (k!=0) {
      if (k%2==1) ans=(ans+z)%MM;
      z=z*2%MM;
      k=k/2;
    }
    return ans;
}
int main(){
	int ttt,tt,k;
	scanf("%d",&ttt);
	for (tt=1;tt<=ttt;++tt){
		scanf("%lld%lld%d",&n,&m,&k);
		for (i=1;i<=k;++i){
			scanf("%lld",&pp[i]);
		}
		MM=1;
		for (i=1;i<=k;++i){
			MM=MM*pp[i];
			p=pp[i];
			a[i]=Lucas(n,m,p);
		}
		for (i=1;i<=k;++i){
			mi=MM/pp[i];
			mt[i]=mi;
			p=pp[i];
			t[i]=f(pp[i]-2);
		}
		ans=0;
        for (i=1;i<=k;++i){
            ans=ans+chen(a[i]*mt[i],t[i]);
            ans=ans%MM;
        }
		printf("%lld\n",ans);
	}
	return 0;
}
