#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

char a[5010];
int f[5010][5010];
int g[5010][5010];
int s[5010];
int n, i, j;

inline bool pan(int l, int r) {
    if (l <= r)
        return f[l][r];
    return 1;
}

inline int q(int l, int r) {
    int mid;
    if ((r - l) % 2 == 0)
        mid = (l + r) / 2 - 1;
    else
        mid = (l + r) / 2;
    if (mid < l)
        return 0;
    return g[l][mid];
}

int main() {
    scanf("%s", a);
    n = strlen(a);
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
    for (i = 0; i < n; ++i)
        f[i][i] = 1;
    memset(s, 0, sizeof(s));
    for (i = 1; i < n; ++i)
        for (j = 0; j + i < n; ++j)
            if (a[j] == a[j+i] && pan(j+1, j+i-1)) {
                f[j][j+i] = 1;
            }
    for (i = 0; i < n; ++i)
        for (j = 0; j + i < n; ++j)
            if (f[j][j+i]) {
                g[j][j+i] = q(j, j + i) + 1;
                ++s[g[j][j+i]];
            }
    for (i = n-1; i > 0; --i)
        s[i] = s[i] + s[i + 1];
    for (i = 1; i < n; ++i)
        printf("%d ", s[i]);
    printf("%d\n", s[n]);
    return 0;
}