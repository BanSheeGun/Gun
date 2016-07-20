#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

const int N = 100000;
long long a[N + 10];
long long f[N + 10];
long long t[N + 10];
long long k, ans, m;
int i, n;

int main() {
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    memset(f, 0, sizeof(f));
    memset(t, 0, sizeof(t));

    m = 1;
    for (i = 1; i <= n; ++i) {
        scanf("%I64d", &k);
        a[k] += k;
        m = max(m, k);
    }

    ans = a[2];
    f[2] = a[1];
    t[2] = 0;
    for (i = 3; i <= m + 1; ++i) {
        t[i] = max(t[i-1], f[i-1]);
        f[i] = max(f[i-2] + a[i-1], t[i]);
        ans = max(ans, t[i]);
        ans = max(ans, f[i]);
    }
    printf("%I64d\n", ans);
    return 0;
}
