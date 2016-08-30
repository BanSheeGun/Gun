#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

ll t[110];
ll c[110][110];
ll f[110][110][110];
ll i, j, k, jj, z, n, m, ans, ma;

int main() {
    scanf("%lld%lld%lld", &n, &m, &k);
    for (i = 1; i <= n; ++i) {
        scanf("%lld", &t[i]);
    }
    ma = 1e12;
    for (i = 0; i <= n; ++i)
        for (j = 0; j <= m; ++j)
            for (z = 0; z <= k; ++z)
                f[i][j][z] = ma;
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= m; ++j)
            scanf("%lld", &c[i][j]);
    f[0][0][0] = 0;
    for (i = 1; i <= n; ++i) {
        if (t[i] != 0) {
            j = t[i];
            for (z = 1; z <= k; ++z) {
                for (jj = 0; jj <= m; ++jj)
                    if (jj == j)
                        f[i][j][z] = min(f[i][j][z], f[i-1][jj][z]);
                    else
                        f[i][j][z] = min(f[i][j][z], f[i-1][jj][z-1]);
            }
        } else {
            for (j = 1; j <= m; ++j)
                for (z = 1; z <= k; ++z)
                    for (jj = 0; jj <= m; ++jj)
                        if (jj == j)
                            f[i][j][z] = min(f[i][j][z], f[i-1][jj][z] + c[i][j]);
                        else
                            f[i][j][z] = min(f[i][j][z], f[i-1][jj][z-1] + c[i][j]);
        }
    }
    if (t[n] != 0) {
        ans = f[n][t[n]][k];
    } else {
        ans = ma;
        for (j = 1; j <= m; ++j)
            ans = min(ans, f[n][j][k]);
    }
    if (ans != ma) {
        printf("%lld\n", ans);
    } else {
        printf("-1\n");
    }
    return 0;
}