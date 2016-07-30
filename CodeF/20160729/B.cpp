#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<map>

using namespace std;

map<long long, long long> a;
long long t[32];
long long n, k, ans, i, j;

int main() {
    t[0] = 1;
    for (i = 1; i <= 31; ++i) {
        t[i] = t[i-1] * 2;
    }

    ans = 0;
    scanf("%I64d", &n);
    for (i = 1; i <= n; ++i) {
        scanf("%I64d", &k);
        for (j = 1; j <= 31; ++j) {
            ans += a[t[j] - k];
        }
        a[k]++;
    }
    printf("%I64d\n", ans);
    return 0;
}