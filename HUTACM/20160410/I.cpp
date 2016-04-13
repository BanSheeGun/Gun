#include<cstdio>
#include<algorithm>
#include<cstring> 
using namespace std;

int n, i, j, m ,ans, top, t, k;
int a[510];
int f[250010];
int p[250010];
int l[250010];
int s[250010];

int dfs(int k) {
    if (l[k] != 0) {
        dfs(l[k]);
        printf(" %d",a[p[k]]);
    } else {
        printf("%d",a[p[k]]);
    }
    return 0;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (i = 1;i <= n; ++i) {
            scanf("%d",&a[i]);
        }
        top = 0;
        scanf("%d", &m);
        for (j = 1; j <= m; ++j) {
            scanf("%d", &k);
            for (i = n;i >= 1; --i)
                if (k == a[i]) {
                    ++top;
                    p[top] = i;
                }
        }
        memset(f, 0, sizeof(f));
        memset(l, 0, sizeof(l));
        for (i = 1; i <= top; ++i) {
            f[i] = 1;
            for (j = 1; j < i; ++j)
                if (a[p[j]] < a[p[i]] && p[j] < p[i] && f[j]+1 > f[i]) {
                    f[i] = f[j] + 1;
                    l[i] = j;
                }
        }
        for (i = 1, ans = 1; i <= top; ++i) 
            if (f[i] > f[ans])
                ans = i;
        printf("%d\n", f[ans]);
        dfs(ans);
        putchar('\n');
        if (t != 0) putchar('\n');
    }
    return 0;
}
