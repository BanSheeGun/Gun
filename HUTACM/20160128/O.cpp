#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

struct stu
{
    char name[21];
    int sum;
};

bool cmp(stu a,stu b) {
    if (a.sum == b.sum)
        return (strcmp(a.name,b.name) < 0);
    return a.sum>b.sum;
}

stu a[1010];
int so[15];
int n,m,k,i,line;

int main()
{
    while (~scanf("%d",&n)) {
        if (n == 0) break;
        scanf("%d%d",&m,&line);
        for (i = 1;i <= m; ++i)
            scanf("%d",&so[i]);
        for (i = 1;i <=n;++i) {
            a[i].sum = 0;
            scanf("%s",a[i].name);
            scanf("%d",&m);
            while (m--) {
                scanf("%d",&k);
                a[i].sum += so[k];
            }
        }
        sort(a+1,a+1+n,cmp);
        m = 0;
        for (i = 1;i <= n;++i) {
            if (a[i].sum >= line) m = i;
        }
        printf("%d\n",m);
        for (i = 1;i <= m; ++i)
            printf("%s %d\n",a[i].name,a[i].sum);
    }
    return 0;
}
