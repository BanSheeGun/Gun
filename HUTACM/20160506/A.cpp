#include<cstdio>
#include<algorithm>
#include<cstring> 
using namespace std;

int a[110][110];
int ma[110];
int na[110];
int n, m, i, j, ans;

int main() {
    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; ++i)
        for (j = 1; j <= n; ++j) 
            scanf("%d", &a[i][j]);

    memset(na, 0, sizeof(na));
    for (i = 1; i <= m; ++i) {
        ma[i] = 1;
        for (j = 1; j <= n; ++j) 
            if (a[i][ma[i]] < a[i][j])
                ma[i] = j;
        ++na[ma[i]];
    }
    ans = 1;
    for (i = 1; i <= n; ++i)
        if (na[i] > na[ans])
            ans = i;
    printf("%d\n", ans);
    return 0;
}
