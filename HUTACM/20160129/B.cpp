#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int a[501];
int num,sum,n,i,ans,tt;

int main()
{
    scanf("%d",&tt);
    while (tt--) {
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        for (i = 1;i <= n; ++i) {
            scanf("%d%d",&num,&sum);
            a[num] += sum;
        }
        ans = 0;
        for (i = 1;i <= 500;++i) {
            ans += (a[i]+63) / 64;
        }
        ans = (ans + 35) / 36;
        printf("%d\n",ans);
    }
    return 0;
}
