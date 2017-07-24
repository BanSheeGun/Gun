#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

struct M {
    ll a[102][102];
    int i, j, k;

    M() {
        memset(a, 0, sizeof(a));
    }

    M operator * (const M & B) {
        M C;
        for (i = 1; i <= 101; ++i)
            for (j = 1; j <= 101; ++j)
                for (k = 1; k <= 101; ++k)
                    C.a[i][k] = (C.a[i][k] + a[i][j] * B.a[j][k]) % mod;
        return C;
    }
};

M ff(int n, M a) {
    M tmp, ans;
    for (int i = 1; i <= 101; ++i)
        ans.a[i][i] = 1;
    tmp = a;
    while (n != 0) {
        if (n & 1)
            ans = ans * tmp;
        tmp = tmp * tmp;
        n = n >> 1;
    }
    return ans;
}

M a, b;
int n, x, i, j;
ll f[111];
int d[100010];
ll ans;

int main() {
    scanf("%d%d", &n, &x);
    for (i = 1; i <= n; ++i)
        scanf("%d", &d[i]);
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for (i = 1; i <= 100; ++i)
        for (j = 1; j <= n; ++j)
            if (i - d[j] >= 0)
                f[i] = (f[i] + f[i - d[j]]) % mod;
    for (i = 1; i <= 99; ++i)
        a.a[i + 1][i] = 1;
    for (i = 1; i <= n; ++i) {
        a.a[101 - d[i]][100]++;
        a.a[101 - d[i]][101]++;
    }
    a.a[101][101] = 1;
    if (x <= 100) {
        ans = 0;
        for (i = 0; i <= x; ++i)
            ans = (ans + f[i]) % mod;
        printf("%lld\n", ans);
    } else {
        b = ff(x - 100, a);
        ans = 0;
        for (i = 0; i <= 100; ++i)
            f[101] = (f[101] + f[i]) % mod;
        for (i = 1; i <= 101; ++i)
            ans = (ans + f[i] * b.a[i][101]) % mod;
        printf("%lld\n", ans);
    }
    return 0;
}