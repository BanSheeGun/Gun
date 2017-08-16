#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
inline ll qm(ll a, ll n, const ll & p) {
    ll ans = 1;
    ll tmp = a;
    while (n != 0) {
        if (n & 1)
            ans = ans * tmp % p;
        n = n >> 1;
        tmp = tmp * tmp % p;
    }
    return ans;
}

int a, c, i;
ll ans;
char b[1000010];

int main() {
    while (~scanf("%d%s%d", &a, b, &c)) {    
        int phi = c, m = c;
        int k = 2;
        while (k * k <=m) {
            if (m % k == 0) {
                phi /= k;
                phi *= (k-1);
                while (m % k == 0)
                    m /= k;
            }
            ++k;
        }
        if (m != 1)
            phi = phi / m * (m - 1);
        int n = strlen(b);
        ans = 0;
        if (n <= 10) {
            for (i = 0; i < n; ++i) {
                ans *= 10;
                ans += b[i] - '0';
            }
            if (ans > phi)
                ans = ans % phi + phi;
        } else {            
            for (i = 0; i < n; ++i) {
                ans *= 10;
                ans += b[i] - '0';
                ans %= phi;
            }
            ans += phi;
        }
        printf("%lld\n", qm(a, ans, c));
    }
    return 0;
}