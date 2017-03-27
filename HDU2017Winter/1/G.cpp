#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;

inline bool cmp(int a, int b) {
    return a < b;
}

int a[1010][1010];
int b[1010];
long long t, ans;
int i, j, n, m, T;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        ans = 0;
        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; ++j)
                scanf("%d", &a[i][j]);

        for (j = 1; j <= m; ++j) {
            for (i = 1; i <= n; ++i)
                b[i] = a[i][j];
            sort(b+1, b+n+1, cmp);
            t = b[(1+n)/ 2];
            for (i = 1; i <= n; ++i)
                ans += abs(b[i] - t);
        }
        printf("%lld\n", ans);
    }
    return 0; 
}