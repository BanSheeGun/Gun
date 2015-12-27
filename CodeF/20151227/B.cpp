#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int a[500000];
int n, i;
long long ans,mi;
int f[500000];

int main()
{
    scanf("%d",&n);
    for (i = 1;i <= n;++i)
        scanf("%d",&a[i]);
    mi = a[1];
    for (i = 1;i <= n;++i) {
        a[i + n] = a[i];
        if (a[i] < mi) mi = a[i];
    }
    f[0] = 0;
    ans = 0;
    for (i = 1;i <= 2*n; ++i) {
        if (a[i] == mi) {
            f[i] = 0;
        } else {
            f[i] = f[i-1] + 1;
        }
        if (f[i] > ans) ans = f[i];
    }
    ans = ans + mi * (long long)n;
    printf("%I64d\n",ans);
    return 0;
}
