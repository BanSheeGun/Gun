#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

inline ll mi(const ll & a, ll b, const ll & p) {
    ll ans = 0;
    ll tmp = a;
    while (b != 0) {
        if (b & 1)
            ans = (ans + tmp) % p;
        tmp = tmp * 2 % p;
        b = b >> 1;
    }
    return ans;
}

inline ll f(const ll & a, ll n,const ll & p) {
    ll ans = 1;
    ll tmp = a;
    while (n != 0) {
        if (n & 1)
            ans = mi(ans, tmp, p);
        tmp = mi(tmp, tmp, p);
        n = n >> 1;
    }
    return ans;
}

ll exgcd(ll a, ll b, ll & x, ll & y) {
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

ll e, p, q, T, n;

int main() {
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld%lld%lld", &e, &p, &q);
        ll m = (p - 1) * (q - 1);
        ll x, y;
        exgcd(e, m, x, y);
        x = (x + m) % m;
        m = p * q;
        scanf("%lld", &n);
        while (n--) {
            scanf("%lld", &y);
            printf("%lld", (f(y, x, m) + m) % m);
            if (n != 0)
                putchar(' ');
            else
                putchar('\n');
        }
    }
	return 0;
}