#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

char a[1010][1010];
int h[1010], l[1010];
int total, tmp, n, m, i, j;

int main() {
    scanf("%d%d", &n, &m);
    total = 0;
    memset(h, 0 ,sizeof(0));
    memset(l, 0, sizeof(0));
    for (i = 1; i <= n; ++i) {
        scanf("%s", a[i]);
        for (j = 1; j <= m; ++j)
            if (a[i][j-1] == '*') {
                ++h[i];
                ++l[j];
                ++total;
            }
    }

    for (i = 1; i <= n; ++i)
        for (j = 1; j <= m; ++j) {
            tmp = h[i] + l[j];
            if (a[i][j-1] == '*')
                --tmp;
            if (tmp == total) {
                printf("YES\n");
                printf("%d %d\n", i, j);
                return 0;
            }
        }
    printf("NO\n");
    return 0;
}