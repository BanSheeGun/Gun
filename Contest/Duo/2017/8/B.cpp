#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int N = 1e6;
int prime[N + 10];
int mi[N + 10];
int p[N + 10];
int e[N + 10];
int div_num[N + 10];
int i, j, top;
ll f[N + 10];

int main() {
    memset(p, 0, sizeof(p));
    mi[1] = 1;
    div_num[1] = 1;
    top = 0;
    for (i = 2; i <= N; ++i) {
        if (!p[i]) {
            prime[++top] = i;
            mi[i] = -1;
            e[i] = 1;
            div_num[i] = 2;
        }
        for (j = 1; j <= top; ++j) {
            if (i * prime[j] > N)
                break;
            p[i * prime[j]] = 1;
            if (i % prime[j] == 0) {                        
                div_num[i*prime[j]]=div_num[i]/(e[i]+1)*(e[i]+2);  
                e[i*prime[j]]=e[i]+1;  
                break;
            }
            mi[i * prime[j]] = -mi[i];                        
            div_num[i*prime[j]]=div_num[i]*div_num[prime[j]];  
            e[i*prime[j]] = 1; 
        }
    }

    f[1] = 1;
    for (i = 2; i <= N; ++i)
        f[i] = (f[i-1] + 1 + div_num[i-1]) % mod;
    for (i = 2; i <= N; ++i) {
        f[i] = (f[i] + f[i-1]) % mod;
        mi[i] = (mi[i] + mi[i-1]) % mod;
    }

    int n;
    while (~scanf("%d", &n)) {
        ll ans = 0;
        for (int l = 1, r; l <= n; l = r+1) {
            r = n / (n / l);
            ans += (mi[r] - mi[l-1]) * f[n / l] % mod;
            ans = (ans % mod + mod) % mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}