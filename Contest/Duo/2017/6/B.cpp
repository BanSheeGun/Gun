#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

int T;
double R, xx1, xx2, yy1, yy2, ans;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%lf", &R);
        scanf("%lf%lf", &xx1, &yy1);
        scanf("%lf%lf", &xx2, &yy2);
        double c = (xx1 - xx2) * (xx1 - xx2) + (yy1 - yy2) * (yy1 - yy2);
        c = sqrt(c) / 2;
        double xmid = (xx1 + xx2) / 2;
        double ymid = (yy1 + yy2) / 2;
        double tt = sqrt(xmid * xmid + ymid * ymid);
        double a = R / sqrt(1 + tt * tt / c / c);
        double b = tt * a * a / c / c;
        if (b <= R)
            printf("%.10lf\n", 2.0 * a);
        else
            printf("%.10lf\n", 2.0 * sqrt((R - tt )* (R - tt) + c * c));
    }
    return 0;
}