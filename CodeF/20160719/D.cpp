#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

const int nn = 200010;

int f[nn];
int fa[nn];
int t[nn];
int fx, fy, n, i, ans, pp;

inline int find(int x) {
    if (x != f[x])
        f[x] = find(f[x]);
    return f[x];
}

int main() {
    scanf("%d", &n);
    for (i = 1; i <= n; ++i) {
        f[i] = i;
        scanf("%d", &fa[i]);
    }
    pp = 0;
    for (i = 1; i <= n; ++i) {
        if (fa[i] == i) pp = i;
    }
    ans = 0;
    for (i = 1; i <= n; ++i) {
        if (fa[i] == i) continue;
        fx = find(i);
        fy = find(fa[i]);
        if (fx == fy) {
            ++ans;
            if (pp == 0) {
                pp = i;
                fa[i] = i;
            }
            if (fa[i] == pp) {
                fa[pp] = pp;
            } else {
                fa[i] = pp;
            }
        }
        fx = find(i);
        fy = find(fa[i]);
        f[fx] = fy;
    }

    memset(t, 0, sizeof(t));
    for (i = 1; i <= n; ++i) {
        fx = find(i);
        if (t[fx] == 0) {
            ++ans;
            t[fx] = 1;       
        }
        if (fa[i] == i && fx != find(pp))
            fa[i] = pp;
    }
    printf("%d\n", ans-1);
    for (i = 1; i < n; ++i)
        printf("%d ", fa[i]);
    printf("%d\n", fa[n]);
    return 0;
}