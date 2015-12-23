#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

struct p
{
    int f,s;
};

bool cmp(p a,p b) {
    return a.f>b.f;
}

p a[200];
int n,s,i,ans,now;

int main()
{
    scanf("%d%d",&n,&s);
    for (i = 0;i < n; ++i)
        scanf("%d%d",&a[i].f,&a[i].s);
    sort(a,a+n,cmp);
    a[n].f = 0;
    a[n].s = 0;
    ans = 0;
    now = s;
    for (i = 0;i <= n; ++i) {
        ans += now - a[i].f;
        ans = max(a[i].s,ans);
        now = a[i].f;
    }

    printf("%d\n",ans);
    return 0;
}
