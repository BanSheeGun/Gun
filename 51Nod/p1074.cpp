#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

long long k, n, ans, i, x;

inline int find() {
    for (i = 2; i <= n; ++i) {
        if (ans + k < i) {
            x = (i - ans + 1) / (k-1) - 1;
            if (i + x < n) {
                ans += k * x;
                i += x;
            } else {
                ans += k * (n - i);
                i = n;
            }
        }
        ans = (ans + k) % i;
    }
}

int main() {
    ans = 0;
    scanf("%lld%lld", &n, &k);
    find();
    printf("%lld\n", ans + 1);
    return 0;
}
