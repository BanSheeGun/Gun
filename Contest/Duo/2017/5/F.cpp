#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

int T;
ll n, m, ans, x, y;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld", &n, &m);
        if (m < (n-1)) {
            x = m+1;
            y = n-x;
            ans = 2 * (x - 1) * (x - 1);
            ans += 2 * x * y * n;
            ans += y * (y - 1) * n;
        } else {
            m -= n-1;
            ans = 2 * (n-1) * (n-1);
            ll tmp = (n-1) * (n-2) / 2;
            if (m >= tmp)
                m = tmp;
            ans -= m * 2;
        }
        printf("%lld\n", ans);
    }    
    return 0;
}