#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

long long ans, t ,i ,n ,tt;
long long a[300000];

int main()
{
    scanf("%I64d",&n);
    ans = 0;
    for (i = 1;i <= n;++i) {
        scanf("%I64d",&t);
        a[t] = i;
    }
    for (i = 1;i < n;++i) {
        ans += abs(a[i] - a[i + 1]);
    }
    printf("%I64d\n",ans);
    return 0;
}
