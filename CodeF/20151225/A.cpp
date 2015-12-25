#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int x,y;
int t,i,j,n,p,q;
char a[1000];

int s() {
    int i;
    for (i = 0;i <= n/p;++i)
        if ((n- i * p) % q == 0) {
            x = i;
            y = (n- i * p) / q;
            return 1;
        }
    return 0;
}

int main()
{
    scanf("%d%d%d",&n,&p,&q);
    scanf("%s",a);
    if (s()) {
        t = -1;
        printf("%d\n",x + y);
        for (i = 1;i <= x; ++i) {
            for (j = 1;j <= p; ++j) {
                ++t;
                printf("%c",a[t]);
            }
            putchar('\n');
        }
        for (i = 1;i <= y; ++i) {
            for (j = 1;j <= q; ++j) {
                ++t;
                printf("%c",a[t]);
            }
            putchar('\n');
        }
    }  else {
        printf("-1\n");
    }
    return 0;
}
