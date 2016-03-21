#include<cstdio>
#include<cstdlib>
#include<cstring> 
#include<string> 
using namespace std;

int f[100010];
int p[100010];
int t[100010];
int ans, i, n, m, k, x, y, fx, fy, top;

int find(int x) {
    if (f[x] != x) f[x] = find(f[x]);
    return f[x];
}

int main() {
    scanf("%d%d",&x,&y);
    int test = 0; 
    while (x != -1 || y != -1) {
        ++test;
        n = 100010;
        for (i = 1;i <= n; ++i) {
            f[i] = i;
            t[i] = 1;
        }
        ans = 1;
        n = 0;
        top = 0;
        while (x != 0 || y != 0) {
            top ++;
            if (t[x]) {
                ++n;
                p[n] = x;
                t[x] = 0;
            }
            if (t[y]) {
                ++n;
                p[n] = y;
                t[y] = 0;
            }
            if (ans == 0 || x == y) {
                scanf("%d%d",&x,&y);
                continue;
            }
            fx = find(x);
            fy = find(y);
            if (fy == y) {
                f[fy] = fx;
            } else {
                ans = 0; 
            }
            scanf("%d%d",&x,&y);
        }
        
        if (top != n-1)
            ans = 0;
        if (n == 0)
            ans = 1;
        
        if (ans == 1) {
            printf("Case %d is a tree.\n", test);
        } else {
            printf("Case %d is not a tree.\n", test);
        }
        scanf("%d%d",&x,&y);
    }
    return 0;
}
