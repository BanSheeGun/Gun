#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[510][511];
ll i, j, x, y, sum, tmp, n, xx;
int main() {
    scanf("%lld", &n);
    if (n == 1) {
        printf("1\n");
        return 0;
    }
    x = 0; y = 0;
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; ++j) {
            scanf("%lld", &a[i][j]);
            if (a[i][j] == 0) {
                x = i;
                y = j;
            }
        }

    tmp = 0; xx = 1; if (x == 1) xx = 2;
    for (i = 1; i <= n; ++i)
        tmp += a[xx][i];
    for (i = 1; i <= n; ++i)
        tmp -= a[x][i];
    a[x][y] = tmp;
    if (tmp < 1) {
        printf("-1\n");
        return 0;
    }
    tmp = 0;
    for (i = 1; i <= n; ++i)
        tmp += a[1][i];
    for (i = 1; i <= n; ++i) {
        sum = 0;
        for (j = 1; j <= n; ++j)
            sum += a[i][j];
        if (sum != tmp) {
            printf("-1\n");
            return 0;
        }
    }
    for (i = 1; i <= n; ++i) {
        sum = 0;
        for (j = 1; j <= n; ++j)
            sum += a[j][i];
        if (sum != tmp) {
            printf("-1\n");
            return 0;
        }
    }
    sum = 0;
    for (i = 1; i <= n; ++i) {
        sum += a[i][i];
    }
        if (sum != tmp) {
            printf("-1\n");
            return 0;
        }

    sum = 0;
    for (i = 1; i <= n; ++i) {
        sum += a[i][n+1-i];
    }
        if (sum != tmp) {
            printf("-1\n");
            return 0;
        }
    printf("%lld\n", a[x][y]);
    return 0;
}