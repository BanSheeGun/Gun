#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int a[5], b[5];
int T, TT, i, j, ans, t;

int main() {
    scanf("%d", &T); TT = 0;
    while (T--) {
        TT++;
        scanf("%d%d%d%d", &a[0], &a[1], &a[3], &a[2]);
        scanf("%d%d%d%d", &b[0], &b[1], &b[3], &b[2]);
        ans = 0;
        for (i = 0; i <= 4; ++i) {
            t = 1;
            for (j = 0; j < 4; ++j)
                t = t & (a[(i+j) % 4] == b[j]);
            ans = ans | t;
        }
        if (ans)
            printf("Case #%d: POSSIBLE\n", TT);
        else
            printf("Case #%d: IMPOSSIBLE\n", TT);
    }
    return 0;
}