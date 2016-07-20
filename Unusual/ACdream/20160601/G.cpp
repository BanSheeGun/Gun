#include<cstdio>
#include<cstdlib>

using namespace std;

const int N = 100005;
const long long base = 1000000007;
long long a[N], b[N], sa[N], sb[N];
long long ans, n, i;

int main() {
    a[0] = 0;
    sa[0] = 0;
    b[0] = 0;
    sb[0] = 0;
    ans = 0;
    scanf("%lld", &n);
    for (i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        a[i] %= base;
        sa[i] = sa[i-1] + a[i];
        sa[i] %= base;
    } 

    for (i = 1; i <= n; ++i) {
        scanf("%lld", &b[i]);
        b[i] %= base;
        sb[i] = sb[i-1] + b[i];
        sb[i] %= base;
    }

    for (i = 1; i <= n; ++i) {
        ans = (sa[i] * b[i] % base);
        ans = ans + (sb[i] * a[i] % base);
        ans %= base;
        ans = ans - (a[i] * b[i] % base);
        ans = (ans + base) % base;
        if (i == n)
            printf("%lld\n", ans);
        else
            printf("%lld ", ans);
    }
    return 0;
}