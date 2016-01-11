#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int sum[2000000];
int ss[4];
int a[1010][1010];
char b[1010];
int i,j,k,ans,n,m,top,x,y;

int dfs(int x,int y) {
    int i;
    a[x][y] = top;
    ++sum[top];
    for (i = 0;i <4;++i) {
        if (a[x + dx[i]][y + dy[i]] == 0)
            dfs(x + dx[i], y + dy[i]);
    }
    return 0;
}

int main()
{
    scanf("%d%d",&n,&m);
    for (i = 1;i <= n;++i) {
        scanf("%s",b);
        for (j = 1;j <= m;++j)
            if (b[j-1] == '.')
                a[i][j] = 0;
            else
                a[i][j] = -1;
    }
    for (i = 0;i <= n+1;++i) {
        a[i][0] = -1;
        a[i][m+1] = -1;
    }
    for (i = 0;i <= m+1;++i) {
        a[0][i] = -1;
        a[n+1][i] = -1;
    }

    top = 0;
    for (i = 1;i <= n; ++i)
        for (j = 1;j <= m; ++j)
            if (a[i][j] == 0) {
                ++top;
                sum[top] = 0;
                dfs(i,j);
            }

    for (i = 1;i <= n; ++i) {
        for (j = 1;j <= m; ++j)
            if (a[i][j] != -1) {
                printf(".");
            } else {
                ans = 1;
                for (k = 0;k < 4;++k) {
                    x = i + dx[k];
                    y = j + dy[k];
                    ss[k] = a[x][y];
                }
                if (ss[0] != -1) ans += sum[ss[0]];
                if (ss[1] != -1&&ss[0]!=ss[1]) ans += sum[ss[1]];
                if (ss[2] != -1&&ss[0]!=ss[2]&&ss[1]!=ss[2]) ans += sum[ss[2]];
                if (ss[3] != -1&&ss[0]!=ss[3]&&ss[1]!=ss[3]&&ss[2]!=ss[3]) ans += sum[ss[3]];
                printf("%d",ans % 10);
            }
        putchar('\n');
    }
    return 0;
}
