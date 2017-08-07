#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int ans, n, i;
long long a[1000010];
long long s;

int main() {
    while(~scanf("%d", &n)) {
        for (i = 1; i <= n; ++i)
            scanf("%lld", &a[i]);
        s = 0; ans = 0;
        for (i = n; i >= 1; --i) {
            s = s + a[i];
            if (s >= 0) {
                s = 0;
                ++ans;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}