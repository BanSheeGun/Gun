#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

int x[300];
int y[300];
int n, k, xs, ys, ans, i, j, mi, z;
ll t;
int f[60000][300];
bool fa[60000][300];

int main() {
    scanf("%d%d", &n, &k);
    for (i = 1; i <= n; ++i) {
        scanf("%lld", &t);
        x[i] = 0;
        y[i] = 0;
        while (t % 5 == 0) {
            ++x[i];
            t /= 5;
        }
        while (t % 2 == 0) {
            ++y[i];
            t /= 2;
        }
    }
    memset(f, 0, sizeof(f));
    memset(fa, 0, sizeof(fa));
    mi = 0;
    fa[0][0] = 1;
    for (i = 1; i <= n; ++i) {
        for (j = mi; j >= 0; --j)
            for (z = k; z >= 1; --z)
                if (fa[j][z-1]) {
                    f[j+x[i]][z] = max(f[j+x[i]][z], f[j][z-1] + y[i]);
                    fa[j+x[i]][z] = 1;
                }
        mi = mi + x[i];
    }
    ans = 0;
    for (i = 1; i <= mi; ++i)
        ans = max(ans, min(i, f[i][k]));
    printf("%d\n", ans);
    return 0;
}