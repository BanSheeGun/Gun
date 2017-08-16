#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const ll mod2 = 5e8 + 4;
const ll N = 1000000;
int prime[N + 10];
ll phi[N + 10];
bool p[N + 10];
ll i, j, top;
ll ans[2 * N + 10];
ll tot;
ll l, r, a, n, tmp;
map<ll, int> hs;

ll find(ll n) {
    if (n <= N)
        return phi[n];
    if (hs[n] != 0)
        return ans[hs[n]];
    ll an = (n % mod) * ((n + 1) % mod) % mod * mod2 % mod;
    for (ll l = 2, r; l <= n; l = r + 1) {
        r = n / (n / l);
        an -= find(n / l) * (r - l + 1) % mod;
        an = (an % mod + mod) % mod;
    }
    hs[n] = ++tot;
    ans[tot] = an;
    return an;
}

int main() {
    memset(p, 0, sizeof(p));
    tot = 0;
    hs.clear();
    phi[1] = 1;
    top = 0;
    for (i = 2; i <= N; ++i) {
        if (!p[i]) {
            prime[++top] = i;
            phi[i] = i-1;
        }
        for (j = 1; j <= top; ++j) {
            if (i * prime[j] > N)
                break;
            p[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            phi[i * prime[j]] = phi[i] * phi[prime[j]];
        }
    }
    phi[0] = 0;
    tot = 0;
    for (i = 2; i <= N; ++i) {
        phi[i] += phi[i-1];
        phi[i] %= mod;
    }
    scanf("%lld", &n);
    a = find(n);
    printf("%lld\n", a);
    return 0;
}