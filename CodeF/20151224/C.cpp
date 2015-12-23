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
    int a,b;
};

bool cmp(p a,p b) {
    return a.a<b.a;
}

p a[200000];
int ans[200000];
int n,i,aa,t;

int find(int l,int r,int bb) {
    int mid = (l + r + 1) >> 1;
    if (l == r) return mid;
    if (a[mid].a<bb) return find(mid,r,bb);
    return find(l,mid-1,bb);
}

int main()
{
    scanf("%d",&n);
    for (i = 1;i <= n; ++i)
        scanf("%d%d",&a[i].a,&a[i].b);
    sort(a+1,a+n+1,cmp);
    a[0].a = -10000000;
    a[0].b = 0;
    aa = 0;
    memset(ans,0,sizeof(ans));

    for (i = 1;i<=n;++i) {
        t = find(0,i-1,a[i].a-a[i].b);
        ans[i] = ans[t] + 1;
        aa = max(aa, ans[i]);
    }

    printf("%d\n",n - aa);
    return 0;
}
