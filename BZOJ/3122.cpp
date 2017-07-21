/**************************************************************
    Problem: 3122
    User: Gunpowder
    Language: C++
    Result: Accepted
    Time:3212 ms
    Memory:2552 kb
****************************************************************/
 
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
 
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
 
ll p, a, b, x, t;
int T;
 
map<ll, int> hash;
 
ll bsgs(ll a, ll b, ll p) {
    int i;
    a %= p;
    if (a == 0) {
        if (b == 0)
            return 1;
        return -2;
    }
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
    return -2;
}
 
inline ll s1() {
    ll xx, yy;
    ll tmp = (t - x + p) % p;
    ll tt = exgcd(b, p, xx, yy);
    if (tmp % tt != 0)
        return -1;
    tmp /= tt;
    xx = xx * tmp % p;
    xx = (xx + p) % p;
    return xx + 1;
}
 
inline ll s2() {
    ll c = f(a-1, p-2, p), xx, yy;
    ll aa = (x + b * c) % p;
    ll bb = (t + b * c) % p;
    ll tt = exgcd(aa, p, xx, yy);
    if (bb % tt != 0)
        return -1;
    bb /= tt;
    xx = (xx + p) % p;
    xx *= bb;
    xx %= p;
    return bsgs(a, xx, p) + 1;
}
 
inline ll solve() {
    if (x == t)
        return 1;
    if (a == 0)
        return (b == t) ? 2 : -1;
    if (a == 1)
        return s1();
    return s2();
}
 
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld%lld%lld%lld", &p, &a, &b, &x, &t);
        printf("%lld\n", solve());
    }
    return 0;
}