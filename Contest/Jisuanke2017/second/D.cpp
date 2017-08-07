#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;

typedef long long ll;

int head[80000];
int nxt[1000000];
int e[1000000];
ll dis[1000000];
int d[8000000];
int n, m, k, x, y, i, s, t, id, f, p;
ll ans[80000], l;
bool pan[80000];

inline void ins(int x, int y, ll l) {
    ++id;
    nxt[id] = head[x];
    head[x] = id;
    e[id] = y;
    dis[id] = l;
}

int main() {
    id = 0;
    memset(head, 0, sizeof(0));
    memset(nxt, 0, sizeof(0));
    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; ++i) {
        scanf("%d", &k);
        while (k--) {
            scanf("%d", &x);
            ins(n + i * 2 - 1, x, 0);
            ins(x, n + i * 2, 0);
        }
    }

    scanf("%d", &k);
    while (k--) {
        scanf("%d%d%lld", &x, &y, &l);
        ins(x, y, l);
        ins(y, x, l);
    }

    scanf("%d", &f);
    while (f--) {
        scanf("%d%d%lld", &x, &y, &l);
        ins(x*2+n, y*2-1+n, l);
        ins(y*2+n, x*2-1+n, l);
    }
    scanf("%d%d", &s, &t);
    for (i = 0; i <= n + m*2; ++i)
        ans[i] = (ll)1e16;
    ans[s] = 0;
    memset(pan, 0, sizeof(pan));
    pan[s] = 1;
    f = 1; p = 1;
    d[1] = s;
    do {
        x = d[f];
        for (k = head[x]; k != 0; k = nxt[k]) {
            y = e[k];
            if (ans[x] + dis[k] < ans[y]) {
                ans[y] = ans[x] + dis[k];
                if (pan[y] == 0) {
                    pan[y] = 1;
                    ++p;
                    d[p] = y;
                }
            }
        }
        pan[x] = 0;
        ++f;
    } while (f <= p);
    if (ans[t] == ans[0])
        ans[t] = -1;
    printf("%lld\n", ans[t]);
    return 0; 
}