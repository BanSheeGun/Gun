#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

inline bool cmp(int a, int b) {
    return a < b;
}

int a[100010];
int n, i, l, r, now, ans, x;

int main() {
    scanf("%d%d", &n, &x);
    for (i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    a[0] = x;
    sort(a, a+1+n, cmp);
    now = 0;
    for (i = 0; i <= n; ++i)
        if (a[i] == x) now = i;
    ans = 1000000000;
    if (n == 1) {
        printf("%d\n", 0);
        return 0;
    }
    l = now - 0;
    r = n - now;
    if (l == 0) {
        ans = min(ans, a[n-1] - x);
        printf("%d\n", ans);
        return 0;
    }
    if (r == 0) {
        ans = min(ans, x - a[1]);
        printf("%d\n", ans);
        return 0;
    }
    ans = min(ans, x - a[0] + x - a[0] + a[n-1] - x);
    ans = min(ans, x - a[1] + x - a[1] + a[n] - x);
    ans = min(ans, x - a[0] + a[n-1] - x + a[n-1] - x);
    ans = min(ans, x - a[1] + a[n] - x + a[n] - x);
    printf("%d\n", ans);
    return 0;
}