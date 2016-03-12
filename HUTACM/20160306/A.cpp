#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;

struct St {
    int a[3];
    int step;
    void Pull(int x, int y,int uy) {
        a[y] = a[y] + a[x];
        a[x] = 0;
        if (uy < a[y]) {
            a[x] = a[y] - uy;
            a[y] = uy;
        }
        return;
    }
    void Pr() {
        printf("s%d %d %d %d\n",step,a[0],a[1],a[2]);
    }
};

int t[110][110];
St d[20000];
int u[3];
int f, p, ans;

int check(St a) {
    int ans = 0;
    for (int i = 0; i < 3; ++i) {
        if (a.a[i] == u[0] / 2)
            ++ans;
    }
    return (ans == 2);
}

int bfs() {
    for (f = 1;f <= p; ++f) {
        for (int i = 0;i < 3; ++i)
            for (int j = 0;j < 3; ++j)
                if (i != j && d[f].a[i] != 0) {
                    ++p;
                    d[p] = d[f];
                    d[p].step++;
                    d[p].Pull(i,j,u[j]);
                    if (check(d[p])) {
                        ans = d[p].step;
                        return 0;
                    }
                    if (t[d[p].a[0]][d[p].a[1]] == 1) {
                        --p;
                    } else {
                        t[d[p].a[0]][d[p].a[1]] = 1;
                    }
                }
    }
}

int main() {
    scanf("%d%d%d",&u[0],&u[1],&u[2]);
    while (!(u[0] == 0 && u[1] == 0 && u[2] == 0)) {
        if (u[0] % 2) {
            scanf("%d%d%d",&u[0],&u[1],&u[2]);
            printf("NO\n");
            continue;
        }
        memset(t, 0, sizeof(t));
        p = 1;
        d[1].a[0] = u[0];
        d[1].a[1] = 0;
        d[1].a[2] = 0;
        d[1].step = 0;
        t[u[0]][0] = 1;
        ans = 0;
        bfs();
        if (ans == 0)
            printf("NO\n");
        else
            printf("%d\n",ans);
        scanf("%d%d%d",&u[0],&u[1],&u[2]);
    }
    return 0;
}
