#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

int t[400010];
int p[400010];
int a[400010];
int i, j, k, pt, m, s, T;
long long ans, n;

inline long long f(long long n) {
    memset(a, 0, sizeof(a));
    ans = 1;
    while (ans <= n / 2) {
        i = 1;
        while (i <= pt && ans <= n / p[i]) {
            ans *= p[i];
            ++a[i];
            ++i;
        }
    }
    return ans;
}

int main() {
    memset(t, 0, sizeof(t));
    pt = 0;
    for (i = 2; i < 400000; ++i) {
        if (t[i] == 0) {
            ++pt; p[pt] = i;
            for (j = 2 * i; j < 400000; j = j + i) {
                t[j] = 1;
            }
        }
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%lld", &n);
        printf("%lld ", f(n));
        ans = 1;
        for (i = 1; i <= pt; ++i)
            ans = ans * (1 + a[i]);
        printf("%lld\n", ans);
    }
    return 0;
}