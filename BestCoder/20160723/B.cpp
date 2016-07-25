#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

int q[100010];
int ans[100010];
int a[100010];
int t, n, i;

inline int find(int l, int r, int x) {
    if (l ==  r)
        return l;
    int mid = (l + r + 1) / 2;
    if (q[mid] < x)
        return find(mid, r, x);
    return find(l, mid-1, x);
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (i = 1; i <= n; ++i) {
            q[i] = 1e9 + 1;
            scanf("%d", &a[i]);
            ans[i] = 0;
        }
        ans[0] = 0;
        q[0] = 0;

        for (i = 1; i <= n; ++i) {
            ans[i] = find(0, n, a[i]) + 1;
            q[ans[i]] = min(q[ans[i]], a[i]);
        }

        for (i = 1; i < n; ++i)
            printf("%d ", ans[i]);
        printf("%d\n", ans[n]);
    }
    return 0;
}