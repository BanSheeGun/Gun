#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long ll;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll f[20][500000];
const ll mod = 1e9 + 7;
int n, k, i, j, l, r;
int a[20];
ll now, tmp1, tmp2, ans;

int main() {
    memset(f, 0, sizeof(f));
    scanf("%d%d", &n, &k);
    for (i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    f[0][0] = 1;
    for (now = 0; now < (1 << n); ++now)
        for (j = 0; j <= n; ++j) 
            if (f[j][now] != 0) {
                for (l = 1; l <= n; ++l)
                    if ((now & (1 << (l-1))) == 0) {
                        tmp1 = now;
                        tmp2 = a[l];
                        for (r = l; r <= n; ++r) {
                            if ((now & (1 << (r-1))) != 0)
                                continue;
                            tmp1 |= ((1 << (r-1)));
                            tmp2 = gcd(tmp2, a[r]);
                            if (tmp2 >= k)
                                f[j+1][tmp1] = (f[j+1][tmp1] + f[j][now]) % mod;
                            else
                                break;
                        }
                    }
            }

    ans = 0;
    tmp1 = (1 << n) - 1;
    for (i = 1; i <= n; ++i)
        ans = (ans + i * f[i][tmp1]) % mod;
    if (ans < 0)
        ans += mod;
    printf("%lld\n", ans);
    return 0; 
}