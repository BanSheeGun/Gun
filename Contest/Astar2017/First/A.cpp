#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

struct Point {
    ll x, y;

    Point operator - (Point b) {
        Point c;
        c.x = x - b.x;
        c.y = y - b.y;
        return c;
    }

    ll operator * (Point b) {
        return x * b.y - y * b.x;
    }
};

inline bool cmp(const Point & a, const Point & b) {
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

Point a[2100];
Point b[2100];
int f[2100][2100];
bool p[2100][2100];
ll n, m, i, j, l, ans, OK, k;

inline bool pan(Point x, Point y) {
    ll i;
    Point z = y - x;
    for (i = 1; i <= m; ++i) {
        Point tmp = b[i] - x;
        if (z * tmp < 0)
            return 0;
    }
    return 1;
}

inline ll check(int l, int r) {
    ll i;
    if (l == r)
        return 0;
    for (i = 1; i <= n; ++i)
        if (l != i && r != i)
            if ((a[l] - a[r]) * (a[l] - a[i]) != 0)
                return 1;
    return 0;
}

int main() {
    while (~scanf("%lld", &m)) {
        for (i = 1; i <= m; ++i)
            scanf("%lld%lld", &b[i].x, &b[i].y);
        scanf("%lld", &n);
        for (i = 1; i <= n; ++i)
            scanf("%lld%lld", &a[i].x, &a[i].y);
        sort(a+1, a+1+n, cmp);
        memset(p, 0, sizeof(p));
        for (i = 1; i <= n; ++i)
            for (j = 1; j <= n; ++j)
                f[i][j] = n+1;

        for (l = 2; l <= n; ++l) {
            for (i = 1; i + l - 1 <= n; ++i) {
                j = i+l-1;
                if (pan(a[i], a[j])) {
                    p[i][j] = 1;
                    f[i][j] = 2;
                    continue;
                }
                for (k = i+1; k < j; ++k)
                    if (p[i][k] && p[k][j]) {
                        p[i][j] = 1;
                        f[i][j] = min(f[i][j], f[i][k] + f[k][j] - 1);
                    }
            }

            for (i = n; i - l + 1 > 0; --i) {
                j = i-l+1;
                if (pan(a[i], a[j])) {
                    p[i][j] = 1;
                    f[i][j] = 2;
                    continue;
                }
                for (k = i-1; k > j; --k)
                    if (p[i][k] && p[k][j]) {
                        p[i][j] = 1;
                        f[i][j] = min(f[i][j], f[i][k] + f[k][j] - 1);
                    }
            }
        }

        ans = 0;
        OK = 0;
        for (i = 1; i <= n; ++i)
            for (j = 1; j <= n; ++j)
                if (p[i][j] && p[j][i] && check(i, j)) {
                    OK = 1;
                    ans = max(ans, n - f[i][j] - f[j][i] + 2);
                }
        if ((n - ans) == 2)
            --ans;
        if (OK)
            printf("%lld\n", ans);
        else
            puts("ToT");
    }    
    return 0;
}