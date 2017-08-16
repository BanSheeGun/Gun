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

int work(int p) {
    if (p == 1)
        return 0;
    int phi = p, m = p;
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
    if (m != 1) {
        phi /= m;
        phi *= (m-1);
    }
    if (p % 2 == 0)
        return qm(2, work(phi) + phi, p);
    else
        return qm(2, work(phi), p);
}

int T, n;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("%d\n", work(n));
    }
    return 0;
}