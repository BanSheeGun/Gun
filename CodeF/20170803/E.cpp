#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int N = 1e6 + 7;
ll top, n, i, j;
ll p[N + 10];
ll f[N + 10];
 
inline void init() {
    top = 0;
    memset(f, 0, sizeof(f));
    for (i = 2; i <= N; ++i) {
        if (!f[i]) {
            p[++top] = i;
        }
        for (j = 1; j <= top && i * p[j] <= N; ++j) {
            f[i * p[j]] = 1;
            if (i % p[j] == 0)
                break;
        } 
    }
    return;
}

ll ans, a, b, tmp, ap;

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int fa(ll a, ll b) {
    if (a == 1) {
        ans += b;
        return 0;
    }
    if (b == 0)
        return 0;
    tmp = b;
    for (i = 1; i <= top; ++i) {
        if (p[i] > a)
            break;
        if (a % p[i] != 0)
            continue;
        tmp = min(tmp, b % p[i]);
    }
    ans += tmp;
    b -= tmp;    
    tmp = gcd(a, b);
    a /= tmp;
    b /= tmp;
    fa(a, b);
    return 0;
}

int main() {
    init();
    scanf("%lld%lld", &a, &b);
    ans = 0;
    tmp = gcd(a, b);
    a /= tmp;
    b /= tmp;
    tmp = 0;
    ap = a;
    for (i = 1; i <= top; ++i)
        if (ap % p[i] == 0) {
            p[++tmp] = p[i];
            while (ap % p[i] == 0)
                ap /= p[i];
        }
    if (ap != 1)
        p[++tmp] = ap;
    top = tmp;
    fa(a, b);
    printf("%lld\n", ans);
    return 0;
}