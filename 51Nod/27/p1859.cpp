#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
int T;
ll n, k, ans;
double eps = 1e-5;

ll find(ll l, ll r, ll x) {
    if (l == r)
        return l;
    ll mid = (l + r + 1) / 2;
    if (mid * mid <= x)
        return find(mid, r, x);
    return find(l, mid-1, x);
}

ll sq(ll x) {
    return find(1, 1e9, x);
}  

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld", &n, &k);
        if (k == 2 && (n == 1 || n == 3)) {
            puts("-1");
            continue;
        }
        ans = 0;
        while (n != 0) {
            if (k == 2 && n <= 4) {
                ans += n / 2;
                n = 0;
            } else {
                ll tmp = floor(sq(n));
                if (tmp * tmp != n) {
                    if (n - k < tmp * tmp && n > 5) {
                        n = n - k;
                        ans++;
                    } else {
                        n = tmp * tmp;
                        ans++;
                    }
                } else {
                    if (tmp > 2) {
                        ans += (tmp - 2) * 2;
                        n = 4;
                    } else {
                        n -= k;
                        ++ans;
                    }
                }           
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}