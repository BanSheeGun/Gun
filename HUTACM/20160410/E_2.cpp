#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

long long a[1010][2010];
long long w[2010];
long long n, i, j, k, m;

bool cmp(int a, int b) {
    return a < b;
}

int main() {
    while(~scanf("%I64d%I64d", &n, &k)) {
        for (i = 1; i <= n; ++i)
            scanf("%I64d", &w[i]);
        sort(w+1, w+1+n, cmp);

        memset(a, 0, sizeof(a));
        for (i = 1; i <= k; ++i) {
            m = a[i-1][i * 2 - 2];
            for (j = i * 2; j <= n; ++j) {
                a[i][j] = m + (w[j] - w[j-1]) * (w[j] - w[j-1]);
                m = min(m, a[i-1][j-1]);
            }
        }
        m = a[k][k*2];
        for (i = k*2; i <= n; ++i)
            m = min(m, a[k][i]);
        printf("%I64d\n", m);
    }
    return 0;
}