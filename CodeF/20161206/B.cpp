#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

long long a[100100];
long long t[1000100];
long long n, x, i;
long long ans;

int main() {
    scanf("%lld%lld", &n, &x);
    memset(t, 0, sizeof(t));
    ans = 0;
    for (i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        t[a[i]]++;
    }
    for (i = 1; i <= n; ++i) {
        ans += t[a[i] ^ x];
    }
    ans /= 2;
    printf("%lld\n", ans);
    return 0;
}