#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 998244353;


ll exgcd(ll a,ll b,ll &x,ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return 0;
    }
    exgcd(b, a % b, x, y);
    ll x1 = y;
    ll y1 = x - (a / b) * y;
    x = x1;
    y = y1;
    return 0;
}

inline ll Inv(int n) {
    if (n == 0)
        return 1;
    ll x, y;
    exgcd(n, mod, x, y);
    x = x % mod;
    x = (x + mod) % mod;
    return x;
}


ll inv[10010];
ll n, m, i, ans;

int main() {
    inv[1] = 1;
    inv[0] = 1;
    for (i = 2; i < 10010; ++i) {
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    }
    for (i = 1; i <= 10000; ++i)
        inv[i] = inv[i] * inv[i-1] % mod;

    while (~scanf("%lld%lld", &n, &m)) {
        if ((n - m) % 2 != 0) {
            printf("0\n");
            continue;
        }
        ans = 1;
        for (i = n - m + 2; i <= n + m - 2; i += 2)
            ans = ans * i % mod;
        if (m < 2)
            ans = Inv(n);
        ans = ans * inv[m] % mod * n % mod;
        if ((n - m) % 4 == 2)
            ans = -ans;
        ans = (ans + mod) % mod;
        printf("%lld\n", ans);
    }
    return 0;
}