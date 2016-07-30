#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

int a[100010];
int b[100010];
int i, j, n, m, ans, l1, l2;

int main() {
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (j = 1; j <= m; ++j)
        scanf("%d", &b[j]);

    i = 1; j = 1; ans = 0;
    while (i <= n) {
        l1 = abs(a[i] - b[j]);
        while (j < m) {
            l2 = abs(a[i] - b[j+1]);
            if (l2 > l1) break;
            ++j;
            l1 = l2;
        }
        ans = max(ans, l1);
        ++i;
    }
    printf("%d\n", ans);
    return 0;
}