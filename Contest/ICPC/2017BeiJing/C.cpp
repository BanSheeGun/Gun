#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int a[310][310];
int f[310][310][310][2];
int i, j, l, ans, n, m, p, sum, mi;

int main() {
    memset(f, 0, sizeof(f));
    while (~scanf("%d%d%d", &n, &m, &p)) {
        for (i = 1; i <= n; ++i)
            for (j = 1; j <= m; ++j)
                scanf("%d", &a[i][j]);

        ans = p;
        for (i = 1; i <= n; ++i)
            for (j = 1; j <= m; ++j) {
                mi = a[i][j];
                sum = 0;
                for (l = 1; l <= j; ++l) {
                    mi = min(mi, a[i][j + 1 - l]);
                    sum += a[i][j + 1 - l];
                    f[i][j][l][0] = sum + max(0, f[i-1][j][l][0]);
                    f[i][j][l][1] = sum - mi + p + max(0, f[i-1][j][l][0]);
                    if (i != 1)
                        f[i][j][l][1] = max(f[i][j][l][1], sum + max(0, f[i-1][j][l][1]));
                    ans = max(ans, f[i][j][l][1]);
                    ans = max(ans, f[i][j][l][0]);
                }
            }
        sum = 0;
        mi = a[1][1];
        for (i = 1; i <= n; ++i)
            for (j = 1; j <= m; ++j) {
                sum += a[i][j];
                mi = min(a[i][j], mi);
            }
        if (sum == ans) {
            int tmp = 0;
            for (i = 1; i <= n; ++i)
                for (j = 1; j <= m; ++j)
                    for (l = 1; l <= j; ++l) {
                        if (f[i][j][l][1] == ans)
                            ++tmp;
                        if (f[i][j][l][0] == ans)
                            ++tmp;
                    }
            if (tmp == 1) {
                ans = ans - mi + p;
                for (i = 1; i <= n; ++i)
                for (j = 1; j <= m; ++j)
                    for (l = 1; l <= j; ++l) {
                        if (f[i][j][l][1] != sum)
                            ans = max(ans, f[i][j][l][1]);
                        if (f[i][j][l][0] != sum)
                            ans = max(ans, f[i][j][l][0]);
                    }
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}