#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long ll;

const ll mm = 1e18;

ll ans, c1, c2, x, y;

inline bool check(ll now) {
    ll t1, t2, t3, t4;
    t1 = now / x;
    t2 = now / y;
    t3 = t1 / y;
    t1 -= t3; t2 -= t3;
    t4 = now - t1 - t2 - t3;
    if ((t2 + t4) < c1) return 0;
    if (t2 < c1)
        t4 = (t4 + t2) - c1;
    if ((t4 + t1) >= c2)
        return 1;
    else
        return 0; 
}

inline ll find(ll l, ll r) {
    if (l == r) return l;
    ll mid = (l+r) / 2;
    if (check(mid))
        return find(l, mid);
    else
        return find(mid+1, r);
}

int main() {
    scanf("%lld%lld%lld%lld", &c1, &c2, &x, &y);
    ans = find(0, mm+20);
    printf("%lld\n", ans);
    return 0;
}