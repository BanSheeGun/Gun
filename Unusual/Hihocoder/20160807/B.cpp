#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

struct DD {
    int x;
    int y;
};

DD d[5000000];
int t[510][510];
int a[510][510];
int ans[510][510];
int fx[4] = {0, 1, 0,-1};
int fy[4] = {1, 0,-1, 0};
int n, m, k, i, x, y, j, ttt, tt;
int h[510], l[510];

inline int bfs() {
    int f = 1; int q = 1;
    int xx, yy, tmp;
    while (f <= q) {
        int x = d[f].x; int y = d[f].y;
        for (int i = 0; i < 4; ++i) {
            xx = x + fx[i]; yy = y + fy[i];
            if (t[xx][yy] == 0 && a[xx][yy] == 0) {
                if (i == 0) tmp = l[y];
                if (i == 1) tmp = h[x];
                if (i == 2) tmp = l[y-1];
                if (i == 3) tmp = h[x-1];
                if (tmp + ans[x][y] < ans[xx][yy]) {
                    ans[xx][yy] = tmp + ans[x][y];
                    if (t[xx][yy] == 0) {
                        t[xx][yy] = 1;
                        ++q; d[q].x = xx; d[q].y =yy;
                    }
                }
            }
        }
        t[x][y] = 0;
        ++f;
    }
    return 0;
}

int main() {
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n-1; ++i) {
        scanf("%d", &h[i]);
    }
    for (j = 1; j <= m-1; ++j) {
        scanf("%d", &l[j]);
    }
    scanf("%d", &k);
    memset(a, 0 ,sizeof(t));
    for (i = 1; i <= k; ++i) {
        scanf("%d%d", &x, &y);
        a[x][y] = 1;
    }
    for (i = 0; i <= n+1; ++i) {
        a[i][0] = 1;
        a[i][m+1] =1;
    }
    for (i = 0; i <= m+1; ++i) {
        a[0][i] = 1;
        a[n+1][i] =1;
    }

    scanf("%d", &tt);
    for (ttt = 1; ttt <= tt; ++ttt) {
        scanf("%d%d", &x, &y);
        d[1].x = x; d[1].y = y;
        for (i = 1; i <= n; ++i)
            for (j = 1; j <= m; ++j)
                ans[i][j] = 1000000000;
        ans[x][y] = 0;
        memset(t, 0 ,sizeof(t));
        t[x][y] = 1;
        bfs();
        scanf("%d%d", &x, &y);
        if (ans[x][y] != 1000000000)
            printf("%d\n", ans[x][y]);
        else
            printf("-1\n");
    }
    return 0;
}