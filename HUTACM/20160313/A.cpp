#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int f[1010];
int cx[1010];
int cy[1010];
char a[2];
int t[1010];
int ans, i, n, m, k, x, y, fx, fy, d;

int find(int x) {
    if (f[x] != x)
        f[x] = find(f[x]);
    return f[x];
}

inline int check(int a, int b) {
    int k = (cx[a] - cx[b]) * (cx[a] - cx[b]);
    k += (cy[a] - cy[b]) * (cy[a] - cy[b]);
    return (k <= d * d); 
}

int main() {
    scanf("%d%d",&n, &d); 
    for (i = 1;i <= n; ++i) {
        f[i] = i;
        scanf("%d%d",&cx[i],&cy[i]);
    }
    memset(t, 0, sizeof(t));
    while (~scanf("%s",a)) {
        if (a[0] == 'O') {
            scanf("%d", &x);
            for (i = 1;i <= n;++i) {
                if (t[i] && check(x, i)) {
                    fx = find(x);
                    fy = find(i);
                    f[fx] = f[fy];
                }
                t[x] = 1;
            }
        } else {
            scanf("%d%d",&x,&y);
            fx = find(x);
            fy = find(y);
            if (fx == fy)
                printf("SUCCESS\n");
            else
                printf("FAIL\n"); 
        } 
    }
    return 0;
}
