#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int f[200010];
int q[200010];
int ans, i, n, k, x, y, fx, fy, d;

int find(int x) {
    if (f[x] == x)
        return x;
    int fx = find(f[x]);
    q[x] = q[f[x]] + q[x];
    f[x] = fx;
    return f[x];
}

int main() {
    while (~scanf("%d%d",&n, &k) ) {

        for (i = 0;i <= n; ++i) {
            f[i] = i;
            q[i] = 0;
        }
    
        ans = 0;
        for (i = 1;i <= k; ++i) {
            scanf("%d%d%d",&x,&y,&d);
            x--; 
            fx = find(x);
            fy = find(y);
            if (fx == fy) {
                if (q[x] != q[y] + d) {
                    ++ans; 
                } 
            } else {
                f[fx] = fy;
                q[fx] = q[y] - q[x] + d;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
