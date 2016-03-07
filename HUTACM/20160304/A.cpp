#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;

long long ttt, tt, n, ans, m, t;

int main() {
    tt = 0;
    scanf("%lld", &ttt);
    while (ttt--) {
        ++tt;
        scanf("%lld",&n);
        ans = 0;
        m = n;
        while (m != 0) {
            t = sqrt(m);
            t = (t + 1) / 2;
            ans += t;
            m = m / 2;
        }
        ans = n - ans;
        printf("Case %lld: %lld\n",tt,ans);
    }

    return 0;
}
