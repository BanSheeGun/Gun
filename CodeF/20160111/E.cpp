#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

typedef long long ll;
ll base = 1000000007;
ll ans,n,m,t,z,tt;
ll i;

int main()
{
    scanf("%I64d%I64d",&n,&m);
    n = n % base;
    t = min(m,base);
    t = min(m,n);
    if (m > n) {
        ans = (m - n) %base;
        ans = ans * n %base;
    }
    z = n / 2;
    for (i = 1;i <= z;i++) {
        ans = ans + n % i;
        if (ans >= base) ans -= base;
    }
    z = z+1;
    tt = (t - z +1);
    tt = tt * (t - z)/2 % base;
    if (tt >=0) ans = ans + tt;
    ans = ans % base;
    printf("%I64d\n",ans);
    return 0;
}
