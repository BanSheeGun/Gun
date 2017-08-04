#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

int a, b, n, l, r, ans;
int x[200], y[200], i, j;

inline bool check(int i, int j) {
    l = max(x[i], x[j]);
    r = y[i] + y[j];
    if ((l <= a && r <= b) || (l <= b && r <= a))
        return 1;
    l = max(x[i], y[j]);
    r = y[i] + x[j];
    if ((l <= a && r <= b) || (l <= b && r <= a))
        return 1;
    l = max(y[i], x[j]);
    r = x[i] + y[j];
    if ((l <= a && r <= b) || (l <= b && r <= a))
        return 1;
    l = max(y[i], y[j]);
    r = x[i] + x[j];
    if ((l <= a && r <= b) || (l <= b && r <= a))
        return 1;
    return 0;
}

int main() {
    scanf("%d%d%d", &n, &a, &b);
    for (i = 1; i <= n; ++i)
        scanf("%d%d", &x[i], &y[i]);
    ans = 0;
    for (i = 1; i < n; ++i)
        for (j = i+1; j <= n; ++j) {
            if (check(i, j))
                ans = max(ans, x[i] * y[i] + x[j] * y[j]);
        }
    printf("%d\n", ans);
    return 0;
}