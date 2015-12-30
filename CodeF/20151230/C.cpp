#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

char aa[600];
int a[600][600];
int ll[600][600];
int hh[600][600];
int i,j,ans,t,h,w,x1,x2,y1,y2;

int main()
{
    scanf("%d%d",&h,&w);
    memset(a,0,sizeof(a));
    for (i = 1;i <= h; ++i) {
        scanf("%s",aa);
        for (j = 1;j <=w;++j) {
            if (aa[j-1] == '.') {
                a[i][j] = 0;
            } else {
                a[i][j] = 1;
            }
        }
    }

    memset(hh,0,sizeof(hh));
    for (i = 1;i <= h; ++i) {
        for (j = 2;j <=w;++j) {
            if (a[i][j] == 0 && a[i][j-1] ==0)
                hh[i][j] = 1;
        }
        for (j = 2;j <=w;++j) {
            hh[i][j] += hh[i][j-1];
        }
    }
    for (i = 1;i <= h; ++i) {
        for (j = 1;j <=w;++j) {
            hh[i][j] += hh[i-1][j];
        }
    }
    memset(ll,0,sizeof(ll));
    for (j = 1;j <= w; ++j) {
        for (i = 2;i <=h;++i) {
            if (a[i][j] == 0 && a[i-1][j] ==0)
                ll[i][j] = 1;
        }
        for (i = 2;i <=h;++i) {
            ll[i][j] += ll[i-1][j];
        }
    }
    for (j = 1;j <= w; ++j) {
        for (i = 1;i <=h;++i) {
            ll[i][j] += ll[i][j-1];
        }
    }

    scanf("%d",&t);
    while (t --) {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        ans = (hh[x2][y2] - hh[x2][y1]) - (hh[x1-1][y2] - hh[x1-1][y1]);
        ans+= (ll[x2][y2] - ll[x1][y2]) - (ll[x2][y1-1] - ll[x1][y1-1]);
        printf("%d\n",ans);
    }
    return 0;
}
