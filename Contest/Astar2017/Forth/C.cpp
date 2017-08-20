#include<cstdio>
typedef long long ll;
ll a[10011]={0};  
ll b[10011]={0};  
const ll mod = 1e9 + 7;  
int i, n, T;  

int main() {  
    scanf("%d", &T);
    while (T--) {
        scanf("%d",&n);  
        b[1]=1;  
        for (i = 2; i <= n; i++)  
            b[i]= b[i-1] * 2 % mod;
        a[1] = 1;
        a[2] = 6;

        for (i=3;i<=n;i++)  
            a[i]=(2 * a[i-1] + b[i] + 4 * a[i-2]) % mod;

        ll ans=4*a[n];  
        for (i=2;i<n;i++) {  
            ans+=((8*b[n-i]*a[i-1])%mod+(8*a[n-i]*b[i-1])%mod)%mod;  
            ans %= mod;  
        }   
        if(n==1)  
            ans = 2;   
        printf("%lld\n",ans);  
    }
    return 0;  
}  