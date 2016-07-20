#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

const int N = 100010;

int sa[4 * N];
int sb[4 * N];
int a[N];
int b[N];
int n, i, x, y, z, m ,op, ans;


inline void pushdown(int now) {
    int lc = now * 2;
    int rc = now * 2 + 1;
    sa[lc] = sa[now]; sb[lc] = sb[now];
    sa[rc] = sa[now]; sb[rc] = sb[now];
    sa[now] = 0;
    sb[now] = 0;
    return ;
}

inline int find(int now, int l, int r, int x) {
    if (l == r) {
        if (sa[now] == 0) {
            return b[l];
        }
        return a[l - sb[now] + sa[now]];
    }
    if (sa[now] != 0) pushdown(now);
    int mid = (l + r) >> 1;
    int lc = now * 2;
    int rc = now * 2 + 1;
    if (x <= mid)
        return find(lc, l, mid, x);
    else
        return find(rc, mid+1, r, x);
}

inline void change(int now, int l, int r, int ll, int rr) {
    if (l == r) {
        sa[now] = x;
        sb[now] = y;
        return;
    }
    if (sa[now] != 0) pushdown(now);
    if (ll <= l && r <= rr) {
        sa[now] = x;
        sb[now] = y;
        return;
    }
    int mid = (l + r) >> 1;
    int lc = now * 2;
    int rc = now * 2 + 1;
    if (ll <= mid)
        change(lc, l, mid, ll, rr);
    if (mid < rr)
        change(rc, mid+1, r, ll, rr);
    return;
}

int main() {
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (i = 1; i <= n; ++i)
        scanf("%d", &b[i]);
    memset(sa, 0, sizeof(sa));
    memset(sb, 0, sizeof(sb));
    for (i = 1; i <= m; ++i) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d%d%d", &x, &y, &z);
            change(1, 1, n, y, y+z-1);
        } else {
            scanf("%d", &x);
            ans = find(1, 1, n, x);
            printf("%d\n", ans);
        }
    }
    return 0;
}
