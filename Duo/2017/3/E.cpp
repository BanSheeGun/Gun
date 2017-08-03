#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#pragma comment(linker, "/STACK:102400000, 102400000")
using namespace std;
typedef long long ll;

int n, k, x, y, i;
int head[1000010];
int nxt[2000010];
ll l[2000010];
int e[2000010];
int sum[2000010];
ll ans, la;

int add(int n, int x, int y, ll la) {
    nxt[n] = head[x];
    head[x] = n;
    e[n] = y;
    l[n] = la;
    return 0;
}

int dfs(int x, int fa) {
    sum[x] = 1;
    for (int q = head[x]; q != 0; q = nxt[q]) {
        int y = e[q];
        if (y == fa)
            continue;
        dfs(y, x);
        ans += (ll)min(k, sum[y]) * l[q];
        sum[x] += sum[y];
    }
    return 0;
}

int main() {
    while (~scanf("%d%d", &n, &k)) {
        memset(head, 0, sizeof(head));
        memset(nxt, 0, sizeof(nxt));
        for (i = 1; i < n; ++i) {
            scanf("%d%d%lld", &x, &y, &la);
            add(i * 2 - 1, x, y, la);
            add(i * 2, y, x, la);
        }
        ans = 0;
        memset(sum, 0, sizeof(sum));
        dfs(1, 0);
        printf("%lld\n", ans);
    }    
    return 0;
}