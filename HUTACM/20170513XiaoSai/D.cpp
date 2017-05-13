#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>

using namespace std;

int f[20][20];
int i, j, n, m;

int main() {
    while (~scanf("%d%d", &n, &m)) {
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (i = 0; i <= n; ++i)
            for (j = 0; j <= m; ++j)
                if (i < j)
                    f[i][j] = 0;
                else {
                    if (i == 0 || j == 0)
                        f[i][j] = 1;
                    else 
                        f[i][j] = f[i-1][j] + f[i][j-1];
            }
        printf("%d\n", f[n][m]);
    }
    return 0; 
}