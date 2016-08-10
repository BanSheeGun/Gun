#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll n, m, a, b, t;

int main() {
    while (scanf("%lld%lld", &n, &m), m != 0) {
        a = n * (m - 1);
        b = m * m;
        t = gcd(a, b);
        printf("%lld/%lld\n", a/t, b/t);
    }
    return 0;
}