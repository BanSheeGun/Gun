#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

typedef long long ll;

ll n,m,ans,t,i;

int main() {
    scanf("%lld%lld",&n,&m);
    while (n != 0 || m != 0) {
        if (n > m) swap(n,m);
        ans = m * n * (n - 1);
        ans += n * m * (m - 1);
        ans += 2 * n * (n - 1) * (3 * m - n - 1) / 3;
        printf("%lld\n",ans);
        scanf("%lld%lld",&n,&m);
    }
    return 0;
}
