#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int a[2000];
int b[2000];
int n,x,y,i;
long long t,ans;

int main()
{
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    while (n--) {
        scanf("%d%d",&x,&y);
        a[x + y - 1]++;
        b[x - y + 1000]++;
    }
    ans = 0;
    for (i = 1;i <= 1999;++i) {
        t = a[i];
        ans += (t - 1) * t / 2;
        t = b[i];
        ans += (t - 1) * t / 2;
    }
    printf("%I64d\n",ans);
    return 0;
}
