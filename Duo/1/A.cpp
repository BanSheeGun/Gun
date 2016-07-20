#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

struct Line {
    int x, y;
    long long k;
};

bool cmp(Line a, Line b) {
    return a.k < b.k;
}

Line a[1000010];
int f[100010];
int tt, ttt, i, m, now, fx, fy;
long long ans, n;
int head[100010];
int nxt[200010];
int e[200010];
long long v[200010];
long long sum[100010];
bool t[100010];
double aa;

int find(int x) {
    if (f[x] != x)
        f[x] = find(f[x]);
    return f[x];
}

int dfs(int x, int fa) {
    sum[x] = 1;
    t[x] = 1;
    for (int k = head[x]; k != 0; k = nxt[k]) {
        int y = e[k];
        if (t[y] == 0 && y != fa) {
            dfs(y, x);
            sum[x] += sum[y];
        }
    }
    return 0;
}

int dfs1(int x, int fa) {
    t[x] = 1;
    for (int k = head[x]; k != 0; k = nxt[k]) {
        int y = e[k];
        if (t[y] == 0 && y != fa) {
            dfs1(y, x);
            aa += (n - sum[y]) * sum[y] * v[k];
        }
    }
    return 0;
}

int main() {
    scanf("%d", &tt);
    for (ttt = 1; ttt <= tt; ++ttt) {
        scanf("%I64d%d", &n, &m);
        for (i = 1; i <= m; ++i) {
            scanf("%d%d%I64d", &a[i].x, &a[i].y, &a[i].k);
        }
        sort(a+1, a+1+m, cmp);
        for (i = 1; i <= n; ++i) {
            f[i] = i;
        }
        
        memset(nxt, 0, sizeof(nxt));
        memset(head, 0 , sizeof(head));
        now = 1;
        ans = 0;
        i = 0;
        while (now < n) {
            ++i;
            fx = find(a[i].x);
            fy = find(a[i].y);
            if (fx != fy) {
                e[now*2-1] = a[i].x;
                nxt[now*2-1] = head[a[i].y];
                head[a[i].y] = now*2 -1;
                e[now*2] = a[i].y;
                nxt[now*2] = head[a[i].x];
                head[a[i].x] = now*2;
                v[now*2] = a[i].k;
                v[now*2-1] = a[i].k;
                ++now;
                ans += a[i].k;
                f[fx] = fy;
            }
        }
        printf("%I64d ", ans);

        aa = 0;
        memset(t, 0, sizeof(t));
        memset(sum, 0, sizeof(sum));
        dfs(1, 0);
        memset(t, 0, sizeof(t));
        dfs1(1, 0);
        aa = aa * 2;
        aa /= (n * (n-1));
        printf("%.2lf\n", aa);
    }
    return 0;
}