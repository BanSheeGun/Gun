#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

ll n, m, x, y;
ll a, b, c, d, ans, e, f, a3, a1, a2;

inline ll find(ll dx, ll dy) {
    if (dx == 0 && dy == 0)
        return 1;
    if (dx > 0)
        dx = (n - x) / dx;
    else
        if (dx == 0)
            dx = n;
        else
            dx = (1 - x) / dx;

    if (dy > 0)
        dy = (m - y) / dy;
    else
        if (dy == 0)
            dy = n;
        else
            dy = (1 - y) / dy;

    return min(dx, dy) + 1;
}

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

inline int work() {
    if (a == 0 && b == 0 && c == 0 && d == 0)
        return 1;
    else {
        if (a == 0 && b == 0)
            return a2;
        if (c == 0 && d == 0)
            return a1;
        if (a * d == b * c && a * c >= 0) {
            if (a == 0)
                e = 0;
            else
                e = a * c / gcd(abs(a), abs(c));
            if (b == 0)
                f = 0;
            else
                f = b * d / gcd(abs(b), abs(d));
            if (a < 0)
                e = -e;
            if (b < 0)
                f = -f;
            a3 = find(e, f);
            return a1 + a2 - a3;
        }
        return a1 + a2 - 1;
    }
}

int main() {
    scanf("%lld%lld%lld%lld", &n, &m, &x, &y);
    ans = 0;
    scanf("%lld%lld", &a, &b);
    scanf("%lld%lld", &c, &d);
    a1 = find(a, b);
    a2 = find(c, d);
    ans = work();
    printf("%lld\n", ans);
    return 0;
}