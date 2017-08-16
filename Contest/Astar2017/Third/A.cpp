#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;
ll f[1010][1010];
int n, m, t, T, i, j;

inline void init() {
    memset(f, 0, sizeof(f));
    f[0][0] = 1;
    for (i = 1; i <= 1000; ++i) {
        f[i][0] = 1;
        for (j = 1; j <= i; ++j)
            f[i][j] = (f[i-1][j] + f[i-1][j-1]) % mod;
    }
    return;
}

int main() {
    init();
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        t = min(n, m);
        ll ans = f[n][t] * f[m][t] % mod;
        printf("%lld\n", ans);
    }
    return 0;
}