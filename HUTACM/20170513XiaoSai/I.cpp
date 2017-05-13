#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;

int T;
int n, m, x, y, k, i;
int head[100010];
int nxt[200010];
int e[200010];
long long dis[200010];
int t[100010];
int tt[100010];
long long ans[100010];

int dfs(int x) {
    int k;
    t[x] = 1;
    for (k = head[x]; k != 0; k = nxt[k]){
        int y = e[k];
        if (t[y])
            continue;
        dfs(y);
        if (tt[y]) {
            ans[x] += dis[k];
        } else {
            ans[x] += min(ans[y], dis[k]);
        }
    }
    return 0;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);
        memset(tt, 0, sizeof(tt));
        for (i = 1; i <= k; ++i) {
            scanf("%d", &x);
            tt[x] = 1;
        }
        m = n-1;
        memset(head, 0, sizeof(head));
        memset(nxt, 0, sizeof(nxt));
        for (i = 1; i <= m; ++i) {
            scanf("%d%d%d", &x, &y, &k);
            nxt[i*2-1] = head[x];
            head[x] = i*2-1;
            e[i*2-1] = y;
            dis[i*2-1] = k;
            nxt[i*2] = head[y];
            head[y] = i*2;
            e[i*2] = x;
            dis[i*2] = k;
        }

        memset(t, 0, sizeof(t));
        memset(ans, 0, sizeof(ans));
        dfs(1);
        printf("%lld\n", ans[1]);
    }
    return 0; 
}