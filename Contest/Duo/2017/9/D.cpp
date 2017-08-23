#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

const double eps = 1e-12;
const double MIN = 1e-4;

struct Point {
    double x, y;

    Point operator - (const Point & a) const {
        return (Point) {
            (x - a.x),
            (y - a.y)
        };
    }

    Point operator + (const Point & a) const {
        return (Point) {
            (x + a.x),
            (y + a.y)
        };
    }

    double operator * (const Point & a) const  {
        return x * a.y - y * a.x;
    }
};

struct Line {
    Point q, w;
    double a, b, c, k;

    inline void fresh() {
        a = q.y - w.y;
        b = w.x - q.x;
        c = w.y * q.x - q.y * w.x;
    }

    inline void rev(const Line & n) {
        double tmp = n.a * q.x + n.b * q.y + n.c;
        tmp /= n.a * n.a + n.b * n.b;
        q.x = q.x - 2 * n.a * tmp;
        q.y = q.y - 2 * n.b * tmp;
        tmp = n.a * w.x + n.b * w.y + n.c;
        tmp /= n.a * n.a + n.b * n.b;
        w.x = w.x - 2 * n.a * tmp;
        w.y = w.y - 2 * n.b * tmp;
        fresh();
    }
} l[1010];
 
int n, i, ans, la;
Point v;
Line now;
double k, x, y;

inline bool pan(int i) {
    Point x = l[i].q - now.q;
    Point y = l[i].w - now.q;
    Point v = now.w - now.q;
    double tmp;
    tmp = (v * x) * (v * y);
    if (tmp > eps)
        return 0;
    tmp = (x * v) * (x * y);
    if (tmp < -eps)
        return 0;
    tmp = (y * v) * (y * x);
    if (tmp < -eps)
        return 0;
    return 1;
}

inline bool pans(int i) {
    Point x = l[i].q - now.q;
    Point y = l[i].w - now.q;
    Point v = now.w - now.q;
    double tmp;
    tmp = v * x;
    if (fabs(tmp) < eps)
        return 1;
    tmp = v * y;
    if (fabs(tmp) < eps)
        return 1;
    return 0;
}

int main() {
    while (~scanf("%d", &n)) {
        for (i = 1; i <= n; ++i) {
            scanf("%lf%lf%lf", &x, &y, &l[i].k);
            l[i].q.x = x;
            l[i].q.y = y;
        }
        l[n].w = l[1].q;
        for (i = 1; i < n; ++i)
            l[i].w = l[i + 1].q;
        for (i = 1; i <= n; ++i)
            l[i].fresh();

        scanf("%lf%lf", &v.x, &v.y);
        now.q.x = 0;
        now.q.y = 0;
        now.w = v;
        now.fresh();
        ans = 0;
        k = 1;
        la = 0;
        while (k >= MIN) {
            for (i = 1; i <= n; ++i)
                if (i != la && pan(i)) {
                    ++ans;
                    k *= l[i].k;
                    la = i;
                    if (pans(i))
                        la = n+1;
                    break;
                }
            if (la == n + 1)
                break;
            now.rev(l[la]);
        }

        printf("%d\n", ans);
    }
    return 0;
}