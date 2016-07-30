#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

long long d, k, a, b, t, n;
long long a1, a2, a3;

int main() {
    scanf("%I64d%I64d%I64d%I64d%I64d", &d, &k, &a, &b, &t);
    if (d <= k) {
        a1 = d * a;
    } else {
        a1 = k * a + (d - k) * b;
    }

    n = d / k;
    a2 = d * a + n * t;
    a3 = n * k * a + (d - n * k) * b + (n - 1) * t;
    a1 = min(a1, a2);
    a1 = min(a1, a3);
    printf("%I64d\n", a1);
    return 0;
}