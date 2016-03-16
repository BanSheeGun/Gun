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
    scanf("%d%d",&n,&m);
    while (n != 0 || m != 0) {
        ans = 0;
        for (i = 0;i < n; ++i)
            f[i] = i;
        while (m--) {
            scanf("%d",&k);
            k--;
            scanf("%d",&x);
            while (k--) {
                scanf("%d",&y);
                fx = find(x);
                fy = find(y);
                f[fx] = fy;
            }
        }
        for (i = 0;i < n;++i)
            if (find(0) == find(i)) 
                ++ans;
        printf("%d\n",ans);
        scanf("%d%d",&n,&m);
    }
    return 0;
}
