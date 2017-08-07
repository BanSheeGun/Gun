#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
ll high[340000], low[340000];
ll fun(ll n) {
    ll i, m, ret=0, p, s, x;
    for(m = 1; m*m <= n; m++)
        high[m] = n/m-1;
    for(i = 1;i <= m; i++)
        low[i]=i-1;
    for(p = 2;p <= m; p++)
    {
        if(low[p] == low[p-1])
            continue;
        s = min(n/(p*p), m-1);
        for(x = 1; x <= s; x++)
        {
            if(x*p <= m-1)
                high[x] -= high[x*p]-low[p-1];
            else
                high[x] -= low[n/(x*p)]-low[p-1];
        }
        for(x = m;x >= p*p; x--)
            low[x] -= low[x/p]-low[p-1];
    }
    for(p = 2;p < m;p++)
    {
        if(low[p] == low[p-1])
            continue;
        ret += high[p]-low[p];
    }
    return ret;
}

ll n,k;
int main() {
    while (~scanf("%lld", &n)) {
        k = pow(n, 1.0/3) + 1e-9;
        printf("%lld\n", fun(n)+low[k]);
    }
    return 0;
}