#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

struct Point
{
    int x,s1,s2;
};

Point a[4000000];
int ans[400000][2];

bool cmp(Point a,Point b) {
    if (a.x == b.x)
        return a.s1 >= b.s1;
    return a.x<b.x;
}

int n ,k ,t ,i;

int main()
{
    n = 0;
    scanf("%d%d",&n,&k);
    for (i = 1; i<= n; ++i ){
        scanf("%d",&a[i*2-1].x);
        a[i*2-1].s1 = 1;
        a[i*2-1].s2 = 0;
        scanf("%d",&a[i*2].x);
        a[i*2].s1 = 0;
        a[i*2].s2 = 1;
    }
    sort(a + 1,a + 1 + n * 2,cmp);
    for (i = 2;i <= 2 * n; ++i) {
        a[i].s1 += a[i-1].s1;
        a[i].s2 += a[i-1].s2;
    }

    for (i = 2;i <= 2 * n; ++i) {
        if (a[i-1].s1-a[i-1].s2 >=k) {
            ++t;
            ans[t][0] = a[i-1].x;
            if (t > 1)
                if (ans[t-1][1] >= a[i-1].x)
                    --t;
            ans[t][1] = a[i].x;
        }
    }

    printf("%d\n",t);
    for (i = 1;i <= t;++i)
        printf("%d %d\n",ans[i][0],ans[i][1]);
    return 0;
}
