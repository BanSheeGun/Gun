#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

struct P {
    ll x, y, z;
};

inline ll ca(P a, P b) {
    return a.x * b.y - a.y * b.x;
}

inline int xiangxian(P a) {
    if (a.y >= 0 && a.x > 0)
        return 1;
    if (a.y > 0 && a.x <= 0)
        return 2;
    if (a.y <= 0 && a.x < 0)
        return 3;
    return 4;
}

inline bool cmp(const P & a, const P & b) {
    int xa = xiangxian(a);
    int xb = xiangxian(b);
    if (xa != xb)
        return xa < xb;
    return ca(a, b) > 0;
}

P a[100010];
ll s[100010];
ll sum, tmp, ans;
int T, i, n, r;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (i = 1; i <= n; ++i) {
            scanf("%lld%lld%lld", &a[i].x, &a[i].y, &a[i].z);
        }
        sort(a+1, a+1+n, cmp);
        s[0] = 0;
        for (i = 1; i <= n; ++i)
            a[i+n] = a[i];
        for (i = 1; i <= 2 * n; ++i)
            s[i] = s[i-1] + a[(i-1) % n + 1].z;
        sum = s[n] - s[0];
        r = 0;
        ans = 0;
        a[0] = a[n];
        while (ca(a[0], a[r+1]) > 0)
            ++r;
        for (i = 1; i <= n; ++i) {
            do {
                tmp = s[r] - s[i-1];
                ans = max(ans, tmp * (sum - tmp));
                ++r;
            } while (ca(a[i], a[r]) > 0);
            --r;
        }
        printf("%lld\n", ans);
    }
    return 0;
}