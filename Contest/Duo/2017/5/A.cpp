#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<bitset>
using namespace std;
typedef long long ll;
const int L = 63;
int T, n, m, q, k, l, j;
ll now[50000];
ll ans[50000];

inline void work(int l, int r) {
    ll tmp = 0;
    int f1 = l-1, f2 = 0;
    while (f1 != r) {
        int nx1 = L - (f1+1) % L;
        nx1 = min(nx1, r-f1);
        int nx2 = L - (f2+1) % L;
        int nx = min(nx1, nx2);
        tmp = now[(f1 + nx) / L];
        tmp >>= (f1+1) % L;
        tmp %= (1LL << (nx % L));
        ans[(f2 + nx) / L] ^= tmp << ((f2 + 1) % L - 1);
        f1 += nx;
        f2 += nx;
    }
    return;
}

int bb[100010];

int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d%d%d", &n, &m, &q);
        l = 0;
        memset(now, 0, sizeof(now));
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &k);
            now[k/L] |= 1LL << (k % L);
            l = max(l, k);
        }
        for (int i = 1; i <= m; ++i)
            scanf("%d", &bb[i]);
        sort(bb+1, bb+1+m);
        bb[0] = 0;
        for (int i = 1; i <= m; ++i)
            if (bb[i] == bb[i-1]) {
                bb[i] = 0;
                bb[i-1] = 0;
            }
        memset(ans, 0, sizeof(ans));
        for (int i = 1; i <= m; ++i) {
            k = bb[i];
            if (k == 0)
                continue;
            for (j = 1; j <= ((l+k) / k); ++j)
                work((j-1) * k, min(l, j * k - 1));
        }

        for (int i = 1; i <= q; ++i) {
            scanf("%d", &k);
            ll tmp = 1 << (k % L);
            printf("%d\n", (int)((ans[k/L] & tmp) != 0));
        }
    }
    return 0;
}