#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int tt,ttt;

struct line {
    int x, y, w;
}a[12010];

bool cmp (line a, line b) {
    return a.w < b.w;
}

bool cmp2 (line a, line b) {
    return a.w > b.w;
}

int f[110];
int ans, t, i, n, m, x, y, w,fx, fy;

int find(int x) {
    if (f[x] != x)
        f[x] = find(f[x]);
    return f[x];
}

int gcd(int a, int b) {
    if (b == 0) return 0;
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}

int main() {
    scanf("%d",&tt);
    for (ttt = 1;ttt <= tt; ++ttt) {
        printf("Case %d: ",ttt);
        scanf("%d", &n);
        m = 0;
        scanf("%d%d%d", &x, &y, &w);
        while (!(x == 0 && y == 0 && w == 0)) {
            ++m;
            a[m].x = x;
            a[m].y = y;
            a[m].w = w;
            scanf("%d%d%d", &x, &y, &w);
        }
        sort(a+1, a+1+m, cmp);

        t = 0;
        ans = 0;

        for (i = 0; i <= n; ++i)
            f[i] = i;
        for (i = 1; i <= m; ++i) {
            fx = find(a[i].x);
            fy = find(a[i].y);
            if (fx != fy) {
                ans += a[i].w;
                f[fx] = fy;
            }
        }

        sort(a+1, a+1+m, cmp2);
        for (i = 0; i <= n; ++i)
            f[i] = i;
        for (i = 1; i <= m; ++i) {
            fx = find(a[i].x);
            fy = find(a[i].y);
            if (fx != fy) {
                ans += a[i].w;
                f[fx] = fy;
            }
        }

        n = 2;
        t = gcd(n, ans);
        if (ans == 0)
            printf("%d\n", 0);
        else {
            n /= t;
            ans /= t;
            if (n != 1)
                printf("%d/%d\n",ans, n);
            else
                printf("%d\n",ans);
        }
    }
    return 0;
}
