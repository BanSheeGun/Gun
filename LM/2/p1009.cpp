#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int fx[4] = {0, 1, 0,-1};
int fy[4] = {1, 0,-1, 0};
int a[20][20];
char b[20];
int c[20][20];
int t[20][20];
int i, j, cnt, ans, T, TT;

int dfs(int x, int y) {
    t[x][y] = 1; int ii;
    for (ii = 0; ii < 4; ++ii) {
        int xx = x + fx[ii];
        int yy = y + fy[ii];
        if (a[xx][yy] == 2 && t[xx][yy] == 0)
            dfs(xx, yy);
        if (a[xx][yy] == 1 && c[xx][yy] == 0) {
            ++cnt;
            c[xx][yy] = 1;
        }
    }
    return 0;
}

int main() {
    scanf("%d", &T); TT = 0;
    while (T--) {
        TT++;
        ans = 0;
        memset(a, 0 ,sizeof(a));
        for (i = 1; i <= 9; ++i) {
            scanf("%s", b);
            for (j = 1; j <= 9; ++j)
                if (b[j-1] == '.')
                    a[i][j] = 1;
                else
                    if (b[j-1] == 'o')
                        a[i][j] = 2;
        }
        memset(t, 0, sizeof(t));
        for (i = 1; i <= 9; ++i)
            for (j = 1; j <= 9; ++j) 
                if (a[i][j] == 2 && t[i][j] == 0) {
                    memset(c, 0 ,sizeof(c));
                    cnt = 0;
                    dfs(i, j);
                    if (cnt == 1)
                        ans = 1;
                }
        if (ans)
            printf("Case #%d: Can kill in one move!!!\n", TT);
        else
            printf("Case #%d: Can not kill in one move!!!\n", TT);
    }
    return 0;
}