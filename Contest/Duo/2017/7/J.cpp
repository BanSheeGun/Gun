#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

int a[200010];
int n, m, i, k, T;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        int k = 1;
        while (k * 4 <= m)
            k *= 4;
        while (m != 0) {
            while (m >= k) {
                for (i = k + 1; i <= n; ++i)
                    a[i] ^= a[i-k];
                m -= k;
            }
            k /= 4;
        }
        for (i = 1; i < n; ++i)
            printf("%d ", a[i]);
        printf("%d\n", a[n]);
    }
    return 0;
}