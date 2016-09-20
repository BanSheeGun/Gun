#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int a[60][60];
int n, m, ans, t, i, j, T;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        memset(a, 0, sizeof(a));
        ans = 0;
        for (i = 1; i <= n; ++i) {
            for (j = 1; j <= m; ++j) {
                scanf("%d", &a[i][j]);
                if (a[i][j] != 0) ans += 1;
            }
        }

        for (i = 1; i <= n; ++i) {
            for (j = 1; j <= m; ++j) {
                ans += max(0, a[i][j] - a[i-1][j]);
                ans += max(0, a[i][j] - a[i+1][j]);
                ans += max(0, a[i][j] - a[i][j-1]);
                ans += max(0, a[i][j] - a[i][j+1]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}