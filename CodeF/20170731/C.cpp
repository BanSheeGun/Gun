#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

int sum[12][110][110];
int i, x, y, s, n, q, c, t, tmp;
int x1i, x2i, y1i, y2i, ans;

int main() {
    memset(sum, 0, sizeof(sum));
    scanf("%d%d%d", &n, &q, &c);
    for (i = 1; i <= n; ++i) {
        scanf("%d%d%d", &x, &y, &s);
        sum[s][x][y]++;
    }
    for (i = 0; i <= c; ++i)
        for (x = 1; x <= 100; ++x)
            for (y = 1; y <= 100; ++y)
                sum[i][x][y] = sum[i][x][y] + sum[i][x][y-1];
    for (i = 0; i <= c; ++i)
        for (x = 1; x <= 100; ++x)
            for (y = 1; y <= 100; ++y)
                sum[i][x][y] = sum[i][x][y] + sum[i][x-1][y];
    while (q--) {
        scanf("%d%d%d%d%d", &t, &x1i, &y1i, &x2i, &y2i);
        ans = 0;
        t = t % (c + 1);
        for (i = 0; i <= c; ++i) {
            tmp = sum[i][x2i][y2i] + sum[i][x1i-1][y1i-1];
            tmp -= sum[i][x1i-1][y2i];
            tmp -= sum[i][x2i][y1i-1];
            ans += (t + i) % (c + 1) * tmp;
        }
        printf("%d\n", ans);
    }
    return 0;
}