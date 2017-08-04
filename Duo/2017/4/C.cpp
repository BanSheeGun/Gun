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
int p[N + 10];
int f[N + 10];
 
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

ll now[1000010];
ll tm[1000010];
int ft, T;
ll l, r, k;

int main() {
    init();
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld%lld", &l, &r, &k);
        ll ans = 0;
        for (i = l; i <= r; ++i) {
            now[i-l] = i;
            tm[i-l] = 1; 
        }
        for (i = 1; i <= top; ++i) {
            j = (l + p[i] - 1) / p[i] * p[i];
            while (j <= r) {
                ll tmp = 0;
                while (now[j-l] % p[i] == 0) {
                    ++tmp;
                    now[j-l] /= p[i];
                }
                tm[j-l] *= (tmp * k + 1);
                if (tm[j-l] >= mod)
                    tm[j-l] %= mod;
                j += p[i];
            }
        }
        for (i = l; i <= r; ++i) {
            if (now[i-l] != 1)
                tm[i-l] = tm[i-l] * (k + 1) % mod;
            ans += tm[i-l];
            if (ans >= mod)
                ans %= mod;
        }
        ans = (ans + mod) % mod;
        printf("%lld\n", ans);
    }
    return 0;
}