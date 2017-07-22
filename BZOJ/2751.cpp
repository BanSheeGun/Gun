/**************************************************************
    Problem: 2751
    User: Gunpowder
    Language: C++
    Result: Accepted
    Time:212 ms
    Memory:2384 kb
****************************************************************/
 
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
struct A {
    ll x, y;    
};
 
inline bool cmp(const A & a, const A & b) {
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
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
 
A a[100010];
ll n, m, k, i, t1, tmp, ans, lx, ly;
 
int main() {
    scanf("%lld%lld%lld", &n, &m, &k);
    t1 = n * (n + 1) / 2 % mod;
    for (i = 1; i <= k; ++i)
        scanf("%lld%lld", &a[i].x, &a[i].y);
    ans = 1;
    sort(a+1, a+1+k, cmp);
    lx = 0; tmp = 1; ly = 0;
    a[k+1].x = -1;
    for (i = 1; i <= k+1; ++i) {
        if (lx != a[i].x) {
            lx = a[i].x;
            ans = ans * tmp % mod;
            --m;
            tmp = t1 - a[i].y;
            tmp = (tmp + mod) % mod;
            ly = a[i].y;
        } else {
            if (ly == a[i].y)
                continue;
            tmp -= a[i].y;
            tmp = (tmp + mod) % mod;
            ly = a[i].y;
        }
    }
    ++m;
    t1 = f(t1, m, mod);
    ans = ans * t1 % mod;
    printf("%lld\n", ans);
    return 0;
}
