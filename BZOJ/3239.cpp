#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;

map<ll, int> hash;
ll i, j;

inline ll f(ll a, ll n, const ll & p) {
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

ll exgcd(ll a,ll b,ll &x,ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll tmp = exgcd(b, a % b, x, y);
    ll x1 = y;
    ll y1 = x - (a / b) * y;
    x = x1;
    y = y1;
    return tmp;
}

ll bsgs(ll a, ll b, ll p) {
    ll xx, yy;
    if (exgcd(a, p, xx, yy) != 1)
        return -1;
    int i;
    a %= p;
    ll m = ceil(sqrt(p));
    hash.clear();
    ll tmp, ans = b % p;
    for (i = 0; i <= m; ++i) {
        hash[ans] = i;
        ans = ans * a % p;
    }
    tmp = f(a, m, p);
    ans = 1;
    for (i = 1; i <= m; ++i) {
        ans = ans * tmp % p;
        if (hash[ans] != 0)
            return i * m - hash[ans];
    }
    return -1;
}

ll p, b, n;

int main() {
    while (~scanf("%lld%lld%lld", &p, &b, &n)) {
        ll tmp = bsgs(b, n, p);
        if (tmp != -1)
            printf("%lld\n", tmp);
        else
            puts("no solution");
    }
    return 0;
}