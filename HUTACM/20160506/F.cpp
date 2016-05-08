#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int f[9][9][400];
int a[9];
char b[10];
int i,j,k,y,z,now,n,m,N, ans;

int main() {
    while(~scanf("%d%d", &n, &m)) {
        if (n == -1) return 0;
    for (i = 1; i <= n; ++i) {
        scanf("%s", b);
        a[i] = 0;
        for (j = 1; j <= n; ++j) {
            a[i] = a[i] * 2;
            if (b[j-1] == '.') ++a[i];
        }
    }
    N = 1 << n;
    N--;
    memset(f,0 ,sizeof(f));
    f[0][0][0] = 1;

    for (i = 1; i <= n; ++i)
        for (j = 1; j <= m; ++j) {
            for (k = 0; k < n; ++k) {
                now = 1 << k;
                if ((now & a[i]) == 0)
                    for (z = 0; z <= N; ++z)
                        for (y = 0; y < i; ++y)
                            if ((z & now) == 0 && f[y][j-1][z] != 0) {
                                f[i][j][z|now] += f[y][j-1][z];
                            }
            }
        }

    ans = 0;
    for (i = 1; i <= n; ++i) {
        for (z = 0; z <= N; ++z)
            ans += f[i][m][z];
    }
    printf("%d\n", ans);
    }
    return 0;
}
