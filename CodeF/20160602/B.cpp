#include<cstdio>
#include<cstdlib>
#include<cstring> 
#include<string> 
#include<algorithm> 
using namespace std;

long long n, k, h, i, ans, now;
long long a[100010];

int main() {
    scanf("%I64d%I64d%I64d", &n, &h, &k);
    for (i = 1; i <= n; ++i)
        scanf("%I64d", &a[i]);

    ans = 0;
    i = 1;
    now = 0;
    for (i = 1; i <= n; ++i) {
        if (a[i] + now <= h) {
            now += a[i];
        } else {
            ans += now / k;
            now %= k;
            if (now + a[i] <= h) {
                now += a[i];
            } else {
                now = a[i];
                ++ans;
            }
        }
    }
    ans += now / k;
    now %= k;
    if (now > 0) ++ans;
    printf("%I64d\n", ans);
    return 0;
}
