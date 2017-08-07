#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

const ll oo = 9223372036854775807L;
ll n, m, i, ma, ans, j, bb;
bool flag;
ll f[2000];
ll a[100010];
ll b[100010];
ll k[2000];
ll p[2000];

int main() {
    while (~scanf("%lld%lld", &n, &m)) {
        ma = 0;
        for (i = 1; i <= n; ++i) {
            scanf("%lld%lld", &a[i], &b[i]);
            ma = max(a[i], ma);
        }
        for (i = 1; i <= m; ++i)
            scanf("%lld%lld", &k[i], &p[i]);

        ans = 0;
        flag = 1;
        for (bb = 0; bb <= 10; ++bb) {
            for (i = 1; i <= ma; ++i)
                f[i] = oo;
            f[0] = 0;
            for (i = 1; i <= ma; ++i) {
                for (j = 1; j <= m; ++j) {
                    if (p[j] <= 0)
                        continue;
                    if (i - p[j] < 0)
                        f[i] = min(f[i], k[j]);
                    else
                        f[i] = min(f[i], k[j] + f[i - p[j]]);
                }
            }

            for (i = 1; i <= n; ++i)
                if (b[i] == bb) {
                    if (f[a[i]] == oo)
                        flag = 0;
                    else
                        ans += f[a[i]];
                }

            for (j = 1; j <= m; ++j)
                --p[j];
        }
        if (flag == 0)
            ans = -1;
        printf("%lld\n", ans);
    }
    return 0;
}