#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int a[1010], b[1010], c[1010];
int f[1010][1010];
int n, i, m, t, l, r;

inline bool cmp(int a, int b) {
    return a < b;
}

inline int work() {
    memset(f, 0, sizeof(f));
    for (i = 1; i <= n; ++i) {
        ++f[a[i]][0];
        f[a[i]][f[a[i]][0]] = i;
    }
    for (i = 0; i <= n; ++i)
        f[i][0] = 0;
    for (i = 1; i <= n; ++i) {
        ++f[b[i]][0];
        c[i] = f[b[i]][f[b[i]][0]];
    }

    for (i = 1; i <= m; ++i) {
        scanf("%d%d", &l, &r);
        sort(c+l, c+r+1, cmp);
    }

    for (i = 1; i <= n; ++i) 
        if (c[i] != i) {
            printf("No\n");
            return 0;
        }

    printf("Yes\n");
    return 0;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (i = 1; i <= n; ++i) {
            scanf("%d", &b[i]);
        }
        for (i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        work();
    }
    return 0;
}