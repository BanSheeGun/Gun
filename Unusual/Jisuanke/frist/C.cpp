#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<math.h>
using namespace std;

int i, j, n, m, k;
int h[200010];
int y[3000];
int x[3000];
int ans;


int fa[200100][19];
int init() {
    for (i = 1; i <= n; ++i) {
        fa[i][0] = h[i];
    }

    int nLog = int(log(double(n)) / log(2.0));
    for (int j = 1; j <= nLog; j++) {
        for (int i = 1; i <= n; i++) {
            if ((i + (1 << j) - 1) <= n) {
                fa[i][j] = min(fa[i][j - 1], fa[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    return 0;
}

int ST(int l,int r) {
    int nLog = (int)(log(double(r - l + 1) / log(2.0)));
    return min(fa[l][nLog], fa[r - (1 << nLog) + 1][nLog]);
}

int f(int x1, int x2, int y1, int y2) {
    if (x1 > x2) {
        swap(x1, x2);
        swap(y1, y2);
    }
    int hi = min(y1, y2);
    if (x1+1 <= x2-1)
        hi = min(ST(x1+1, x2-1), hi);
    int dis = y1 - hi + y2 - hi + (x2 - x1);
    if (dis <= k)
        return 1;
    else
        return 0;
}

int main() {
    scanf("%d%d", &n, &k);
    for (i = 1; i <= n; ++i) {
        scanf("%d", &h[i]);
    }
    init();
    scanf("%d", &m);
    for (i = 1; i <= m; ++i) {
        scanf("%d%d", &x[i], &y[i]);
    }

    ans = 0;
    for (i = 1; i <= m; ++i)
        for (j = i+1; j <= m; ++j)
            if (f(x[i], x[j], y[i], y[j]))
                ++ans;

    printf("%d\n", ans);
    return 0; 
}
