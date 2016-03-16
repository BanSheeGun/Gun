#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map> 
using namespace std;

struct Point {
    int x, y;
    bool used; 
};

struct Op {
    int op;
    int k; 
    int ans; 
};

Point p[20010];
Op q[50010];
int f[20010];
int l[20010];
char aa[20];
int ans, i, n, m, k, x, y, fx, fy, d;

int find(int x) {
    if (f[x] != x)
        f[x] = find(f[x]);
    return f[x];
}

map < int , int > a [10010];

int main() {
    bool tt = 0;
    while (~scanf("%d",&n)) {
        if (tt)
            printf("\n");
        tt = 1;
        for (i = 0;i < n; ++i) {
            scanf("%d",&l[i]);
            a[i].clear();
            f[i] = i;
        }
        
        scanf("%d", &k);
        for (i = 1;i <= k; ++i) {
            scanf("%d%d",&p[i].x, &p[i].y);
            if (p[i].x > p[i].y) swap(p[i].x, p[i].y);
            a[p[i].x][p[i].y] = i;
            p[i].used = 1;
        }
        
        scanf("%d",&m);
        for (i = 1;i <= m; ++i) {
            scanf("%s", aa);
            if (aa[0] == 'd') {
                q[i].op = 1;
                scanf("%d%d",&x,&y);
                if (x > y) swap(x, y);
                q[i].k = a[x][y];
                p[q[i].k].used = 0;
            } else {
                q[i].op = 0;
                scanf("%d",&x);
                q[i].k = x;
            }
        }
       
        for (i = 1;i <= k; ++i) {
            if (p[i].used) {
                fx = find(p[i].x);
                fy = find(p[i].y);
                if (l[fx] < l[fy] || (l[fx] == l[fy] && fy < fx)) {
                    f[fx] = fy;
                } else {
                    f[fy] = fx;
                }
            }
        }
     
        for (i = m;i >= 1; --i) {
            if (q[i].op == 0) {
                fx = find(q[i].k);
                if (l[fx] == l[q[i].k]) {
                    q[i].ans = -1;
                } else {
                    q[i].ans = fx;
                }
            } else {
                fx = find(p[q[i].k].x);
                fy = find(p[q[i].k].y);
                if (l[fx] < l[fy] || (l[fx] == l[fy] && fy < fx)) {
                    f[fx] = fy;
                } else {
                    f[fy] = fx;
                }
            }
        }
       
        for (i = 1;i <= m; ++i)
            if (q[i].op == 0)
                printf("%d\n",q[i].ans);
    }
    return 0;
}
