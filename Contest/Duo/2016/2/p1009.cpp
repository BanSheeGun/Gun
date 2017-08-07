#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

int a[200];
int n, i, m, x, y, s1, s2, s,t;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    scanf("%d", &t);
    while (t--) {
        memset(a, 0 ,sizeof(a));
        scanf("%d%d", &n, &m);
        for (i = 1; i <= m; ++i) {
            scanf("%d%d", &x, &y);
            a[x] = y;
        }

        if (a[1] == 0) a[1] = 100;
        if (a[2] == 0) a[2] = a[1];

        for (i = n; i > 2; --i)
            if (a[i] == 0)
                a[i] = a[i+1];

        s1 = a[1] + a[2];
        s2 = 0;
        for (i = 1; i <= n; ++i)
            s2 += a[i];
        s = gcd(s1, s2);
        printf("%d/%d\n", s1/s, s2/s);
    }
    return 0;
}