#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define LL long long

const LL base = 110119;
LL fac[120010];
struct P {
    long long x, y;
};

bool cmp(P x, P y) {
    if (x.x == y.x) return x.y < y.y;
    return x.x < y.x;
}

LL Init() {
    fac[0] = 1;
    for (LL i = 1; i <= base; ++i)
        fac[i] = fac[i - 1] * i % base;
    return 0;
}
 
LL quick_mod(LL a,LL b,LL m)  
{  
    LL ans = 1;  
    a %= m;  
    while(b)  
    {  
        if(b & 1)  
        {  
            ans = ans * a % m;  
            b--;  
        }  
        b >>= 1;  
        a = a * a % m;  
    }  
    return ans;  
}  
  
LL C(LL n,LL m,LL p)  
{  
    if(n < m || n < 0 || m < 0) return 0;  
    return fac[n] * quick_mod(fac[m] * fac[n-m] % p, p - 2, p) % p;  
}  
  
LL Lucas(LL n,LL m,LL p)  
{  
    if(m == 0) return 1;  
    return C(n % p, m % p, p) * Lucas(n / p, m / p, p) % p;  
}  

long long f(long long x, long long y) {
    if ((2 * x - y) % 3 != 0) return 0;
    if ((2 * y - x) % 3 != 0) return 0;
    long long a = (2 * x - y) / 3;
    long long b = (2 * y - x) / 3;
    return Lucas(a+b, a, base);
}

int test, r, i, j;
LL n, m, t;
P a[110];
long long b[110];

int main() {
    test = 0;
    Init();
    while (~scanf("%lld%lld%d", &n, &m, &r)) {
        for (i = 1; i <= r; ++i) {
            scanf("%lld%lld", &a[i].x, &a[i].y);
        }
        ++r; a[r].x = n; a[r].y = m;
        sort(a+1, a+1+r, cmp);
        memset(b, 0, sizeof(b));
        for (i = 1; i <= r; ++i) {
            b[i] = f(a[i].x - 1, a[i].y - 1);
            for (j = 1; j < i; ++j) {
                t = b[j];
                t = t * f(a[i].x - a[j].x, a[i].y - a[j].y) % base;
                b[i] = (b[i] - t) % base;
                if (b[i] < 0) b[i] += base;
            }
        }
        ++test;
        printf("Case #%d: %lld\n", test, b[r]);
    }
    return 0;
}