#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

double a[1010];
double b[1010];
double d[1010];
int n ,i ,k;
double ans, eps = 0.000001;

bool cmp(double a, double b) {
    return a > b;
}

double solve() {
    double t, l, r, mid;
    l = 0;
    r = 1000;
    do {
        t = 0;
        mid = (l + r) / 2;
        for (int i = 0;i < n; ++i)
            d[i] = a[i] - mid * b[i];
        sort(d, d + n, cmp);
        for (int i = 0; i < n-k; ++i)
            t += d[i];
        if (t > 0) {
            l = mid;
        } else {
            r = mid;
        }
    } while (l + eps < r);
    return l;
}

int main() {
    scanf("%d%d", &n, &k);
    while (n != 0 || k != 0) {
        for (i = 0;i < n; ++i)
            scanf("%lf", &a[i]);
        for (i = 0;i < n; ++i)
            scanf("%lf", &b[i]);

        ans = solve() * 100;
        printf("%.0f\n", ans);
        scanf("%d%d", &n, &k);
    }
    return 0;
}
