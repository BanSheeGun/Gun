#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;

int fx[4] = {0, 1, 0,-1};
int fy[4] = {1, 0,-1, 0};
int a[1003][1003];
int n,m,i,j,xxx,x2,yyy,y2,ans,test,kk;
int f, p;
char aa[1010];

struct Point {
    int x, y;
    int step;
    int st;
};

Point d[2000000];
int t[1003][1003];

int bfs() {
    for (f = 1;f <= p; ++f) {
        int s = d[f].step + 1;
        for (int i = 0;i < 4; ++i) {
            int xx = d[f].x + fx[i];
            int yy = d[f].y + fy[i];
            if (a[xx][yy] == -2 && d[f].st == 0) {
                ans = s;
                return 0;
            }
            if (a[xx][yy] == 0) {
                t[xx][yy] = 1;
                ++p;
                d[p].x = xx; d[p].y = yy;
                d[p].step = s; d[p].st = d[f].st;
                a[xx][yy] = 1;
            }
        }
    }
    return 0;
}

int main() {
    scanf("%d", &test);
    while (test--) {
        p= 0;
        memset(t, 0, sizeof(t));
        scanf("%d%d",&n,&m);
        memset(a, 0, sizeof(a));
        for (i = 0; i <= m+1; ++i) {
            a[0][i] = -2;
            a[n+1][i] = -2;
        }
        for (i = 1; i <= n; ++i) {
            a[i][0] = -2;
            a[i][m+1] = -2;
            scanf("%s",aa);
            for (j = 1; j <= m;++j)
                if (aa[j-1] == '#')
                    a[i][j] = -1;
                else
                    if (aa[j-1] == 'J') {
                        xxx = i;
                        yyy = j;
                    } else {
                        if (aa[j-1] == 'F') {
                            ++p;
                            d[p].x = i;
                            d[p].y = j;
                            d[p].step = 0;
                            d[p].st = 1;
                            a[i][j] = 1;
                        }
                    }
        }
        ans = 0;
        ++p;
        d[p].x = xxx;
        d[p].y = yyy;
        d[p].step = 0;
        d[p].st = 0;
        a[xxx][x2] = 1;
        bfs();
        if (ans == 0)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}