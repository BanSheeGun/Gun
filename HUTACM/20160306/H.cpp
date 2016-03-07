#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;

int fx[4] = {1, 0,-1, 0};
int fy[4] = {0, 1, 0,-1};
int a[30][30];
char tmp[30];
int i, j, m, n, ans, x, y;

int dfs(int x, int y) {
    ++ans;
    a[x][y] = 1;
    for (int i = 0; i < 4; ++i) {
        int xx = x + fx[i];
        int yy = y + fy[i];
        if (a[xx][yy] == 0) dfs(xx, yy);
    }
}

int main() {
    scanf("%d%d",&m,&n);
    while (n != 0 || m != 0) {
        memset(a, 0, sizeof(a));
        for (i = 0; i <= m + 1; ++i) {
            a[0][i] = 1;
            a[n+1][i] = 1;
        }
        for (i = 1;i <= n; ++i) {
            a[i][0] = 1;
            a[i][m+1] = 1;
            scanf("%s",tmp);
            for (j = 1; j <= m; ++j)
                if (tmp[j-1] == '#') {
                    a[i][j] = 1;
                } else if (tmp[j-1] == '@') {
                    x = i;
                    y = j;
                }
        }
        ans = 0;
        dfs(x, y);
        printf("%d\n",ans);

        scanf("%d%d",&m,&n);
    }
    return 0;
}