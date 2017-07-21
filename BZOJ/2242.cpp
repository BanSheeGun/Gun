/**************************************************************
    Problem: 2242
    User: Gunpowder
    Language: C++
    Result: Accepted
    Time:2204 ms
    Memory:2816 kb
****************************************************************/

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
 
int T, K;
ll y, z, p;
map<ll, int> hash;
 
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
 
inline int work() {
    ll x;
    if (K == 1) {
        x = f(y, z, p);
    } else {
        if (K == 2) {
            ll xx, yy;
            ll tmp = exgcd(y, p, xx, yy);
            if (z % tmp != 0) {
                puts("Orz, I cannot find x!");
                return 0;
            }
            z /= tmp;
            x = z * xx % p;
            x = (x + p) % p;
        } else {
            x = bsgs(y, z, p);
            if (x == -1) {
                puts("Orz, I cannot find x!");
                return 0;
            }
        }
    }
    printf("%lld\n", x);
    return 0;
}
 
int main() {
    while (~scanf("%d%d", &T, &K)) {
        while (T--) {
            scanf("%lld%lld%lld", &y, &z, &p);
            work();
        }
    }
    return 0;
}