#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int a[200];
int ma,mi,n,i,ans;

int main()
{
    scanf("%d",&n);
    for (i = 1;i <= n; ++i) {
        scanf("%d",&a[i]);
    }
    ma = 1;
    for (i = 1;i <= n; ++i) {
        if (a[i] > a[ma])
            ma = i;
    }
    mi = 1;
    for (i = 1;i <= n; ++i) {
        if (a[i] <= a[mi])
            mi = i;
    }
    ans = 0;
    if (ma > mi)
        ans = -1;
    ma = ma - 1;
    mi = n - mi;
    ans += mi + ma;
    printf("%d\n",ans);
    return 0;
}
