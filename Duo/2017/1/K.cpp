#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

ll n, k, t, ans;

int main() {
    int T = 0;
    while (~scanf("%lld%lld", &n , &k)) {
        if (k <= n)
            ans = k;
        else  {
            k -= n;
            t = k / (n-1);
            k = k % (n - 1);
            if (k <= 0)
                k += (n - 1);
            if (t & 1) {
                ans = k;
            } else {
                if (k == (n-1))
                    ans = n;
                else
                    ans = k;
            }
        }
        printf("Case #%d: %lld\n", ++T, ans);
    }
    return 0;
}