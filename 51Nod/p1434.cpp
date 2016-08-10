#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

int t[1000010];
long long p[1000010];
int i, j, k, n, pt;
long long tmp, ans;

int main() {
    memset(t, 0, sizeof(t));
    pt = 0;
    for (i = 2; i <= 1000000; ++i) {
        if (t[i] == 0) {
            ++pt; p[pt] = i;
            for (j = 2 * i; j <= 1000000; j = j + i) {
                t[j] = 1;
            }
        }
    }
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        ans = n+1;
        for (i = 1; i <= pt; ++i) {
            if (p[i] > n) break;
            tmp = p[i];
            while(tmp * p[i] <= n)
                tmp *= p[i];
            ans = max(ans, tmp * 2);
        }
        printf("%lld\n", ans);
    }
    return 0;
}