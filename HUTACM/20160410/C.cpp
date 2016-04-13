#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int f[2][5010];
char p[5010], q[5010];
int la, lb, i, j;

int main() {
    scanf("%d", &la);
    lb = la;
    scanf("%s", p);
    for (i = 0; i < la; ++i)
        q[la - i - 1] = p[i];
    memset(f, 0, sizeof(f));

    for (i = 1; i <= la; ++i)
        for (j = 1; j <= lb; ++j) {
            f[i % 2][j] = max(f[i % 2][j], f[(i-1) % 2][j-1]);
            f[i % 2][j] = max(f[i % 2][j], f[(i-1) % 2][j]);
            f[i % 2][j] = max(f[i % 2][j], f[i % 2][j-1]);
            f[i % 2][j] = max(f[i % 2][j], f[(i-1) % 2][j-1] + (int)(p[i-1] == q[j-1]));
        }
    printf("%d\n", la - f[la  % 2][lb]);
    return 0;
}
