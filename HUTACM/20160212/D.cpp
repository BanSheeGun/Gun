#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int a[60];
int n,v,i,top,nn,p,t;

int main()
{
    scanf("%d%d",&n,&v);
    top = 0;
    for (i = 1;i <= n; ++i) {
        t = 0;
        scanf("%d",&nn);
        while (nn--) {
            scanf("%d",&p);
            if (p < v)
                t = 1;
        }
        if (t) {
            ++top;
            a[top] = i;
        }
    }
    printf("%d\n",top);
    if (top != 0) {
        for (i = 1;i < top; ++i)
            printf("%d ",a[i]);
        printf("%d\n",a[top]);
    }
    return 0;
}
