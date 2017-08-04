#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

char a[200][200];
int n, m, i;

inline bool check(char ch) {
    int lx = n+1, rx = 0;
    int ly = m, ry = -1;
    int i, j;
    for (i = 1; i <= n; ++i)
        for (j = 0; j < m; ++j)
            if (a[i][j] == ch) {
                lx = min(lx, i);
                rx = max(rx, i);
                ly = min(ly, j);
                ry = max(ry, j);
            }

    for (i = lx; i <= rx; i++)
        for (j = ly; j <= ry; ++j)
            if (a[i][j] != ch)
                return 0;
    int x = rx - lx + 1;
    int y = ry - ly + 1;
    if (x * y * 3 == m * n && (x == n || y == m))
        return 1;
    else
        return 0;
}

int main() {
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; ++i)
        scanf("%s", a[i]);

    bool ans = 1;
    ans = ans & check('R');
    ans = ans & check('G');
    ans = ans & check('G');
    if (ans)
        puts("YES");
    else
        puts("NO");
    return 0;
}