#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 300010;
int vis[N + 10];
int mu[N + 10];
int prime[N + 10];
int cnt;
const ll mod = 1e9 + 7;

void Init() {  
    memset(vis,0,sizeof(vis));  
    mu[1] = 1;  
    cnt = 0;  
    for(int i=2; i<N; i++) {  
        if(!vis[i]) {  
            prime[cnt++] = i;  
            mu[i] = -1;  
        }  
        for(int j=0; j<cnt&&i*prime[j]<N; j++) {  
            vis[i*prime[j]] = 1;  
            if(i%prime[j]) mu[i*prime[j]] = -mu[i];  
            else  
            {  
                mu[i*prime[j]] = 0;  
                break;  
            }  
        }  
    } 
    return;
}

inline ll f(ll a, ll n) {
    ll ans = 1;
    ll tmp = a;
    while (n != 0) {
        if (n & 1)
            ans = ans * tmp % mod;
        tmp = tmp * tmp % mod;
        n = n >> 1;
    }
    return ans;
}

int T;
int a[N+10];
ll res, ans;
int i, j, mai, n, k;

int main() {
    scanf("%d", &T);
    Init();
    for (int TT = 1; TT <= T; ++TT) {
        ans = 0;
        mai = 100000;
        scanf("%d", &n);
        memset(a, 0, sizeof(a));
        for (i = 1; i <= n; ++i) {
            scanf("%d", &k);
            a[k]++;
            mai = min(mai, k);
        }
        for (i = 1; i <= N; ++i)
            a[i] = a[i] + a[i-1];
        ans = 0;
        for (i = 2; i <= mai; ++i)
            if (mu[i] != 0) {
                res = 1;
                for (j = 1; i * j - 1 <= 100000; ++j) {
                    res *= f(j, a[i * j + i - 1] - a[i * j - 1]);
                    res %= mod;
                }
                ans = ans - mu[i] * res;
                ans = (ans % mod + mod) % mod;
            }
        printf("Case #%d: %lld\n", TT, ans);
    }
    return 0;
}