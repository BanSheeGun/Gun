#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

struct V
{
    int co;
    int tag;
    bool c[61];
};

int tc;
V a[400010];
int head[400010];
int e[400010];
int next[400010];
int fath[400010];
int n,x,y,i,m,num,ans,j;

int update(int x) {
    int i, k;
    memset(a[x].c,0,sizeof(a[x].c));
    a[x].c[a[x].co] = 1;
    for (k = head[x];k != 0;k = next[k]) {
        int y = e[k];
        for (i = 1;i <= tc; ++i) {
            a[x].c[i] = a[x].c[i] | a[y].c[i];
        }
    }
    if (x != 1) update(fath[x]);
    return 0;
}

int downlow(int x) {
    int i, k;
    for (k = head[x];k != 0;k = next[k]) {
        int y = e[k];
        a[y].tag = a[x].tag;
        memset(a[y].c,0,sizeof(a[y].c));
        a[y].co = a[x].tag;
        a[y].c[a[y].co] = 1;
    }
    a[x].tag = 0;
    return 0;
}

int confirm(int x) {
    if (x != 1)
        confirm(fath[x]);
    if (a[x].tag != 0) downlow(x);
    return 0;
}

int dfs(int x) {
    int i, k;
    for (k = head[x];k != 0;k = next[k]) {
        int y = e[k];
        dfs(y);
    }
    if (head[x] == 0) update(x);
    return 0;
}

int main()
{
    tc = 5;
    scanf("%d%d",&n,&m);
    for (i = 1;i <= n;++i) {
        scanf("%d",&a[i].co);
        a[i].tag = 0;
        memset(a[i].c,0,sizeof(a[i].c));
        tc = max(tc, a[i].co);
        a[i].c[a[i].co] = 1;
    }
    memset(head,0,sizeof(head));
    for (i = 1;i <n;++i) {
        scanf("%d%d",&x,&y);
        next[i] = head[x];
        e[i] = y;
        head[x] = i;
        fath[y] = x;
    }
    dfs(1);

    for (i = 1;i <= m;++i) {
        scanf("%d",&num);
        if (num == 1) {
            scanf("%d%d",&x,&y);
            confirm(x);
            a[x].tag = y;
            a[x].co = y;
            memset(a[x].c,0,sizeof(a[x].c));
            a[x].c[y] = 1;
            update(x);
        } else {
            scanf("%d",&x);
            confirm(x);
            update(x);
            ans = 0;
            for (j = 1;j <= tc;++j) {
                if (a[x].c[j]) ++ans;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
