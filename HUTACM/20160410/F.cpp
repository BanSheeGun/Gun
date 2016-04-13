#include<cstdio>
#include<algorithm>
#include<cstring> 
using namespace std;

int a[501][501];
int f[501][501];
int n, m, i, j, ans;
int ff(int x, int y) {
    if (f[x][y] != 0)
        return f[x][y];
    f[x][y] = 1;
    if (a[x-1][y]<a[x][y]) f[x][y] = max(f[x][y], ff(x-1,y)+1);
    if (a[x+1][y]<a[x][y]) f[x][y] = max(f[x][y], ff(x+1,y)+1);
    if (a[x][y-1]<a[x][y]) f[x][y] = max(f[x][y], ff(x,y-1)+1);
    if (a[x][y+1]<a[x][y]) f[x][y] = max(f[x][y], ff(x,y+1)+1);
    return f[x][y];
}
int main() {
    memset(f, 0, sizeof(f));
    scanf("%d%d", &n, &m);
    for (i = 0; i <= n+1; ++i)
        for (j = 0; j <= m+1; ++j)
            a[i][j] = 20000;
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]);
    ans=0;
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= m; ++j) {
            ff(i, j);
            ans = max(f[i][j], ans);
        }
    printf("%d\n", ans);
    return 0;
}
