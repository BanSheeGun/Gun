#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int f[50010];
int q[50010];
int ans, i, n, k, x, y, fx, fy, d;

int find(int x) {
    if (f[x] == x)
        return x;
    int fx = find(f[x]);
    q[x] = (q[f[x]] + q[x]) % 3;
    f[x] = fx;
    return f[x];
}

int main() {
    scanf("%d%d",&n, &k);
    for (i = 1;i <= n; ++i) {
        f[i] = i;
        q[i] = 0;
    }
    
    ans = 0;
    for (i = 1;i <= k; ++i) {
        scanf("%d%d%d",&d,&x,&y);
        if (x > n || y > n) {
            ++ans;
        } else {
            fx = find(x);
            fy = find(y);
            if (fx == fy) {
                if (q[x] != (q[y] + d - 1) % 3) {
                    ++ans; 
                } 
            } else {
                f[fx] = fy;
                q[fx] = (q[y] - q[x] + d + 2) % 3;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
