#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

struct Point {
    ll x, y, id;
    ll operator * (const Point & b) const {
        return x * b.y - y * b.x;
    }
    Point operator - (const Point & b) const {
        Point c;
        c.x = x - b.x;
        c.y = y - b.y;
        return c;
    }
};

int T, n, i, m, j, k;
Point a[200];
Point ch[400];
int ans[200];

bool cmp(const Point &a, const Point &b) {
    if (a.x == b.x)
        return a.y < b.y;
    return  a.x < b.x;
}

inline bool work() {
    memset(ans, 0, sizeof(ans));
    for (i = 0; i < n; ++i)
        for (j = i+1; j < n; ++j)
            for (k = j + 1; k < n; ++k)
                if ((a[i] - a[j]) * (a[k] - a[j]) == 0) {
                    ans[a[i].id] = 1;
                    ans[a[j].id] = 0;
                    ans[a[k].id] = 1;
                    puts("YES");
                    for (i = 0; i < n; ++i)
                        putchar(ans[i] == 0 ? 'A' : 'B');
                    putchar('\n');
                    return 0;
                }
    if (n <= 3) {
        puts("NO");
        return 0;
    }

    memset(ans, 0, sizeof(ans));
    m = 0;
    for (i = 0; i < n; ++i) {
        while (m > 1 && (ch[m-1] - ch[m-2]) * (a[i] - ch[m-2]) < 0)
            m--;
        ch[m++] = a[i];
    }
    int k = m;
    for (i = n-2; i >= 0; --i) {
        while (m > k && (ch[m-1] - ch[m-2]) * (a[i] - ch[m-2]) < 0)
            m--;
        ch[m++] = a[i];
    }
    m--;
    if (n == m) {
        for (i = 0; i < m; ++i)
            ans[ch[i].id] = i % 2;
    } else {
        for (i = 0; i < m; ++i)
            ans[ch[i].id] = 1;
    }
    puts("YES");
    for (i = 0; i < n; ++i)
        putchar(ans[i] == 0 ? 'A' : 'B');
    putchar('\n');
    return 0;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (i = 0; i < n; ++i) {
            scanf("%lld%lld", &a[i].x, &a[i].y);
            a[i].id = i;
        }
        sort(a, a+n, cmp);
        work();
    }
    return 0;
}