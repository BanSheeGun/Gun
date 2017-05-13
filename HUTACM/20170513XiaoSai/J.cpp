#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;

long long n, t, a, b, c, ans;

long long f(long long l, long long r) {
    if (l == r)
        return l;
    long long mid = (l + r + 1) / 2;
    long long x = 100 * mid / (a * t);
    if (x * a * t < 100 * mid)
        x += 1;
    long long y = n - x;
    if (y * b * t >= 50 * mid)
        return f(mid, r);
    else
        return f(l, mid-1);
}

int main() {
    int T;
    long long maxn = 1e13;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld%lld%lld", &n, &t, &a, &b);
        ans = f(0, maxn);
        printf("%lld\n", ans);
    }
    return 0; 
}