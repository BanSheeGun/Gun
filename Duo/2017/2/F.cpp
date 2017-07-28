#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

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
ll n, m, ans;

int main() {
    scanf("%d", &T);
    ll mod3 = f(3, mod-2);
    while (T--) {
        scanf("%lld%lld", &n, &m);
        if (n & 1) {
            ans = (f(f(2, n)-1, m-1) * 2 + 1)* mod3 % mod;
        } else {
            ans = f(f(2, n)-1, m-1) * 2 * mod3 % mod;
        }
        ans = ans % mod;
        ans = (ans + mod) % mod;
        printf("%lld\n", ans);
    }
    return 0;
}