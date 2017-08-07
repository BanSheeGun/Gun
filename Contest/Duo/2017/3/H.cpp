#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

int T;
ll n, k;
const ll mod = 1e9 + 7;

inline ll f(ll a, ll n,const ll & p) {
    ll ans = 1;
    ll tmp = a;
    while (n != 0) {
        if (n & 1)
            ans = ans * tmp % p;
        tmp = tmp * tmp % p;
        n = n >> 1;
    }
    return ans;
}

int main() {
    T = 0;
    while (~scanf("%lld%lld", &n, &k)) {
        n %= mod;
        printf("Case #%d: %lld\n", ++T, f(n, k, mod));
    }
    return 0;
}