#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int a[1001];
int f[1001];
int ans, n, i, j;

int main() {
    while (scanf("%d", &n), n != 0)  {
        for (i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            f[i] = a[i];
            for (j = 1; j < i; ++j)
                if (a[j] < a[i])
                    f[i] = max(f[i], f[j] + a[i]);
        }
        ans = f[1];
        for (i = 1; i <= n; ++i)
            ans = max(f[i], ans);
        printf("%d\n", ans);
    }
    return 0;
}
