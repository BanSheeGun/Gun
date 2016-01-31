#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int n, p, i, x, y;
double r[100010];
double g[100010];
double ans, a1, a2, r1, g1, c1, c2, c, t1, t2;

int main()
{
    scanf("%d%d",&n,&p);
    for (i = 1;i <=n; ++i) {
        scanf("%d%d",&x,&y);
        r[i] = y - x + 1;
        g[i] = y / p - (x - 1) / p;
    }
    r1 = r[1];
    g1 = g[1];
    r[1] = 1;
    g[1] = 0;
    r[n+1] = r[1];
    g[n+1] = g[1];
    ans = 0;
    for (i = 2;i <= n; ++i) {
        c1 = g[i-1]/r[i-1];
        c2 = g[i+1]/r[i+1];
        c = g[i]/r[i];
        t1 = c * 2000;
        t2 = (1-c) * (c1 + c2) * 1000;
        ans += t1 + t2;
    }
    c1 = g[n]/r[n];
    c2 = g[2]/r[2];
    ans += (c1 + c2) * 1000;
    a1 = ans;
    r[1] = 1;
    g[1] = 1;
    ans = 0;
    r[n+1] = r[1];
    g[n+1] = g[1];
    for (i = 2;i <= n; ++i) {
        c1 = g[i-1]/r[i-1];
        c2 = g[i+1]/r[i+1];
        c = g[i]/r[i];
        t1 = c * 2000;
        t2 = (1-c) * (c1 + c2) * 1000;
        ans += t1 + t2;
    }
    ans += 2000;
    a2 = ans;
    ans = a1 * (1.0 - g1/r1) + a2 *(g1/r1);
    printf("%lf\n",ans);
    return 0;
}
