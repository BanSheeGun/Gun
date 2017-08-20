#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

struct Point {
    ll x, y;

    Point operator + (const Point & b) {
        Point c;
        c.x = b.x + x;
        c.y = b.y + y;
        return c;
    }

    Point operator - (const Point & b) {
        Point c;
        c.x = x - b.x;
        c.y = y - b.y;
        return c;
    }

    ll operator * (const Point & b) {
        return x * b.y - y * b.x; 
    }
} a[1000010];

struct Line {
    Point a, b;
};

inline bool cross(Line a, Line b) {
    ll x = 1, y = 1;
    ll tmp1 = (a.a - a.b) * (b.a - a.b);
    ll tmp2 = (a.a - a.b) * (b.b - a.b);
    if (tmp1 == 0 || tmp2 == 0)
        x = 0;
    else {
        tmp1 = tmp1 / abs(tmp1);
        tmp2 = tmp2 / abs(tmp2);
        x = tmp2 * tmp1;
    }
    if (x > 0)
        return 0;
    tmp1 = (b.a - b.b) * (a.a - b.b);
    tmp2 = (b.a - b.b) * (a.b - b.b);
    if (tmp1 == 0 || tmp2 == 0)
        y = 0;
    else {
        tmp1 = tmp1 / abs(tmp1);
        tmp2 = tmp2 / abs(tmp2);
        y = tmp2 * tmp1;
    }
    if (y > 0)
        return 0;
    return 1;
}

int T, n, k, ans, i;
Line b[10];

inline bool pan() {
    if (i >= 4)
        if (cross(b[0], b[3]))
            return 1;
    if (i >= 6)
    if (cross(b[0], b[5]))
        return 1;
    return 0;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        a[0].x = 0;
        a[0].y = 0;
        b[1].a = a[0];
        b[1].b = a[0];
        b[2] = b[1];
        b[3] = b[1];
        b[4] = b[1];
        b[5] = b[1];
        ans = 0;
        for (i = 1; i <= n; ++i) {
            scanf("%d", &k);
            a[i] = a[i-1];
            switch (i % 4) {
                case 1 : a[i].y += k; break;
                case 2 : a[i].x -= k; break;
                case 3 : a[i].y -= k; break;
                default : a[i].x += k; break;
            };
        }

        b[1].a = a[1];
        for (i = 2; i <= n; ++i) {
            b[0].a = a[i];
            b[0].b = a[i-1];
            if (pan()) {
                ans = i; 
                break;
            }
            b[5] = b[4];
            b[4] = b[3];
            b[3] = b[2];
            b[2] = b[1];
            b[1] = b[0];
        }

        if (ans == 0)
            puts("Catch you");
        else
            printf("%d\n", ans);
    }
    return 0;
}