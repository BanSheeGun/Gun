#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

struct P {
    int l, r;
} a[100010];

inline bool cmp(const P & a, const P & b) {
    return a.l < b.l;
}

int n, m, now, ans, l, r, i, tm;

int main() {
    while (~scanf("%d%d", &n, &m)) {
        for (i = 1; i <= n; ++i)
            scanf("%d%d", &a[i].l, &a[i].r);
        sort(a+1, a+1+n, cmp);
        tm = n;
        n = 0;
        for (i = 1; i <= tm; ++i) {
            if (i != 1 && a[i].l <= a[n].r) {
                a[n].r = max(a[n].r, a[i].r);
            } else {
                a[++n].l = a[i].l;
                a[n].r = a[i].r;
            }
        }
        l = 1;
        now = 0;
        ans = 0;
        for (i = 1; i <= n; ++i) {
            if (i != 1)
                now += a[i].l - a[i-1].r - 1;
            while (i != 1 && now > m) {
                now -= a[l+1].l - a[l].r - 1;
                ++l;
            }
            ans = max(ans, a[i].r - a[l].l + 1 + m - now);
        }
        printf("%d\n", ans);
    }
    return 0;
}