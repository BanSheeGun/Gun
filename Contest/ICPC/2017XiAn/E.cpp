#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const ll mod2 = 5e8+4;

inline ll qm(ll a, ll n, const ll & p) {
    ll ans = 1;
    ll tmp = a;
    while (n != 0) {
        if (n & 1)
            ans = ans * tmp % p;
        n = n >> 1;
        tmp = tmp * tmp % p;
    }
    return ans;
}

int T;
ll ans, n;

int main() {
    while (~scanf("%lld", &n)) {
        ans = 1;
        ll a = 1;
        ll b = 1;
        ll d = 2;
        while (d < n) {
            ll tmp = (n - 1 + b) / d % mod;
            tmp = tmp * (a + 1) % mod;
            b = b * 2;
            a = a * 4 % mod;
            d = d * 2;
            ans = (ans + tmp) % mod;
        }
        printf("%lld\n", (ans + mod) % mod);
    }
    return 0;
}