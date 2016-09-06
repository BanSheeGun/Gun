#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[70];
ll b[70];
ll l, r, ans, t1, t2, i;
int n;

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%lld%lld", &r, &l);
        if (l == r) {
            printf("%lld\n", l);
            continue;
        }
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        t1 = 0;
        while (l != 0) {
            ++t1;
            a[t1] = l % 2;
            l = l / 2;
        }
        t2 = 0;
        while (r != 0) {
            ++t2;
            b[t2] = r % 2;
            r = r / 2;
        }

        for (i = t1; i >= 1; --i) {
            if (a[i] != b[i]) {
                t2 = i;
                break;
            }
        }
        ans = 1;
        for (i = t2; i >= 1; --i)
            if (a[i] == 0) ans = 0;
        if (ans != 1) {
            a[t2] = 0;
            for (i = 1; i < t2; ++i)
                a[i] = 1;
        }

        t2 = 1;ans = 0;
        for (i = 1; i <= t1; ++i) {
            ans += a[i] * t2;
            t2 *= 2;
        }
        printf("%lld\n", ans);
    }
    return 0;
}