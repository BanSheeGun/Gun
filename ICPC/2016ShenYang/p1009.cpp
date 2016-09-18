#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[400];
ll sum[400];
ll b[400];
ll ans[400];
ll a1[400];
int t[400][400];
ll f[400][400];
ll i, j, n, l;
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

inline bool check(int l, int r) {
    if (f[l][r])
        return 1;
    for (int i = l; i < r; ++i)
        if (f[l][i] && f[i+1][r])
            return 1;
    return 0;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld", &n);
        for (i = 1; i <= n; ++i)
            scanf("%lld", &a[i]);
        for (i = 1; i <= n; ++i)
            scanf("%lld", &b[i]);
        memset(t, 0, sizeof(t));
        for (i = 1; i <= n; ++i) {
            for (j = 1; j <= n; ++j)
                t[i][j] = (gcd(a[i], a[j]) != 1);
        }
        memset(f, 0, sizeof(f));
        memset(sum, 0, sizeof(sum));
        for (i = 1; i<= n; ++i) sum[i] = sum[i-1] + b[i];
        for (i = 1; i < n; ++i)
            if (t[i][i+1])
                f[i][i+1] = b[i] + b[i+1]; 
        for (l = 3; l <= n; l = l + 2)
            for (i = 1; i + l <= n; ++i)
                if (t[i][i+l] && check(i+1, i+l-1) || check(i, i+l))
                    f[i][i+l] = sum[i+l] - sum[i-1];

        memset(a1, 0, sizeof(a1));
        memset(ans, 0, sizeof(ans));
        for (i = 1; i <= n; ++i) {
            for (j = 1; i - j > 0; j = j + 2)
                a1[i] = max(a1[i], ans[i-j-1] + f[i-j][i]);
            ans[i] = ans[i-1];
            ans[i] = max(ans[i], a1[i]);
        }
        printf("%lld\n", ans[n]);
    }
    return 0;
}