#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

int a[1600000];
int ta[1600000];
int b[1600000];
int tb[1600000];

inline int update1(int now, int L, int R, int l, int r, int k) {
    if (L <= l && r <= R) {
        a[now] = min(a[now], k);
        ta[now] = 1;
        return 0;
    }
    if (ta[now] == 1) {
        ta[now*2] = 1; a[now*2] = a[now];
        ta[now*2+1] = 1; a[now*2+1] = a[now];
        ta[now] = 0;
    }
    int mid = (l+r) / 2;
    if (L <= mid)
        update1(now*2, L, R, l, mid, k);
    if (R > mid)
        update1(now*2+1, L, R, mid+1, r, k);
    a[now] = min(a[now*2], a[now*2+1]);
    return 0;
}

inline int update2(int now, int L, int R, int l, int r, int k) {
    if (L <= l && r <= R) {
        b[now] = max(b[now], k);
        tb[now] = 1;
        return 0;
    }
    if (tb[now] == 1) {
        tb[now*2] = 1; b[now*2] = b[now];
        tb[now*2+1] = 1; b[now*2+1] = b[now];
        tb[now] = 0;
    }
    int mid = (l+r) / 2;
    if (L <= mid)
        update2(now*2, L, R, l, mid, k);
    if (R > mid)
        update2(now*2+1, L, R, mid+1, r, k);
    b[now] = max(b[now*2], b[now*2+1]);
    return 0;
}

int n, m, l, r, i;
int c[200010];
int ans[200010];

inline int find(int now, int l, int r) {
    if (l == r) {
        ans[a[now]] += c[l];
        ans[b[now]] -= c[l];
        return 0;
    }
    int mid = (l+r) / 2;
    find(now*2, l, mid);
    find(now*2+1, mid+1, r);
    return 0;
}

int main() {
    while (~scanf("%d%d", &n, &m)) {
        for (i = 1; i < n; ++i) {
            scanf("%d", &c[i]);
        }
        n--;
        memset(a, 0, sizeof(a));
        memset(ta, 0, sizeof(ta));
        memset(b, 0, sizeof(b));
        memset(tb, 0, sizeof(tb));
        a[1] = m+1; b[1] = 0; ta[1] = 1; tb[1] = 1;
        for (i = 1; i <= m; ++i) {
            scanf("%d%d", &l, &r);
            if (l > r) swap(l, r); r -= 1;
            update1(1, l, r, 1, n, i);
            update2(1, l, r, 1, n, i+1);
        }
        memset(ans, 0, sizeof(ans));
        find(1,1,n);
        ans[0] = 0;
        for (i = 1; i <= m; ++i)
            printf("%d ", ans[i]);
        printf("\n");
        for (i = 1; i <= m; ++i)
            ans[i] = ans[i-1] + ans[i];
        for (i = 1; i <= m; ++i)
            printf("%d\n", ans[i]);
    }
    return 0;
}