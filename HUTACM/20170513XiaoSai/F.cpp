#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;

int d[50000];
int head[10010];
int e[60010];
int nxt[60010];
int dis[60010];
int t[10010];
int x, y, k, n, m, i, T, ans;
int a[10010], b[10010], c[10010];

int spfa(int * ans, int now) {
    int f = 1, p = 1;
    d[f] = now;
    memset(t, 0, sizeof(t));
    for (i = 1; i <= n; ++i)
        ans[i] = 100000000;
    ans[now] = 0;
    t[now] = 1;
    while (f <= p) {
        x = d[f];
        for (int k = head[x]; k != 0; k = nxt[k]) {
            y = e[k];
            if (ans[x] + dis[k] < ans[y]) {
                ans[y] = ans[x] + dis[k];
                if (t[y] == 0) {
                    t[y] = 1;
                    ++p;
                    d[p] = y;
                }
            }
        }
        t[x] = 0;
        ++f;
    }
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        memset(head, 0, sizeof(head));
        memset(nxt, 0, sizeof(nxt));
        memset(e, 0, sizeof(e));
        for (i = 1; i <=  m; ++i) {
            scanf("%d%d%d", &x, &y, &k);
            nxt[i*2-1] = head[x];
            head[x] = i * 2 - 1;
            e[i*2-1] = y;
            dis[i*2-1] = k;
            nxt[i*2] = head[y];
            head[y] = i * 2;
            e[i*2] = x;
            dis[i*2] = k;
        }
        scanf("%d", &x);
        spfa(a, x);
        scanf("%d", &x);
        spfa(b, x);
        scanf("%d", &x);
        spfa(c, x);
        ans = 300000000;
        for (i = 1; i <= n; ++i) {
            if (a[i] == 100000000)
                continue;
            if (b[i] == 100000000)
                continue;
            if (c[i] == 100000000)
                continue;
            if (a[i] + b[i] + c[i] < ans)
            ans = a[i] + b[i] + c[i];
        }
        if (ans == 300000000)
            ans = -1;
        printf("%d\n", ans);
    }
    return 0; 
}