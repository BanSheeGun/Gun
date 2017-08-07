#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

typedef long long ll;

const ll p = 1000000007;

ll f(ll n, ll a) {
    if (n == 0)
        return 1;
    if (n == 1)
        return a;
    ll t = f(n/2, a);
    t = t * t % p;
    if (n % 2 == 1)
        t = t * a % p;
    return t;
}

ll n, m, p1, p2;
int t;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%lld%lld", &n, &m);
        p1 = f(n+1, m) - 1;
        p2 = f(p-2, m-1);
        p1 = p1 * p2 % p;
        if (p1 < 0) p1 += p;
        printf("%lld\n", p1);
    }
    return 0;
}