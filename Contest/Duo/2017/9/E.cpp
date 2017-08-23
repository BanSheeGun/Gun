#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

int head[1010];
int e[6010];
int nxt[6010];
int t[1010];
int p[1010];
int q[1010];
int n, m, i, x, y, T, tot;
bool OK;

int dfs(int x) {
    ++tot;
    t[x] = 1;
    ++p[x];
    ++q[i];
    for (int k = head[x]; k != 0; k = nxt[k]) {
        int y = e[k];
        if (t[y] == 0)
            dfs(y);
    }
    return 0;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        memset(head, 0, sizeof(head));
        memset(nxt, 0, sizeof(nxt));
        for (i = 1; i <= m; ++i) {
            scanf("%d%d", &x, &y);
            nxt[i] = head[x];
            e[i] = y;
            head[x] = i;
        }

        OK = 1;
        memset(p, 0, sizeof(p));
        memset(q, 0 ,sizeof(q));
        for (i = 1; i <= n; ++i) {
            tot = 0;
            memset(t, 0, sizeof(t));
            dfs(i);
        }

        for (i = 1; i <= n; ++i)
            if (p[i] + q[i] <= n)
                OK = 0;

        if (OK)
            puts("I love you my love and our love save us!");
        else
            puts("Light my fire!");
    }
    return 0;
}