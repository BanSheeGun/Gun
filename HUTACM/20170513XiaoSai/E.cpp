#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;

struct point {
    int id;
    double x;
};

point a[100010];
point b[100010];

inline bool cmp(point a, point b) {
    return a.x < b.x;
}

inline double dis(double a, double b, double c, double d) {
    return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}

int n, i, j;
double tmp, ans, t, ax, bx, cx, ay, by, cy, x, y;

int main() {
    while (~scanf("%lf%lf%lf%lf%lf%lf", &ax, &ay, &bx, &by, &cx, &cy)) {
        scanf("%d", &n);
        ans = 0;
        for (i = 1; i <= n; ++i) {
            scanf("%lf%lf", &x, &y);
            a[i].id = i;
            a[i].x = dis(ax, ay, x, y) - dis(cx, cy, x, y);
            b[i].id = i;
            b[i].x = dis(bx, by, x, y) - dis(cx, cy, x, y);
            ans += (dis(x, y, cx, cy)) * 2;
        }
        a[0].id = 0;
        a[0].x = 0;
        b[0].x = 0;
        b[0].id = 0;
        tmp = 999999999;
        sort(a, a+1+n, cmp);
        sort(b, b+1+n, cmp);
        for (i = 0; i <= n; ++i) {
            j = 0;
            while (b[j].id == a[i].id)
                ++j;
            t = a[i].x + b[j].x;
            tmp = min(tmp, t);
        }
        ans += tmp;
        printf("%.5f\n", ans);
    }
    return 0; 
}