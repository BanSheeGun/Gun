#include <cstdio>
#include <cstring>

const int MAXN = 2222;

int f[MAXN], p[MAXN];

void checkmax(int &x, int y)
{
    if (y > x)
        x = y;
}

int main()
{
    freopen("pack.in", "r", stdin);
    freopen("pack.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i)
    {
        int x;
        scanf("%d", &x);
        if (x == 1)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            memcpy(p, f, sizeof f);
            for (int j = 1; j <= m; ++ j)
            {
                int t = a * j * j - b * j;
                if (t <= 0)
                    continue;
                for (int k = j; k <= m; ++ k)
                    checkmax(p[k], f[k - j] + t);
            }
            memcpy(f, p, sizeof p);
        }
        else if (x == 2)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            for (int j = 1; j <= c; ++ j)
                for (int k = m; k >= b; -- k)
                    checkmax(f[k], f[k - b] + a);
        }
        else
        {
            int a, b;
            scanf("%d%d", &a, &b);
            for (int j = b; j <= m; ++ j)
                checkmax(f[j], f[j - b] + a);
        }
    }
    printf("%d\n", f[m]);
    return 0;
}
