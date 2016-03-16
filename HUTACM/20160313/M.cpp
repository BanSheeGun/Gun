#include<cstdio>
#include<cstdlib>
#include<cstring> 
#include<string> 
using namespace std;

int f[100010];
int d[200010];
int ans, i, n, m, k, x, y, fx, fy, top;

int find(int x) {
    if (f[x] != x) f[x] = find(f[x]);
    return f[x];
}

int main() {
    scanf("%d%d",&x,&y);
    while (x != -1 || y != -1) {
        n = 100010;
        for (i = 1;i <= n; ++i)
            f[i] = i;
        ans = 1;
        top = 0;
        while (x != 0 || y != 0) {
            ++top;
            d[top] = x;
            ++top;
            d[top] = y; 
            if (ans == 0 || x == y) {
                scanf("%d%d",&x,&y);
                continue;
            }
            fx = find(x);
            fy = find(y);
            if (fx == fy) {
                ans = 0;
            } else {
                f[fx] = fy;
            }
            scanf("%d%d",&x,&y);
        }
        fx = find(d[1]);
        for (i = 2;i <= top;++i) {
            fy = find(d[i]);
            if (fx != fy) {
                ans = 0;
                break;
            }
        }
        if (ans == 1) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
        scanf("%d%d",&x,&y);
    }
    return 0;
}
