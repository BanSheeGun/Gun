#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int mn = 10000005;

long long a[100000];
long long pn[664600];
bool prime[mn];
long long ttt, tt, y, n, i, ans, t, j, total;

int main() {
    tt = 0;
    memset(prime, 0, sizeof(prime));
    total = 0;
    for (i = 2;i < mn;++i) {
        if (prime[i] == 0) {
            ++total;
            pn[total] = i;
            for (j = 2;j * i < mn; ++j)
                prime[j * i] = 1;
        }
    }
    scanf("%lld", &ttt);
    while (ttt--) {
        ++tt;
        scanf("%lld",&n);
        t = 0;
        for (i = 1;i <= total && pn[i] <= n;++i) {
            if (n % pn[i] == 0) {
                ++t;
                a[t] = 0;
                while (n % pn[i] == 0) {
                    ++a[t];
                    n = n / pn[i];
                }
            }
        }
        if (n != 1) {
            ++t;
            a[t] = 1;
        }
        ans = 1;
        for (i = 1;i <= t; ++i) {
            ans = ans * (2 * a[i] + 1);
        }
        ans = (ans - 1) / 2 + 1;
        printf("Case %lld: %lld\n",tt,ans);
    }

    return 0;
}
