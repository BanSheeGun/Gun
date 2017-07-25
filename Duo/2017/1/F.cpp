#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int head[100010];
int nxt[100010];
int e[100010];
int a[100010], b[100010];
int d[100010];
int n, m, k, i, j;
ll ans;

inline void add(int num, int x, int y) {
    nxt[num] = head[x];
    head[x] = num;
    e[num] = y;
    return;
}

int dfs(int * a, int x, int dd) {
    d[x] = dd;
    for (int k = head[x]; k != -1; k = nxt[k]) {
        int y = e[k];
        if (d[y] == 0)
            dfs(a, y, dd+1);
        else {
            ++a[0];
            a[a[0]] = abs(d[x] - d[y]) + 1;
        }
    }
    return 0;
}

inline void work(int * a, int n) {
    int i;
    for (i = 0; i < n; ++i) {
        head[i] = nxt[i] = -1;
    }
    for (i = 0; i < n; ++i) {
        scanf("%d", &k);
        add(i, k, i);
    }
    memset(d, 0, sizeof(d));
    for (i = 0; i < n; ++i)
        if (d[i] == 0)
            dfs(a, i, 1);
    return;
}

int main() {
    int T = 0;
    while (~scanf("%d%d", &n, &m)) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        work(a, n);
        work(b, m);
        ans = 1;
        for (i = 1; i <= a[0]; ++i) {
            ll tmp = 0;
            for (j = 1; j <= b[0]; ++j)
                if (a[i] % b[j] == 0)
                    tmp = (tmp + b[j]) % mod;
            ans = ans * tmp %  mod;
        }
        printf("Case #%d: %lld\n", ++T, ans);
    }
    return 0;
}