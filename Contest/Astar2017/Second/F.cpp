#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

char s[200][200];
int a[200][200];
int ss[200];
int pan[200][200];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n, m, i, j;

void dfs(int x, int y, int now) {
    pan[x][y] = 1;
    for (int i = 0; i < 4; ++i) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (pan[xx][yy] == 0 && a[xx][yy] == now)
            dfs(xx, yy, now);
    }
    return;
}

int main() {
    while (~scanf("%d%d", &n, &m)) {
        for (i = 1; i <= n; ++i)
            scanf("%s", s[i]);

        memset(a, 0, sizeof(a));
        for (i = 1; i <= n; ++i)
            for (j = 1; j <= m; ++j)
                a[i+1][j+1] = s[i][j-1] - '0';

        ++n; ++m;
        ++n; ++m;
        memset(pan, 0, sizeof(pan));
        ss[0] = 0;
        ss[1] = 0;
        for (i = 0; i <= n+1; ++i) {
            a[i][0] = -1;
            a[i][m+1] = -1;
        }
        for (i = 0; i <= m+1; ++i) {
            a[0][i] = -1;
            a[n+1][i] = -1;
        }

        for (i = 1; i <= n; ++i)
            for (j = 1; j <= m; ++j)
                if (pan[i][j] == 0) {
                    ++ss[a[i][j]];
                    dfs(i, j, a[i][j]);
                }

        if (ss[1] == 1 && ss[0] == 2)
            puts("0");
        else
            if (ss[1] == 1 && ss[0] == 1)
                puts("1");
            else
                puts("-1");
    }
    return 0;
}