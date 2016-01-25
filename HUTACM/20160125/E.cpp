#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

double ans;
int n, i, t;

int main()
{
    scanf("%d",&t);
    while (t--) {
        ans = 0;
        scanf("%d",&n);
        for (i = 2;i <=n; ++i)
            ans += log(i);
        ans /= log(10);
        ans = ceil(ans);
        printf("%d\n",(int)ans);
    }
    return 0;
}
