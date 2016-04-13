#include<cstdio>
#include<algorithm>
#include<cstring> 
using namespace std;

int a[102][102];
int n, i, j, x, y, ans, s;

int main() {
    memset(a, 0, sizeof(a));
    scanf("%d", &n);
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; ++j)
            scanf("%d", &a[i][j]);
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; ++j)
             a[i][j] = a[i-1][j] + a[i][j];
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; ++j)
             a[i][j] = a[i][j-1] + a[i][j];
    
    ans = 0;
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; ++j)
            for (x = 0; x <= i; ++x)
                for (y = 0; y <= j; ++y) {
                    s = a[i][j] + a[x][y] - a[i][y] - a[x][j];
                    ans = max(ans, s);
                }
             
    printf("%d\n", ans);
    return 0;
}
