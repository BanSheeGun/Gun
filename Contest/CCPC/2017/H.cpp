#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

const double pi = atan(1.0) * 4.0;
const double eps = 1e-7;
int T, n, i, r1, r2;
double N, R, x, y, ans, tmp;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &r1, &r2);
        if (r1 > r2)
            swap(r1, r2);
        ans = pi * (r2 - r1) * (r2 - r1);
        double r = (r1 * 1.0) / r2;
        scanf("%d", &n);
        for (i = 2; i <= n; ++i) {
            N = (int)i / 2;
            R = r * (1 - r) / ((1 - r) * (1 - r) * N  * N + r) * r2;
            tmp = pi * R * R;
            if (tmp * (n - i + 1) < eps) break;
            ans += tmp;
        }
        printf("%.5lf\n", ans);
    }
    return 0;
}