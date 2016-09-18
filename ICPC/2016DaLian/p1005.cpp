#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

long long h, k, l, t, a, ans, a1, a2, n, m, la;

int main() {
    while (~scanf("%lld%lld%lld", &h, &l, &k)) {
        a = k / h;
        m = (k / (a+1))+1;
        if (l % m == 0) {
            n = l / m;
            a2 = (n+a-1)/ a;
        } else {
            n = l / m;
            la = l - m * n;
            if (n % a == 0) {
                a2 = n / a + 1;
            } else {
                a2 = n / a;
                n = n - a2 * a;
                if (n * m + la <= k) {
                    a2 += 1;
                } else {
                    a2 += 2;
                }
            }
        }
        printf("%lld\n", a2);
    }
    return 0;
}