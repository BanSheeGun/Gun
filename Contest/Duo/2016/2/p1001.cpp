#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

int t;
unsigned long long w[100010];
unsigned long long n, i, ss, sss, tt, s;
long long ppp;

inline unsigned long long gcd(unsigned long long a, unsigned long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%llu", &n);
        s = 0;
        for (i = 1; i <= n; ++i) {
            scanf("%llu", &ppp);
            if (ppp < 0)
                ppp = -ppp;
            w[i] = ppp;
            s += w[i];
        }

        ss = 0; sss = n;
        for (i = 1; i <= n; ++i) {
            ss = ss + n * w[i] * w[i];
        }
        ss = ss - s * s;

        tt = gcd(sss, ss);
        ss = ss / tt;
        sss = sss/ tt;
        printf("%llu/%llu\n", ss, sss);
    }    
    return 0;
}