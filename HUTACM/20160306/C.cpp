#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;

struct point {
    int x,y;
    int blood;
    int father;
    int sec;
};

int fx[4] = {0, 1, 0,-1};
int fy[4] = {1, 0,-1, 0};
int t[110][110];
int a[110][110];
char aa[110];
int n,m,i,j,x1,x2,y1,y2,ans;
point d[1000000];

int Print(int n) {
    int f = d[n].father;
    if (f != 1)
        Print(f);
    if (d[n].x == d[f].x && d[n].y == d[f].y) {
        printf("%ds:FIGHT AT (%d,%d)\n",d[n].sec,d[n].x-1,d[n].y-1);
    } else {
        printf("%ds:(%d,%d)->(%d,%d)\n",d[n].sec,d[f].x-1,d[f].y-1,d[n].x-1,d[n].y-1);
    }
    return 0;
}

inline int bfs() {
    int f = 1;
    int p = 1;
    d[1].x = 1;
    d[1].y = 1;
    d[1].blood = a[1][1];
    d[1].father = 0;
    d[1].sec = 0;
    for (f = 1;f <= p; ++f) {
        if (d[f].blood != 0) {
            ++p;
            d[p] = d[f];
            --d[p].blood;
            d[p].sec++;
            d[p].father = f;
            if (d[p].x == n && d[p].y == m && d[p].blood == 0) {
                ans = d[p].sec;
                printf("It takes %d seconds to reach the target position, let me show you the way.\n",ans);
                Print(p);
                ans = 1;
                return 0;
            }
        } else {
            for (int i = 0; i < 4; ++i) {
                int x = d[f].x + fx[i];
                int y = d[f].y + fy[i];
                if (t[x][y] == 0 && a[x][y] != -1) {
                    t[x][y] = 1;
                    ++p;
                    d[p].x = x;
                    d[p].y = y;
                    d[p].blood = a[x][y];
                    d[p].father = f;
                    d[p].sec = d[f].sec + 1;
                    if (x == n && y == m && d[p].blood == 0) {
                        ans = d[p].sec;
                        printf("It takes %d seconds to reach the target position, let me show you the way.\n",ans);
                        Print(p);
                        ans = 1;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}

int main() {
    while (~scanf("%d%d",&n,&m)) {
        memset(a, 0, sizeof(a));
        for (i = 0; i <= m+1; ++i) {
            a[0][i] = -1;
            a[n+1][i] = -1;
        }
        for (i = 1; i <= n; ++i) {
            a[i][0] = -1;
            a[i][m+1] = -1;
            scanf("%s",aa);
            for (j = 1; j <= m;++j)
                if (aa[j-1] == 'X')
                    a[i][j] = -1;
                else
                    if (aa[j-1] == '.')
                        a[i][j] = 0;
                    else
                        a[i][j] = aa[j-1] - 48;
        }
        ans = 0;
        memset(t, 0, sizeof(t));
        bfs();
        if (ans == 0)
            printf("God please help our poor hero.\n");
        printf("FINISH\n");
    }
    return 0;
}
