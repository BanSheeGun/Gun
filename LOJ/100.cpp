#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

ll a[510][510];
ll b[510][510];
ll c[510][510];
int n, p, m, i, j, k;

int main() {
    scanf("%d%d%d", &n, &p, &m);
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= p; ++j)
            scanf("%lld", &a[i][j]);
    for (i = 1; i <= p; ++i)
        for (j = 1; j <= m; ++j)
            scanf("%lld", &b[i][j]);
    memset(c, 0, sizeof(c));
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= p; ++j)
            for (k = 1; k <= m; ++k)
                c[i][k] = (c[i][k] + a[i][j] * b[j][k] % mod) % mod;

    for (i = 1; i <= n; ++i) {
        for (j = 1; j < m; ++j)
            printf("%lld ", (c[i][j] + mod) % mod);
        printf("%lld\n", (c[i][m] + mod) % mod);
    }
	return 0;
}