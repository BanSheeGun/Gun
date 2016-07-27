#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int n, i;
double ans, a[10000];

int main() {
    while (~scanf("%d", &n)) {
        for (i = 1; i <= n; ++i) {
            scanf("%lf", &a[i]);
        }
        if (i == 1) {
            printf("%lf\n", a[i]);
            continue;
        }

        ans = (a[1] + a[n]) / 2;
        for (i = 2; i <= n-1; ++i)
            ans += a[i] / 3;
        printf("%lf\n", ans);
    }
    return 0;
}