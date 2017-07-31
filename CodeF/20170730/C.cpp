#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

int n;
ll a, b;

ll find(ll l, ll r, ll n) {
    if (l == r)
        return l;
    ll mid = (l + r + 1) >> 1;
    if (mid * mid * mid <= n)
        return find(mid, r, n);
    return find(l, mid-1, n);
}

inline int work(const ll & a, const ll & b) {
    ll n = a * b;
    ll ans = find(1, pow(n, 1.0/3) + 10, n);
    if (ans * ans * ans != n) {
        puts("NO");
        return 0;
    }
    if (a % ans != 0 || b % ans != 0) {
        puts("NO");
        return 0;
    }
    puts("YES");
    return 0;
}

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%lld%lld", &a, &b);
        work(a, b);
    }    
    return 0;
}