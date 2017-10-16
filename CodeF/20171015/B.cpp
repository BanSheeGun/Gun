#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int a[100010];
int f[100010];
int g[100101];
int ans, n, k, i;

int main() {
    scanf("%d%d", &n, &k);
    for (i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    if (k == 1) {
        ans = a[1];
        for (i = 1; i <= n; ++i)
            ans = min(ans, a[i]);
    } else
        if (k > 2) {
            ans = a[1];
            for (i = 1; i <= n; ++i)
                ans = max(ans, a[i]);
        } else {
            f[1] = a[1];
            g[1] = a[n];
            for (i = 2; i <= n; ++i) {
                f[i] = min(a[i], f[i-1]);
                g[i] = min(a[n-i+1], g[i-1]);
            }
            ans = max(f[1], g[n]);
            for (i = 2; i <= n; ++i)
                ans = max(ans, max(f[i], g[n-i+1]));
        }
    printf("%d\n", ans);
    return 0;
}