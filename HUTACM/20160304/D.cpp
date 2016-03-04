#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;

long long t, ans, b, tt, i;
char a[300];

int main() {
    scanf("%lld",&t);
    tt = 0;
    while (t--) {
        tt++;
        ans = 0;
        scanf("%s", a);
        scanf("%lld",&b);
        if (b < 0)
            b = -b;

        for (i = 0;i < strlen(a); ++i) {
            if (a[i] == '-')
                continue;
            ans = ans * 10 % b;
            ans = ans + a[i] - 48;
            ans %= b;
        }

        if (ans == 0) {
            printf("Case %lld: divisible\n",tt);
        } else {
            printf("Case %lld: not divisible\n",tt);
        }
    }
    return 0;
}
