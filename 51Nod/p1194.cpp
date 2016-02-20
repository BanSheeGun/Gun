#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

int f[1001];
int i, t, n, m, a, ans;

int main() {
    f[0] = 0;
    f[1] = 1;
    for (i = 2;i <= 1000; ++i)
        f[i] = f[i-1] + f[i-2];
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d",&n,&m);
        a = n / m;
        ans = 1;
        if (a & 1)
            ans = f[m - 1];
        a = a>>1;
        if ((m & 1) && (a & 1))
            ans *= -1;
        ans *= f[n % m];
        ans = (ans % f[m] + f[m]) % f[m];
        printf("%d\n",ans);
    }
    return 0;
}
