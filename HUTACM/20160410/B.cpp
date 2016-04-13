#include<cstdio>
#include<algorithm>
#include<cstring> 
using namespace std;

int a[1001];
int f[1001];
int ans, n, i, j;

int main() {
    scanf("%d", &n);
    for (i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        f[i] = 1;
        for (j = 1; j < i; ++j)
            if (a[j] < a[i])
                f[i] = max(f[i], f[j] + 1);
    }
    ans = f[1];
    for (i = 1; i <= n; ++i)
        ans = max(f[i], ans);
    printf("%d\n", ans);
    return 0;
}
