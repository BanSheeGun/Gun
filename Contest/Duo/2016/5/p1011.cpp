#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int MOD = 1000000007;
int a[1010];
int b[1010];
int f[1010][1010];
int s[1010][1010];
int i, j, n, m, ans;

int main() {
    while (~scanf("%d%d", &n, &m)) {
        for (i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        for (i = 1; i <= m; ++i)
            scanf("%d", &b[i]);
        memset(f, 0, sizeof(f));
        memset(s, 0, sizeof(s));
        for (i = 1; i <= n; ++i) {
            for (j = 1; j <= m; ++j) {
                if (a[i] == b[j])
                    f[i][j] = s[i-1][j-1]+1;
                else
                    f[i][j] = 0;
                s[i][j] = (s[i][j-1] + f[i][j]) % MOD;
            }

            for (j = 1; j <= m; ++j)
                s[i][j] = (s[i][j] + s[i-1][j]) % MOD;
        }

        ans = 0;
        for (i = 1; i <= n; ++i)
            for (j = 1; j <= m; ++j)
                ans = (ans + f[i][j]) % MOD;
        if (ans < 0) ans = ans + MOD;
        printf("%d\n", ans);
    }
    return 0;
}