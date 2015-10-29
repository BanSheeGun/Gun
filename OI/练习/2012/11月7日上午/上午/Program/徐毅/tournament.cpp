#include <cstdio>

const int MAXN = 55;

bool a[MAXN][MAXN], g[MAXN][MAXN];

int main()
{
    freopen("tournament.in", "r", stdin);
    freopen("tournament.out", "w", stdout);
    int n;
    scanf("%d", &n);
    int m = n * (n - 1) / 2;
    for (int i = 1; i < m; ++ i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x][y] = a[x][y] = true;
    }
    for (int k = 1; k <= n; ++ k)
        for (int i = 1; i <= n; ++ i)
            if (i != k)
                for (int j = 1; j <= n; ++ j)
                    if (j != k && i != j && g[i][k] && g[k][j])
                        g[i][j] = true;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j)
            if (g[i][j] && !a[i][j] && !a[j][i])
            {
                printf("%d %d\n", i, j);
                return 0;
            }
    return 0;
}
