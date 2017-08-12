#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

inline bool cmp(const int & a, const int & b) {
    return a < b;
}

ll a[10040];
int b[60];
int n, m, i, now, ma, T;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (i = 0; i <= m; ++i)
            scanf("%lld", &a[i]);
        for (i = 1; i <= n; ++i) {
            now = 1;
            while (a[now] == 0)
                ++now;
            b[i] = now;
            for (now = 0; now <= m; ++now)
                if (a[now] != 0)
                    a[now + b[i]] -= a[now];
        }
        sort(b+1, b+1+n, cmp);
        for (i = 1; i < n; ++i)
            printf("%d ", b[i]);
        printf("%d\n", b[n]);
    }
    return 0;
}