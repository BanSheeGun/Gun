#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int a[100100];
int t, z, tt, i, n, ans, l, r, sum, ll;

int main()
{
    scanf("%d",&tt);
    z = 0;
    while (tt--) {
        ++z;
        printf("Case %d:\n",z);
        scanf("%d",&n);
        t = 0;
        for (i = 1;i <= n;++i){
            scanf("%d",&a[i]);
            if (a[i] > 0) {
                t = 1;
            }
        }

        if (t == 1) {
            ll = 0;
            sum = 0;
            ans = 0;
            for (i = 1;i <= n;++i) {
                sum += a[i];
                if (sum > ans) {
                    ans = sum;
                    r = i;
                    l = ll;
                }
                if (sum < 0) {
                    sum = 0;
                    ll = i;
                }
            }
            printf("%d %d %d\n",ans, l + 1, r);
        } else {
            ans  = 1;
            for (i = 1;i <= n; ++i)
                if (a[i] > a[ans])
                    ans = i;
            printf("%d %d %d\n",a[ans], ans, ans);
        }

        if (tt) {
            printf("\n");
        }
    }
    return 0;
}
