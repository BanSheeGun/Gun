#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long LL;
LL base;
int t[100000];
int p[100000];
int e[100000];
int i, j, k, n, pt, pp, m;

LL f(LL x, LL n, LL base) {
    LL ans = 1;
    x %= base;
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    ans = f(x, n / 2, base);
    ans = ans * ans % base;
    if (n % 2 == 1) 
        ans = ans * x % base;
    return ans;
}

int pan(int k) {
    for (int i = 1; i <= pp; ++i) {
        if (f(k, m / e[i], base) == 1)
            return 0;
    }
    return 1;
}

int main() {
    memset(t, 0, sizeof(t));
    pt = 0;
    for (i = 2; i < 100000; ++i) {
        if (t[i] == 0) {
            ++pt; p[pt] = i;
            for (j = 2 * i; j < 100000; j = j + i) {
                t[j] = 1;
            }
        }
    }

    scanf("%d", &n);
    base = n; m = n-1;
    n = n-1;
    for (i = 1; i <= pt; ++i) {
        if (p[i] > n) break;
        if (n % p[i] == 0) {
            ++pp;
            e[pp] = p[i];
            if (n % p[i] == 0) {
                n /= p[i];
            }
        }
    }

    if (n != 1) {
        ++pp; e[pp] = n;
    }

    for (i = 2;; ++i) {
        if (pan(i)) {
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}