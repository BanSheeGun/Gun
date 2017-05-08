#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
char a[1000010];
ll f[1000010];
ll l, x, ans, i;

int main() {
    f[0] = 1;
    for (i = 1; i <= 1000005; ++i)
        f[i] = f[i-1] * 2 % MOD;
    ans = 0;
    x = 0;
    scanf("%s", a);
    l = strlen(a);
    for (i = 0; i < l; ++i)
        if (a[i] == 'a')
            ++x;
        else
            ans = (ans + f[x] - 1) % MOD;
    printf("%lld\n", ans);
    return 0; 
}