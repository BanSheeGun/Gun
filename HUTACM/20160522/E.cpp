#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

char t[5010];
int a[5010][5010], s3[5010][5010];
int n, i, j, s, m, ans, l, r;
int s1[5010], s2[5010];

int main() {
    scanf("%s", t);
    n = strlen(t);
    memset(a, 0 ,sizeof(a));
    for (i = 1; i <= n; ++i)
        a[i][i] = 1;
    for (i = 1; i < n; ++i)
        if (t[i-1] == t[i])
            a[i][i+1] = 1;

    for (i = 3; i <= n; ++i)
        for (j = 1; j <= n - i + 1; ++j)
            if (t[j-1] == t[j+i-2] && a[j+1][j+i-2] == 1)
                a[j][j+i-1] = 1;

    s = 0;
    memset(s1, 0, sizeof(s1));
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; ++j) {
            s += a[i][j];
            s1[i] += a[i][j];
        }
    for (i = 1; i <= n; ++i)
        s1[i] += s1[i-1];


    memset(s2, 0, sizeof(s1));
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; ++j) {
            s2[j] += a[i][j];
        }
    for (i = n; i >= 1; --i)
        s2[i] += s2[i+1];

    memset(s3, 0, sizeof(s3));
    for (i = 1; i <= n; ++i)
        for (j = n; j >= 1; --j) {
            s3[i][j] = a[i][j] + s3[i][j+1];
    }
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; ++j) {
            s3[i][j] = s3[i][j] + s3[i-1][j];
    }

    scanf("%d", &m);
    while (m--) {
        scanf("%d%d", &l, &r);
        ans = s - s1[l-1] - s2[r+1] + s3[l-1][r+1];
        printf("%d\n", ans);
    }
    return 0;
}
