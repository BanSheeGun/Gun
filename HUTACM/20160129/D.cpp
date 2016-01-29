#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int n,t,d,u,ans,now;

int main()
{
    scanf("%d%d%d",&n,&u,&d);
    while (n != 0) {
        ans = 0;
        t = 1;
        now = 0;
        while (now < n) {
            if (t) {
                now = now + u;
                t = 0;
            } else {
                now = now - d;
                t = 1;
            }
            ++ans;
        }
        printf("%d\n",ans);
        scanf("%d%d%d",&n,&u,&d);
    }
    return 0;
}
