#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;


const int N = 1000010;

int a[N], d[N], b[N];
int nxt[N*2], e[N*2], head[N];
int ans[N];
int t[N];
int n, m, i, l, j, x, y;

bool cmp1(int a, int b) {
    return a < b;
}

bool cmp2(int a, int b) {
    return a > b;
}

int dfs(int x) {
    ++l;
    t[x] = 1;
    d[l] = x;
    b[l] = a[x];
    for (int k = head[x]; k != 0; k = nxt[k]) {
        int y = e[k];
        if (t[y] == 0) {
            dfs(y);
        }
    }
    return 0;
}

int main() {
    scanf("%d%d", &n, &m);
    for (i = 1;  i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    memset(head, 0, sizeof(head));
    memset(nxt, 0, sizeof(nxt));
    for (i = 1; i <= m; ++i) {
        scanf("%d%d", &x, &y);
        e[i*2-1] = x;
        nxt[i*2-1] = head[y];
        head[y] = i*2-1;
        e[i*2] = y;
        nxt[i*2] = head[x];
        head[x] = i*2;
    }

    memset(t, 0 ,sizeof(t));
    for (i = 1; i <= n; ++i)
        if (t[i] == 0) {
            l = 0;
            dfs(i);
            sort(d+1, d+1+l, cmp1);
            sort(b+1, b+1+l, cmp2);
            for (j = 1; j <= l; ++j)
                ans[d[j]] = b[j];
        }

    for (i = 1; i < n; ++ i)
        printf("%d ", ans[i]);
    printf("%d\n", ans[n]);
    return 0;
}