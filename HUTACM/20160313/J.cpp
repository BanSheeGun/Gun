#include<cstdio>
#include<cstdlib>

using namespace std;

int f[20020];
int r[20020];
bool ans;
int n, i, x, y, fx, fy, t, tt, m, ttt;

int find(int x) {
    if (f[x] == x)
        return x;
    int t = find(f[x]);
    r[x] = (r[f[x]] + r[x]) % 2;
    f[x] = t;
    return f[x];
}

int main() {
    scanf("%d",&tt);
    for (ttt = 1;ttt <= tt;++ttt) {
        ans = 1;
        scanf("%d%d",&n,&m);
        for (i = 1;i <= n; ++i) {
            f[i] = i;
            r[i] = 0;
        }

        for (i = 1;i <= m; ++i) {
            scanf("%d%d",&x,&y);
            if (ans == 0) continue;
            fx = find(x);
            fy = find(y);
            if (fx == fy) {
                if (r[x] == r[y])
                    ans = 0;
            } else {
                r[fx] = (r[x] + r[y] + 1) % 2;
                f[fx] = fy;
            }
        }
        printf("Scenario #%d:\n",ttt);
        if (ans == 1)
            printf("No suspicious bugs found!\n");
        else
            printf("Suspicious bugs found!\n");
        printf("\n");
    }
    return 0;
}
