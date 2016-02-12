#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int head[2010];
int next[2010];
int e[2010];
int t[2010];
int n, ans, i, y;

int dfs(int now,int step) {
    int k;
    t[now] = 1;
    ans = max(ans, step);
    for (k = head[now];k != 0;k = next[k]) {
        int y = e[k];
        dfs(y, step + 1);
    }
    return 0;
}

int main()
{
    scanf("%d",&n);
    memset(head,0,sizeof(head));
    memset(next,0,sizeof(next));
    for (i = 1;i <= n; ++i) {
        scanf("%d",&y);
        if (y != -1) {
            e[i] = i;
            next[i] = head[y];
            head[y] = i;
        }
    }
    ans = 0;
    memset(t,0,sizeof(t));
    for (i = 1;i <= n; ++i)
        if (t[i] == 0) {
            dfs(i,1);
        }
    printf("%d\n",ans);
    return 0;
}
