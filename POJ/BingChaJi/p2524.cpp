#include<cstdio>
#include<cstdlib>
using namespace std;

int f[50010];
int ans, i, n, m, k, x, y, fx, fy;

int find(int x) {
    if (f[x] != x)
        f[x] = find(f[x]);
    return f[x];
}

int main() {
    int t = 0;
    scanf("%d%d",&n,&m);
    while (n != 0 || m != 0) {
        ++t;
        ans = n;
        for (i = 1;i <= n; ++i)
            f[i] = i;
        while (m--) {
            scanf("%d%d",&x,&y);
            fx = find(x);
            fy = find(y);
            if (fx != fy) {
                --ans;
                f[fx] = fy;
            }
        }
        printf("Case %d: %d\n",t,ans);
        scanf("%d%d",&n,&m);
    }
    return 0;
}