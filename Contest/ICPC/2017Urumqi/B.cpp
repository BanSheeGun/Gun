#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

struct Point {
    ll x, y;

    Point operator - (const Point & B) const {
        Point C;
        C.x = x - B.x;
        C.y = y - B.y;
        return C;
    }

    ll operator * (const Point & B) const {
        ll tmp = x * B.y - y * B.x;
        if (tmp > 0)
            return 1;
        if (tmp < 0)
            return -1;
        return 0;
    }
};

int T, cnt;
ll i;
bool OK;
Point a[4], b[4], d, dd;

inline bool check(Point * a, Point X, Point d) {
    int i;
    ll tmp;
    for (i = 0; i <= 2; ++i) {
        Point x = a[i] - X;
        Point y = a[(i+1) % 3] - X;
        tmp = (x * d) * (y * d);
        if (tmp > 0)
            continue;
        tmp = (d * x) * (y * x);
        if (tmp < 0)
            continue;
        tmp = (d * y) * (x * y);
        if (tmp < 0)
            continue;
        return 1;
    }
    return 0;
}

inline bool inTri(Point * a, Point b) {
    int b0 = 0, b1 = 0;
    for (int i = 0; i <= 2; ++i) {
        int tmp = (b - a[i]) * (a[(i+1)%3] - a[i]);
        if (tmp < 0) ++b0;
        if (tmp > 0) ++b1;
    }
    if (b0 == 0 || b1 == 0)
        return 1;
    return 0;
}

inline bool panjiao(Point a, Point b, Point c, Point d) {
    ll tmp1 = ((c - a) * (b - a)) * ((d - a) * (b - a));
    if (tmp1 > 0)
        return 0;
    tmp1 = ((a - c) * (d - c)) * ((b - c) * (d - c));
    if (tmp1 > 0)
        return 0;
    return 1;
}

int main() {
    scanf("%d", &T);
    cnt = 0;
    while (T--) {
        printf("Case #%d: ", ++cnt);
        for (i = 0; i <= 2; ++i)
            scanf("%lld%lld", &a[i].x, &a[i].y);
        scanf("%lld%lld", &dd.x, &dd.y);
        for (i = 0; i <= 2; ++i)
            scanf("%lld%lld", &b[i].x, &b[i].y);
        scanf("%lld%lld", &d.x, &d.y);
        OK = 0;
        for (i = 0; i <= 2; ++i) {
            if (inTri(a, b[i]))
                OK = 1;
            if (inTri(b, a[i]))
                OK = 1;
        }
            if (panjiao(a[0], a[1], b[0], b[1]))
                OK = 1;
            if (panjiao(a[0], a[1], b[0], b[2]))
                OK = 1;
            if (panjiao(a[0], a[1], b[2], b[1]))
                OK = 1;
            if (panjiao(a[0], a[2], b[0], b[1]))
                OK = 1;
            if (panjiao(a[0], a[2], b[0], b[2]))
                OK = 1;
            if (panjiao(a[0], a[2], b[2], b[1]))
                OK = 1;
            if (panjiao(a[2], a[1], b[0], b[1]))
                OK = 1;
            if (panjiao(a[2], a[1], b[0], b[2]))
                OK = 1;
            if (panjiao(a[2], a[1], b[2], b[1]))
                OK = 1;

        if (!(d.x == dd.x && d.y == dd.y) && OK == 0) {
            for (i = 0; i <= 2; ++i)
                if (check(a, b[i], d - dd))
                    OK = 1;
            for (i = 0; i <= 2; ++i)
                if (check(b, a[i], dd - d))
                    OK = 1;
        }
        if (OK)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}