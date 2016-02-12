#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int a[60][60];
int t[60][60];
int fx[4] = {1, 0,-1, 0};
int fy[4] = {0, 1, 0,-1};
int n,m,i,j,ans;
char b[60];

int dfs(int x,int y,int now,int ffx,int ffy) {
    if (ans == 1)
        return 0;
    t[x][y] = 1;
    for (int i = 0;i < 4; ++i) {
        int xx = x + fx[i];
        int yy = y + fy[i];
        if (xx == ffx && yy == ffy)
            continue;
        if (a[xx][yy] == a[x][y]) {
            if (t[xx][yy]) {
                if (now >= 4) {
                    ans = 1;
                    return 0;
                }
            } else {
                dfs(xx,yy,now+1,x,y);
            }
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
            a[i][j] = b[j-1] - 'A' + 1;
        }
    }
    memset(t,0,sizeof(t));
    ans = 0;
    for (i = 1;i <= n; ++i) {
        for (j = 1; j<= m; ++j) {
            if (t[i][j] == 0)
                dfs(i,j,1,0,0);
        }
    }
    if (ans)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
