#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

int i, j, n, m, k;
int h[100];
int y[100];
int x[100];
int ans;

int f(int x1, int x2, int y1, int y2) {
    if (x1 > x2) {
        swap(x1, x2);
        swap(y1, y2);
    }
    int hi = min(y1, y2);
    for (int i = x1+1; i <= x2-1; ++i)
        hi = min(hi, h[i]);
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