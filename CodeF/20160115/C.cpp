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
    int x,y;
};

double ans;
double PI = acos(-1.0);
int i,n,ma,l,la;
double mi;
Point z,a,t;
int dd(Point a,Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main()
{
    scanf("%d%d%d",&n,&z.x,&z.y);
    scanf("%d%d",&a.x,&a.y);
    ma = dd(z,a);
    mi = dd(z,a);
    t = a;
    la = ma;
    for (i = 1;i < n; ++i) {
        scanf("%d%d",&a.x,&a.y);
        l = dd(a, z);
        ma = max(ma, l);
        if (l < mi) mi = l;
        if (l == la)
            if (l/2.0 < mi) mi = l/2.0;
        la = l;
    }
    a = t;
    ma = max(ma, l);
    if (l < mi) mi = l;
    if (l == la)
        if (l/2.0 < mi) mi = l/2.0;

    ans = ma - mi;
    ans = ans * PI;
    printf("%.20lf\n",ans);
    return 0;
}
