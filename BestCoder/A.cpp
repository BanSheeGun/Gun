#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int t, n, m, ans;

int main()
{
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d",&m,&n);
        ans = m / 2;
        ans += n / 2;
        printf("%d\n",ans);
    }
    return 0;
}
