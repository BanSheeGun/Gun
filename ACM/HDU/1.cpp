#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<vector>
#include<algorithm>
#define ll unsigned long long 
using namespace std;
ll a[10005],b[10005],mt[10005],h[10005],mi,p,MM;
ll qpow(ll a,ll b,ll p)
{
    ll ans;
    for(ans=1;b;b>>=1,a=a*a%p)
        if(b&1)ans=ans*a%p;
    return ans;
}
ll getc(ll n,ll m,ll p)
{
    if(n<m)return 0;
    if(m>n-m)m=n-m;
    ll s1=1,s2=1;
    for(int i=0;i<m;i++)
    {
        s1=s1*(n-i)%p;
        s2=s2*(i+1)%p;
    }
    return s1*qpow(s2,p-2,p)%p;
}
ll lucas(ll n,ll m,ll p)
{
    if(m==0)return 1;
    return getc(n%p,m%p,p)*lucas(n/p,m/p,p)%p;
}
ll f(ll n){
    if (n==0) return 1;
    if (n==1) return mi;
    ll ttt=f(n/2);
    ttt=ttt*ttt%p;
    if (n%2==1) ttt=ttt*mi%p;
    return ttt; 
}
ll chen(ll a,ll b){
	ll k=b;
    a=a%MM;
    ll ans=0;
    ll z=a;
    while (k!=0) {
      if (k%2==1) ans=(ans+z)%MM;
      z=z*2%MM;
      k=k/2;
    }
    return ans;
}
int main()
{
    ll n,m,sum,ans;
    int t,k,i,j;
    scanf("%lld",&t);
    while(t--)
    {
        sum=1;
        MM=1;
        scanf("%lld%lld%lld",&n,&m,&k);
        for(i=0;i<k;i++)
        {
            scanf("%lld",&a[i]);
            b[i]=lucas(n,m,a[i]);
            MM=a[i]*MM;
        }
        for (i=0;i<k;++i)
        {
            mi=MM/a[i];
            mt[i]=mi;
            p=a[i];
            h[i]=f(a[i]-2);
        }
        ans=0;
        for (i=0;i<k;++i)
        {
            ans=ans+chen((b[i]*mt[i])%MM,h[i]);
            ans=ans%MM;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
