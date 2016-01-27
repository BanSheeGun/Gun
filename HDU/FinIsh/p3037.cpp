#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<set>
#include<vector>
#include<algorithm>
#define LL long long
using namespace std;

LL base;
LL Frac[100010];
LL n,m,t;

LL Init() {
    Frac[0] = 1;
    for (LL i = 1; i < base; ++i)
        Frac[i] = Frac[i - 1] * i % base;
    return 0;
}

LL Inv(LL a,LL p) {
    if (a == 1)
        return 1;
    LL ans = (p - p / a);
    ans = ans * Inv(p % a,p) % p;
    return ans;
}

LL Lucas(LL n, LL m,LL base) {
    LL ans = 1;
    while (n && m) {
        LL a = n % base;
        LL b = m % base;
        if (a < b)
            return 0;
        LL ret = Frac[b] * Frac[a - b] % base;
        ret = Frac[a] * Inv(ret, base) % base;
        ans = ans * ret % base;
        n /= base;
        m /= base;
    }
    return ans;
}

int main()
{
    scanf("%I64d",&t);
    while (t--) {
        scanf("%I64d%I64d%I64d",&n,&m,&base);
        Init();
        LL ans = Lucas(n + m, m, base);
        printf("%I64d\n",ans);
    }
    return 0;
}
