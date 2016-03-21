#include<cstdio>
#include<cstdlib>
#include<cstring> 
#include<string> 
using namespace std;

int change[100010];
int f[100010];
int num[100010];
int sum[100010];
int x, y, n, m, i, fx, fy, op;

int find(int x) {
    if (change[x] == 0) {
        if (f[x] != x) f[x] = find(f[x]);
        return f[x];
    } else {
        if (change[x] != x) change[x] = find(change[x]);
        return change[x];
    }
}

int main() {
    while (~scanf("%d%d",&n, &m)) {
        for (i = 1;i <= n; ++i) {
            f[i] = i;
            change[i] = 0;
            num[i] = 1;
            sum[i] = i;
        }
        while (m != 0) {
            m--;
            scanf("%d",&op);
            switch (op) {
                case (1) : {
                    scanf("%d%d", &y, &x);
                    fx = find(f[x]);
                    fy = find(f[y]);
                    if (fx == fy) break; 
                    if (change[fy] == 0)
                        f[fy] = fx;
                    else
                        change[fy] = fx;
                    num[fx] += num[fy];
                    sum[fx] += sum[fy];
                    break;
                }
                case (2) : {
                    scanf("%d%d", &y, &x);
                    fx = find(f[x]);
                    fy = find(f[y]);
                    if (fx == fy) break; 
                    sum[fy] -= y;
                    num[fy] -= 1;
                    if (change[y] == 0) {
                        change[y] = f[y];
                    }
                    f[y] = fx;
                    num[fx] += 1;
                    sum[fx] += y;
                    break;
                }
                case (3) : {
                    scanf("%d", &x);
                    fx = find(f[x]);
                    printf("%d %d\n",num[fx], sum[fx]);
                    break;
                } 
                default : break;
            }
        }
    } 
    return 0;
}
