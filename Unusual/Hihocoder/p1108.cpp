#include<cstdio>
#include<cstdlib>

using namespace std;

int f[20020];
int r[20020];
bool ans;
int n, i, x, y, fx, fy, t, tt, m;

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
    while (tt--) {
        ans = 1;
        scanf("%d%d",&n,&m);
        for (i = 1;i <= n; ++i) {
            f[i*2-1] = i*2-1;
            f[i*2] = i*2-1;
            r[i*2-1] = 0;
            r[i*2] = 1;
        }

        for (i = 1;i <= m; ++i) {
            scanf("%d%d%d",&x,&y,&t);
            if (ans == 0) continue;
            x = x * 2 - 1 + t;
            y = y * 2 - 1 + t;
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

        if (ans == 1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
