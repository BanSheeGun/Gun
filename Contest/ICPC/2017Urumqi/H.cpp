#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int dis[10010];
int head[10010];
int nxt[100010];
int e[100010];
int l[100010];
int pan[10010];
int d[10000000];
int T, n, m, i, f, p, x, y, z, k, ans;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        memset(dis, 0, sizeof(dis));
        memset(head, 0, sizeof(head));
        memset(nxt, 0, sizeof(nxt));
        f = 1;
        p = n;
        for (i = 1; i <= n; ++i) {
            d[i] = i;
            pan[i] = 1;
        }
        for (i = 1; i <= m; ++i) {
            scanf("%d%d%d", &x, &y, &z);
            nxt[i] = head[x];
            e[i] = y;
            head[x] = i;
            l[i] = z;
        }
        memset(pan, 0, sizeof(pan));
        while (f <= p) {
            x = d[f];
            for (k = head[x]; k != 0; k = nxt[k]) {
                y = e[k];
                if (dis[x] + l[k] > dis[y]) {
                    dis[y] = dis[x] + l[k];
                    if (pan[y] == 0) {
                        d[++p] = y;
                        pan[y] = 1;
                    }
                }
            }
            pan[x] = 0;
            ++f;
        }
        ans = dis[1];
        for (i = 1; i <= n; ++i)
            ans = max(ans, dis[i]);
        printf("%d\n", ans);
    }
    return 0;
}