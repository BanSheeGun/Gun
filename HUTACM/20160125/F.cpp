#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

struct st
{
    double s;
    int num;
};

bool cmp1(st a,st b) {
    return a.s>b.s;
}

bool cmp2(st a,st b) {
    return a.num>b.num;
}

st a[10010];
int i,j,n,m,k;
double z;

int main()
{
    while (scanf("%d%d%d",&n,&m,&k) != EOF) {
        for (i = 0;i < m; ++i) {
            a[i].s = 0;
            a[i].num = i + 1;
        }
        for (j = 1;j <= n; ++j)
            for (i = 0;i < m; ++i) {
                scanf("%lf",&z);
                a[i].s += z;
            }

        sort(a, a+m, cmp1);
        sort(a, a+k, cmp2);
        for (i = 0; i < k-1; ++i)
            printf("%d ",a[i].num);
        printf("%d\n",a[k - 1].num);
    }
    return 0;
}
