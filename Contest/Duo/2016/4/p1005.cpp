#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

long long a[20], m[20];
long long aa[20], p[20];
long long ans, x, y;
int n, i, tmp, j, t, tt, ttt, nn;

#define LL long long
 
LL PowMod(LL a, LL b, LL base) {
    LL ans = 0;
    a %= base;
    b %= base;
    LL now = b;
    while (a != 0) {
        ans += now * (a % 2);
        ans %= base;
        now *= 2;
        now %= base;
        a = a / 2;
    }
    return ans;
}

void extend_Euclid(long long a, long long b, long long &x, long long &y) {  
    if(b == 0) {  
        x = 1;  
        y = 0;  
        return;  
    }  
    extend_Euclid(b, a % b, x, y);  
    long long tmp = x;  
    x = y;  
    y = tmp - (a / b) * y;  
} 

inline long long CRT(long long n, long long l, long long r) {  
    long long M = 1;  
    long long ans = 0;  
    for(int i=1; i<=n; i++)  
        M *= m[i];  
    for(int i=1; i<=n; i++) {  
        long long x, y;  
        long long Mi = M / m[i];  
        extend_Euclid(Mi, m[i], x, y);  
        ans = (ans + PowMod(PowMod(Mi, x, M), a[i], M)) % M;  
    }  
    if(ans < 0) ans += M;
    l = l - ans;
    r = r - ans + 1;
    if (l <= 0) l = 0;
    else
        l = (l + M - 1) / M;
    if (r <= 0) r = 0;
    else
        r = (r + M - 1) / M;
    return r - l;
}

int main() {
    scanf("%d", &tt);
    for (ttt = 1; ttt <= tt; ++ttt) {
        printf("Case #%d: ", ttt);
        scanf("%d%lld%lld", &n, &x, &y);
        for (i = 1; i <= n; ++i)
            scanf("%lld%lld", &p[i], &aa[i]);
        t = 1 << n; t = t - 1;
        ans = y / 7 - (x - 1) / 7;
        for (i = 1; i <= t; ++i) {
            nn = 1;
            a[1] = 0; m[1] = 7;
            tmp = 1; j = 1;
            while (tmp <= i) {
                if (tmp & i) {
                    ++nn;
                    a[nn] = aa[j];
                    m[nn] = p[j];
                }
                ++j;
                tmp = tmp * 2;
            }
            if (nn%2 == 0)
                ans -= CRT(nn, x, y);
            else
                ans += CRT(nn, x ,y);
        }
        printf("%lld\n", ans);
    }
    return 0;
}