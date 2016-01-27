#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int f[400200];
int e[400200];
int s[400200];
int list[400200];
int head[400200];
int next[400200];
int ans, i, n, m, k, x, y ,z;

int find(int x) {
    if (f[x] == x)
        return x;
    f[x] = find(f[x]);
    return f[x];
}

int main()
{
    memset(head,0,sizeof(head));
    memset(next,0,sizeof(next));
    scanf("%d%d",&n,&m);
    for (i = 1;i <= m;++i) {
        scanf("%d%d",&x,&y);
        e[i*2-1] = y;
        next[i*2-1] = head[x];
        head[x] = i*2-1;
        e[i*2] = x;
        next[i*2] = head[y];
        head[y] = i*2;
    }
    for (i = 0;i < n; ++i) {
        f[i] = i;
        s[i] = 1;
    }
    scanf("%d",&m);
    for (i = 1;i <= m; ++i) {
        scanf("%d",&list[i]);
        s[list[i]] = 0;
    }
    ans = n - m;
    for (i = 0;i < n; ++ i) {
        if (s[i]) {
            for (k = head[i];k != 0;k = next[k]) {
                x = i;
                y = e[k];
                if (s[y]) {
                    int fx = find(x);
                    int fy = find(y);
                    if (fx == fy) {
                    } else {
                        --ans;
                        f[fx] = fy;
                    }
                }
            }
        }
    }
    z = ans;
    for (i = m;i >= 1; --i) {
        x = list[i];
        ++ans;
        s[x] = 1;
        for (k = head[x];k != 0;k = next[k]) {
            y = e[k];
            if (s[y]) {
                int fx = find(x);
                int fy = find(y);
                if (fx == fy) {
                } else {
                    --ans;
                    f[fx] = fy;
                }
            }
        }
        list[i] = ans;
    }
    for (i = 1;i <= m; ++i)
        printf("%d\n",list[i]);
    printf("%d\n",z);
    return 0;
}
