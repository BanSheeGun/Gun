#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int f[300];
int i, j, k, x, ma, n;

int main() {
    memset(f, 0 ,sizeof(f));
    scanf("%d%d", &n, &x);
    ma = 0;
    f[0] = 1;
    for (i = 1; i <= n; ++i) {
        scanf("%d", &k);
        for (j = min(ma, x); j >= 0; --j)
            if (f[j]) {
                f[j+k] = 1;
                ma = max(ma, j+k);
            }
    }

    if (ma < x)
        printf("-1\n");
    else {
        for (i = x; i <= ma; ++i)
            if (f[i] == 1)
                ma = min(ma, i);
        printf("%d\n", ma);
    }
    return 0;
}