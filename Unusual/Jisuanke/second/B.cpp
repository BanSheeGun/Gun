#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int n, m, x, y, dex, dey, xa, xb, ya, yb, i, q;
int a[300][300];

int main() {
    memset(a, 0, sizeof(a));
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; ++i) {
        scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
        dex = xa - xb;
        dey = ya - yb;
        if (dex < 0)
            dex = -dex;
        if (dey < 0)
            dey = -dey;
        if (dey == 0)
            dex = 1;
        else
            if (dex == 0)
                dey = 1;
            else {
                int tmp = gcd(dex, dey);
                dex /= tmp;
                dey /= tmp;
            }
        if (xa - xb < 0)
            dex = -dex;
        if (ya - yb < 0)
            dey = -dey;
        x = xb; y = yb;
        a[x][y] = i;
        while (x != xa) {
            x += dex;
            y += dey;
            a[x][y] = i;
        }
    }
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d", &x, &y);
        printf("%d\n", a[x][y]);
    }
    return 0; 
}