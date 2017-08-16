#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

int T;
ll n, k, ans;

void work(ll n) {
    ans ^= n;
    if (n <= 1)
        return;
    n -= 1;
    ll tmp = 0;
    while (tmp < (double)n / k) {
        tmp = tmp * k + 1;
    }
    ll tmp1 = (tmp - 1) / k;
    ll a = (n - k * tmp1) / (tmp - tmp1);
    ll c = k - a - 1;
    if (c < 0)
        c = 0;
    ll b = n - a * tmp - c * tmp1;
    if (b == tmp1) {
        ++c;
        b = 0;
    }
    if (a % 2)
        work(tmp);
    if (c % 2)
        work(tmp1);
    work(b);
    return;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld", &n, &k);
        if (k == 1) {
            switch (n % 4) {
                case 0 : ans = n; break;
                case 1 : ans = 1; break;
                case 2 : ans = n + 1; break;
                default : ans = 0; break;
            };
            printf("%lld\n", ans);
        } else {
            ans = 0;
            work(n);
            printf("%lld\n", ans);
        }
    }    
    return 0;
}