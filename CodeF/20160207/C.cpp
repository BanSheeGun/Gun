#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int a[501][501];
int n,i,j,k,now,ans;

int main()
{
    scanf("%d%d",&n,&k);
    now = 0;
    for (i = 1;i <= n; ++i)
        for (j = 1;j < k; ++j) {
            ++now;
            a[i][j] = now;
        }
    for (i = 1;i <= n; ++i)
        for (j = k;j <= n; ++j) {
            ++now;
            a[i][j] = now;
        }
    ans = 0;
    for (i = 1;i <=n;++i)
        ans += a[i][k];
    printf("%d\n",ans);
    for (i = 1;i <= n; ++i) {
        for (j = 1;j < n; ++j)
            printf("%d ",a[i][j]);
        printf("%d\n",a[i][n]);
    }
    return 0;
}
