#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

long long l , r , k ,n ,t;

int main()
{
    scanf("%I64d%I64d%I64d",&l,&r,&k);
    t = 1;
    n = 0;
    while (t <= r && t > 0) {
        if (t >= l) {
            printf("%I64d ",t);
            n ++;
        }
        t = t * k;
    }
    if (n == 0) printf("-1\n");
     else printf("\n");
    return 0;
}
