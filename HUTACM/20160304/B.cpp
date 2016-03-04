#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;

long long a[100000];
long long ttt, tt, y, n, i, ans, t;

int main() {
    scanf("%lld", &ttt);
    tt = 0;
    while (ttt--) {
        ++tt;
        scanf("%lld",&n);
        t = 0;
        i = 1;
        while (n != 1) {
            ++i;
            if (n % i == 0) {
                ++t;
                a[t] = 0;
                while (n % i == 0) {
                    n = n / i;
                    ++a[t];
                }
            }
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
