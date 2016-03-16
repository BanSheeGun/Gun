#include<cstdio>
#include<cstdlib>
using namespace std;

int f[30010];
int ans, i, n, m, k, x, y, fx, fy;

int find(int x) {
    if (f[x] != x)
        f[x] = find(f[x]);
    return f[x];
}

int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d",&n,&m);
        for (i = 1;i <= n; ++i)
            f[i] = i;
        ans = n;
        while (m--) {
            scanf("%d%d",&x,&y);
            fx = find(x);
            fy = find(y);
            if (fx != fy) {
                --ans;
                f[fx] = fy;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
