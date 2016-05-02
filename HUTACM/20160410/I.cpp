#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int n, i, j, m ,ansx, ansy, ans,top, t, k, ma;
int a[510];
int b[510];
int f[505][505];
int x[505][505];
int y[505][505];
int fl[505][505];

int dfs(int xx, int yy) {
    if (x[xx][yy] != 0) {
        dfs(x[xx][yy], y[xx][yy]);
        printf(" %d",a[xx]);
    } else {
        printf("%d",a[xx]);
    }
    return 0;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (i = 1;i <= n; ++i) {
            scanf("%d",&a[i]);
        }
        scanf("%d", &m);
        for (i = 1;i <= m; ++i) {
            scanf("%d",&b[i]);
        }
        memset(f, 0, sizeof(f));
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        memset(fl, 0, sizeof(fl));

        for (i = 1; i <= n; ++i) {
            ma = 0;
            for (j = 1; j <= m; ++j)
                f[i][j] = f[i-1][j];
                x[i][j] = i-1;
                y[i][j] = j;
                if (a[i] == b[j]) {
                    fl[i][j] = 1;
                    if (f[i][j] < f[i-1][ma] + 1) {
                        f[i][j] = f[i-1][ma] + 1;
                        x[i][j] = i-1;
                        y[i][j] = ma;
                    }
                }
                if (a[i] > b[j] && f[i-1][j] < ma) {
                    ma = i-1; 
                }
                ma = max(ma, f[i-1][j]);
            }


        ans = 0;
        for (i = 1; i <= n; ++i)
            for (j = 1; j <= m; ++j)
                if (f[i][j] >= ans && fl[i][j] == 1) {
                    ans = f[i][j];
                    ansx = i;
                    ansy = j;
                }


        for (i = 1; i <= n; ++i) {
            for (j = 1; j <= m; ++j)
                printf("%d ",f[i][j]);
            printf("\n");
        }

        printf("%d\n",ans);
        if (ans !=0) {
            dfs(ansx, ansy);
            putchar('\n');
        }
        if (t != 0) putchar('\n');
    }
    return 0;
}
