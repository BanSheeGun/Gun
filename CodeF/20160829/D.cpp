#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long LL;
const int base = 1e9 + 7;

LL head[200010];
LL nxt[400010];
LL e[400010];
LL a[200010];
LL f[200010];
LL t[200010];
LL n, x, y, i, ans, sum, top;
LL er[200010];

inline LL PowMod(LL a, LL b, LL base) {
    LL ans = 0;
    a %= base;
    b %= base;
    LL now = b;
    while (a != 0) {
        ans += now * (a % 2);
        ans %= base;
        now *= 2;
        now %= base;
        a = a / 2;
    }
    return ans;
}

inline LL dfs(LL x, LL dep, LL fa) {
    f[x] = dep;
    for (LL k = head[x]; k != 0; k = nxt[k]) {
        LL y = e[k];
        if ((k+1)/2 == fa) continue;
        if (t[y]) continue;
        if (f[y] != 0) {
            ++top;
            a[top] = f[x] - f[y] + 1;
        } else {
            dfs(y, dep+1, (k+1)/2);
        }
    } 
    t[x] = 1;
    return 0;
}

LL tmp;

int main() {
    memset(head, 0, sizeof(head));
    memset(nxt, 0, sizeof(nxt));
    scanf("%lld", &n);
    for (x = 1; x <= n; ++x) {
        i = x;
        scanf("%lld", &y);
        e[i*2-1] = x; e[i*2] = y;
        nxt[i*2-1] = head[y]; nxt[i*2] = head[x];
        head[y] = i*2-1; head[x] = i*2;
    }

    top = 0;
    memset(t, 0, sizeof(t));
    memset(f, 0, sizeof(f));
    memset(a, 0, sizeof(a));
    for (i = 1; i <= n; ++i)
        if (t[i] == 0) {
            dfs(i, 1, 0);
        }
    er[0] = 1;
    for (i = 1; i <= n; ++i) {
        er[i] = er[i-1] * 2 % base;
    }
    ans = 1; sum = 0;
    for (i = 1; i <= top; ++i) {
        tmp = (er[a[i]] - 2) % base;
        if (tmp < 0) tmp += base;
        ans = PowMod(ans, tmp, base);
        if (ans < 0) ans += base;
        sum += a[i];
    }
    ans = PowMod(ans, er[n - sum], base);
    if (ans < 0) ans += base;
    printf("%lld\n", ans);
    return 0;
}