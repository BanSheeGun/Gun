#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int n,m,i,j,t,tt,ans;

int main()
{
    scanf("%d%d",&n,&m);
    scanf("%d",&t);
    for (i = 1;i < m;++i) {
        scanf("%d",&tt);
        t = min(t,tt);
    }
    ans = t;
    for (j = 1;j <n;++j) {       
       scanf("%d",&t);
        for (i = 1;i < m;++i) {
            scanf("%d",&tt);
            t = min(t,tt);
        }
        ans = max(t, ans);
    }
    printf("%d\n",ans);
    return 0;
}
