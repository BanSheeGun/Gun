#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef long long LL;
const ll mod = 1e9 + 7;
ll Inv[1000010];
ll f[1000010];
ll i, t, k;
LL PowMod(LL a, LL b, LL base) {
    LL ans = 0;
    a %= base;
    b %= base;
    LL now = b;
    while (a != 0) {
        ans += now * (a % 2);
        ans %= base;
        now *= 2;
        now %= base;
        a = a / 2;
    }
    return ans;
}
ll find(ll n, ll p, ll m) {
    if (n < 0) return 0;
    ll l = n - m - (m - 1) * (p-1)+1;
    if (m > l) return 0;
    if (m == 0) return 1;
    ll tmp = f[l];
    tmp = PowMod(tmp, Inv[m], mod);
    tmp = PowMod(tmp, Inv[l - m], mod);
    return tmp;
}

ll ans, n, m, a2;

int main() {
    Inv[0] = 1;
    Inv[1] = 1;
    for (i = 2; i < 1000010; ++i) {
        t = mod / i;
        k = mod % i;
        Inv[i] = (mod - t) * Inv[k] % mod;
    }
    for (i = 2; i < 1000010; ++i)
        Inv[i] = PowMod(Inv[i], Inv[i-1], mod);
    f[0] = 1;
    for (i = 1; i < 1000010; ++i)
        f[i] = (f[i-1] * i) % mod;
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld%lld", &n, &m, &k);
        ans = find(n-k, k, m);
        a2 = find(n-2*k-1, k, m-1);
        a2 = PowMod(a2, k , mod);
        ans = (ans + a2) % mod;
        if (ans < 0) ans += mod;
        if (m==1) ans = n;
        printf("%lld\n", ans);
    }
    return 0;
}