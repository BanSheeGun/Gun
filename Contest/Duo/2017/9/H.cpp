#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const ll mod2 = 5e8 + 4;
const int N = 316227;
int prime[N + 10];
bool p[N + 10];
int i, j, top, T, tot, m;
ll l, r, k, an;

bool pan(ll n) {
    for (i = 1; i <= top; ++i) {
        if (prime[i] >= n)
            return 0;
        if (n % prime[i] == 0)
            return 1;
    }
    return 0;
}

ll f(ll n, int j) {
    ll ans = 0;
    if (n == 0)
        return 0;
    if (n <= prime[j])
        return 1;
    if (j == 0) {
        n %= mod;
        ans = (n + 1) * n % mod * mod2 % mod;
        return ans; 
    }
    ans = f(n, j-1) - prime[j] * f(n / prime[j], j-1) % mod;
    ans = ans % mod;
    if (ans < 0)
        ans += mod;
    return ans;
}

int main() {
    memset(p, 0, sizeof(p));
    top = 0;
    for (i = 2; i <= N; ++i) {
        if (!p[i])
            prime[++top] = i;
        for (j = 1; j <= top; ++j) {
            if (i * prime[j] > N)
                break;
            p[i * prime[j]] = 1;
            if (i % prime[j] == 0)                
                break;               
        }
    } 

    scanf("%d", &T);
    int cnt = 0;
    while (T--) {
        scanf("%lld%lld%lld", &l, &r, &k);
        if (pan(k)) {
            printf("Case #%d: 0\n", ++cnt);
            continue;
        }
        if (k > N) {
            if (l <= k && k <= r)
                printf("Case #%d: %lld\n", ++cnt, k % mod);
            else 
                printf("Case #%d: 0\n", ++cnt);
            continue;
        }
        for (i = 1; i <= top; ++i)
            if (k == prime[i])
                m = i;
        an = f(r / k, m - 1) - f((l-1) / k, m - 1);
        an = an % mod;
        an = an * k % mod;
        if (an < 0) an += mod;
        printf("Case #%d: %lld\n", ++cnt, an);
    }
    return 0;
}