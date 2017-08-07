#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

int T, i, j;
char a[20][30];
int b[10];

inline int work(int now) {
    bool f[10];
    memset(f, 0, sizeof(f));
    f[1] = (a[1][now + 1] == 'X');
    f[2] = (a[2][now] == 'X');
    f[3] = (a[2][now + 3] == 'X');
    f[4] = (a[4][now + 1] == 'X');
    f[5] = (a[5][now] == 'X');
    f[6] = (a[5][now + 3] == 'X');
    f[7] = (a[7][now + 1] == 'X');
    if (f[1] && f[2] && f[3] && !f[4] && f[5] && f[6] && f[7])
        return 0;
    if (!f[1] && !f[2] && f[3] && !f[4] && !f[5] && f[6] && !f[7])
        return 1;
    if (f[1] && !f[2] && f[3] && f[4] && f[5] && !f[6] && f[7])
        return 2;
    if (f[1] && !f[2] && f[3] && f[4] && !f[5] && f[6] && f[7])
        return 3;
    if (!f[1] && f[2] && f[3] && f[4] && !f[5] && f[6] && !f[7])
        return 4;
    if (f[1] && f[2] && !f[3] && f[4] && !f[5] && f[6] && f[7])
        return 5;
    if (f[1] && f[2] && !f[3] && f[4] && f[5] && f[6] && f[7])
        return 6;
    if (f[1] && !f[2] && f[3] && !f[4] && !f[5] && f[6] && !f[7])
        return 7;
    if (f[1] && f[2] && f[3] && f[4] && f[5] && f[6] && f[7])
        return 8;
    if (f[1] && f[2] && f[3] && f[4] && !f[5] && f[6] && f[7])
        return 9;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        for (i = 1; i <= 7; ++i)
            scanf("%s", a[i]);
        b[1] = work(0);
        b[2] = work(5);
        b[3] = work(12);
        b[4] = work(17);
        printf("%d%d:%d%d\n", b[1], b[2], b[3], b[4]);
    }
    return 0;
}