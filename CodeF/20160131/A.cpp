#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int n,i,t;
long long a2, a3, ans, k;

int main()
{
    scanf("%d",&n);
    ans = 0;
    a2 = 0;
    a3 = 0;
    t = 0;
    for (i = 1;i <= n;++i) {
        scanf("%I64d",&k);
        if (k % 2 == 0)
            ans += k;
        else {
            a2 += k;
            t = t+1;
            if (t == 1)
                a3 = k;
            else
                if (k < a3) a3 = k;
        }
    }
    if (t % 2==1) a2 = a2 - a3;
    ans = ans + a2;
    printf("%I64d\n",ans);
    return 0;
}
