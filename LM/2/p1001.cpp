#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long ll;
struct Point {
    ll x, y;
    Point () {x = 0; y = 0;}
    inline Point operator - (const Point b) const {
        Point c;
        c.x = x - b.x;
        c.y = y - b.y;
        return c;
    } 
    
    inline ll operator * (const Point b) const {
        return x * b.y - y * b.x;
    }

    inline ll operator ^ (const Point b) const {\
        return x * b.x + y * b.y;
    }

};

bool cmp(Point a, Point b) {
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

int T, n, i, m, k;
Point a[110], t1, t2;
Point ch[110];
ll l, c, ans;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (i = 1; i <= n; ++i)
            scanf("%lld%lld", &a[i].x, &a[i].y);
        sort(a+1, a+1+n, cmp);
        m = 0;
        for (i = 1; i <= n; ++i) {
            while (m > 1 && (ch[m-1] - ch[m-2]) * (a[i] - ch[m-2]) <= 0) m--;
            ch[m++] = a[i];
        }
        k = m;
        for (i = n-1; i >= 1; --i) {
            while (m > k && (ch[m-1] - ch[m-2]) * (a[i] - ch[m-2]) <= 0) m--;
            ch[m++] = a[i];
        }
        if (n > 1) m--;
        ch[m+1] = ch[1];
        t1 = ch[2] - ch[1]; t2 = ch[1] - ch[m];
        c = t1 ^ t2; l = t1.x * t1.x + t1.y * t1.y;
        ans = 1;
        if (n != m) ans = 0;
        for (i = 1; i <= m; ++i) {
            t1 = ch[i+1] - ch[i];
            if (l != (t1.x * t1.x + t1.y * t1.y))
                ans = 0;
            if ((t1 ^ t2) != c)
                ans = 0;
            t2 = t1;
        } 
        if (ans)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}