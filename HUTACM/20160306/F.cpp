#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;

int fx[4] = {0, 1, 0,-1};
int fy[4] = {1, 0,-1, 0};
int a[101][101];
int t[101][101][30];
int n,m,i,j,x1,x2,y1,y2,ans,test,kk;
char aa[110];

int dfs(int x, int y, int f,int step) {
    if (a[x][y] == -1)
        return 0;
    if (step >= t[x][y][f] && t[x][y][f] != 0)
        return 0;
    if (step > kk)
        return 0;
    t[x][y][f] = step;
    if (x == x2 && y == y2) {
        ans = 1;
        return 0;
    }

    dfs(x + fx[f], y + fy[f],  f, step);
    int i;
    for (i = 0;i < 4; ++i) {
        dfs(x + fx[i], y + fy[i], i, step + 1);
        if (ans == 1)
            return 0;
    }
    return 0;
}

int main() {
    scanf("%d", &test);
    while (test--) {
        scanf("%d%d",&n,&m);
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
                if (aa[j-1] == '*')
                    a[i][j] = -1;
        }
        scanf("%d%d%d%d%d",&kk,&y1,&x1,&y2,&x2);
        ++kk;
        ans = 0;
        memset(t, 0, sizeof(t));
        for (i = 0;i < 4; ++i) {
            t[x1][y1][i] = 1;
            dfs(x1 + fx[i], y1 + fy[i],i,1);
            if (ans == 1)
                break;
        }
        if (ans)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
