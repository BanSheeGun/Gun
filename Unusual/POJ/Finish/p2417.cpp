#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
map<ll, int> h;

inline ll f(const ll & a, ll n, const ll & p) {
    ll ans = 1;
    ll now = a;
    while (n != 0) {
        if (n & 1)
            ans = ans * now % p;
        now = now * now % p;
        n = n >> 1;
    }
    return ans;
}

ll p, a, b, i;

int main() {
    while (~scanf("%lld%lld%lld", &p, &a, &b)) {
        h.clear();
        if (a % p == 0) {
            printf("no solution\n");
            continue;
        }
        ll m = ceil(sqrt(p));
        ll tmp = b % p;
        for (i = 0; i <= m; ++i) {
            h[tmp] = i;
            tmp = tmp * a % p;
        }

        tmp = f(a, m, p);
        ll ans = 1; 
        bool ok = 0;
        for (i = 1; i <= m; ++i) {
            ans = ans * tmp % p;
            if (h[ans]) {
                printf("%lld\n", i * m - h[ans]);
                ok = 1;
                break;
            }
        }
        if (!ok) {
            printf("no solution\n");
        }
    }
	return 0;
}