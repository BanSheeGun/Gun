#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;

inline bool cmp(int a, int b) {
    return a < b;
}

int n, c, i, m, k, t, x, y, T;
int v[100010];
double vv;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &c);
        for (i = 1; i <= n; ++i)
            scanf("%d%d%d", &v[i], &x, &y);
        sort(v+1, v+n+1, cmp);
        scanf("%d", &m);
        while(m--) {
            scanf("%d%d", &t, &k);
            vv = v[k];
            vv = vv * vv + 2.0 * c * t;
            vv = sqrt(vv);
            printf("%.3lf\n", vv);
        }
    }
    return 0;
}