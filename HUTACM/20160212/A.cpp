#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int a[110][110];
int fx[4] = {1, 0,-1, 0};
int fy[4] = {0, 1, 0,-1};
int n,m,i,j;
char b[110];

int dfs(int x,int y,int now) {
    a[x][y] = now;
    for (int i = 0;i < 4; ++i) {
        int xx = x + fx[i];
        int yy = y + fy[i];
        if (a[xx][yy] == 0) {
            dfs(xx,yy, 3 - now);
        }
    }
    return 0;
}

int main()
{
    scanf("%d%d",&n,&m);
    for (i = 0;i <= m+1;++i) {
        a[0][i] = -1;
        a[n+1][i] = -1;
    }
    for (i = 1;i <= n; ++i) {
        a[i][0] = -1;
        a[i][m+1] = -1;
        scanf("%s",b);
        for (j = 1;j <= m;++j) {
            if (b[j-1] == '.') {
                a[i][j] = 0;
            } else {
                a[i][j] = -1;
            }
        }
    }
    for (i = 1;i <= n; ++i) {
        for (j = 1; j<= m; ++j) {
            if (a[i][j] == 0)
                dfs(i,j,1);
        }
    }
    for (i = 1;i <= n; i++) {
        for (j = 1;j <= m; j++)
            if (a[i][j] == 1)
                putchar('B');
            else
                if (a[i][j] == 2)
                    putchar('W');
                else
                    putchar('-');
        putchar('\n');
    }
    return 0;
}
