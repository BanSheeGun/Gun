#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int x, xx, y, yy, a, n;
double ans, t;

int main() {
    scanf("%d%d", &x, &y);
    scanf("%d", &n);
    ans = 100000000;
    while (n--) {
        scanf("%d%d%d", &xx, &yy, &a);
        t = (x - xx) * (x - xx) + (y - yy) * (y - yy);
        t = sqrt(t) / a;
        ans = min(ans, t);
    }
    printf("%lf\n", ans);
    return 0;
}