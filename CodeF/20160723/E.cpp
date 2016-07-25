#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

const int nn = 200010;

int head[nn], e[nn*2], nxt[nn*2];
int son[nn], t[nn];
int a[nn];
int x, y, n, m, i, ans, size, k; 
long long aa;

int dfs(int x) {
    son[x] = a[x];
    t[x] = 1;
    int tmp = 0;
    for (int k = head[x]; k != 0; k = nxt[k]) {
        int y = e[k];
        if (t[y] == 0) {
            dfs(y);
            son[x] += son[y];
            tmp = max(tmp, son[y]);
        }
    }
    tmp = max(tmp, m - son[x]);
    if (tmp < size) {
        ans = x;
        size = tmp;
    }
    return 0;
}


int dfs2(int x) {
    son[x] = a[x];
    t[x] = 1;
    int tmp = 0;
    for (int k = head[x]; k != 0; k = nxt[k]) {
        int y = e[k];
        if (t[y] == 0) {
            dfs2(y);
            son[x] += son[y];
            aa = aa + (long long)son[y];
        }
    }
    return 0;
}

int main() {
    scanf("%d%d", &n, &m);
    m = 2 * m;
    for (i = 1; i <= m; ++i) {
        scanf("%d", &k);
        a[k] = 1;
    }
    for (i = 1; i < n; ++i) {
        scanf("%d%d", &x, &y);
        e[i*2-1] = y;
        nxt[i*2-1] = head[x];
        head[x] = i*2-1;
        e[i*2] = x;
        nxt[i*2] = head[y];
        head[y] = i*2;
    }
    size = n+1; ans = 1;
    memset(son, 0, sizeof(son));
    memset(t, 0, sizeof(t));
    dfs(1);
    memset(son, 0, sizeof(son));
    memset(t, 0, sizeof(t));
    aa = 0;
    dfs2(ans);
    printf("%I64d\n", aa);
    return 0;
}