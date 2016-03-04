#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;

long long k;
long long x, n, mod, t, tt, ttt, i;

long long Pow(long long k) {
    if (k == 0)
        return 1;
    if (k == 1)
        return n;
    int t = Pow(k / 2);
    t = t * t % mod;
    if (k % 2 == 1)
        t = t * n % mod;
    return t;
}

int main() {
    scanf("%lld",&tt);
    ttt = 0;
    while (tt--) {
        ++ttt;
        scanf("%lld%lld%lld",&n,&k,&mod);
        x = 0;
        for (i = 1;i <= n; ++i) {
            scanf("%lld", &t);
            x += t;
            x %= mod;
        }

        t = Pow(k - 1);
        t = t * k % mod;
        t = t * x % mod;
        printf("Case %lld: %lld\n",ttt,t);
    }
    return 0;
}
