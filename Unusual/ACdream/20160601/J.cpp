#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int f[2010][2010];
int v[2010];
int ans[2010];
int e[4010];
int nxt[4010];
int head[2010];
int x, y, i, n, j;

int dfs(int k, int fa) {
    int i, j, y;
    f[k][0] = 1;
    for (i = 1; i <= n; ++i)
        f[k][i] = 1000000000;
    f[k][1] = v[k];
    for (i = head[k]; i != 0; i = nxt[i]) {
        y = e[i];
        if (fa != y) {
            dfs(y, k);
        }
    }
    if (fa != 0) {
        for (i = f[fa][0]; i >= 1; --i)
            for (j = 1; j <= f[k][0]; ++j)
                if (i + j <= n) {
                    f[fa][i+j] = min(f[fa][i+j], f[fa][i] + f[k][j]);
                }
        f[fa][0] = max(f[fa][0], f[fa][0] + f[k][0]);
        f[fa][0] = min(f[fa][0], n);
    }
    return 0;
}

int main() {
    scanf("%d", &n);
    for (i = 1; i <= n; ++i) {
        scanf("%d", &v[i]);
    }
    for (i = 1; i < n; ++i) {
        scanf("%d%d", &x, &y);
        e[i*2-1] = y;
        nxt[i*2-1] = head[x];
        head[x] = i*2-1;
        e[i*2] = x;
        nxt[i*2] = head[y];
        head[y] = i*2;
    }

    dfs(1, 0);

    for (i = 1; i <= n; ++i)
        ans[i] = 1000000000;
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; ++j)
            ans[j] = min(ans[j], f[i][j]);

    for (i = 1; i < n; ++i)
        printf("%d ", ans[i]);
    printf("%d\n", ans[n]);
    return 0;
}