/**************************************************************
    Problem: 1013
    User: Gunpowder
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:824 kb
****************************************************************/
 
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
 
const double eps = 1e-6;
 
double f[20];
double a[20][20], k;
int n, i, j, now, to;
 
int main() {
    scanf("%d", &n);
    for (i = 1; i <= n; ++i)
        scanf("%lf", &f[i]);
    for (i = 1; i <= n; ++i) {
        a[i][n+1] = 0;
        for (j = 1; j <= n; ++j) {
            scanf("%lf", &k);
            a[i][j] = 2.0 * (k - f[j]);
            a[i][n+1] += k * k - f[j] * f[j];
        }
    }
 
    now = 1;
    for (i = 1; i <= n; ++i) {
        for (to = now; to <= now; ++to)
            if (fabs(a[to][i]) > eps)
                break;
        for (j = 1; j <= n+1; ++j)
            swap(a[to][j], a[now][j]);
        k = a[now][i];
        for (j = i; j <= n + 1; ++j)
            a[now][j] /= k;
 
        for (j = 1; j <= n; ++j) {
            if (j == now)
                continue;
            k = a[j][i];
            for (int p = i; p <= n+1; ++p)
                a[j][p] -= k * a[now][p];
        }
        now++;
    }
 
    for (i = 1; i < n; ++i)
        printf("%.3lf ", a[i][n+1]);
    printf("%.3lf\n", a[n][n+1]);
    return 0;
}