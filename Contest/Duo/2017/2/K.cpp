#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;


int aa[3000][3000];
int n, i, j, k;
ll ans;

struct P {
    int x, y;
} p[600];

int a(int x, int y, int d) {
    if (x + 100 < 0)
        return 0;
    if (y + 100 < 0)
        return 0;
    aa[x + 100][y + 100] += d;
    return aa[x + 100][y + 100];
}

bool pan(int i, int j) {
    int x1 = p[i].x + p[j].x; 
    int y1 = p[i].y + p[j].y;
    int dx = p[i].x - p[j].x;
    int dy = p[i].y - p[j].y;
    if ((x1 + dy) % 2 != 0)
        return 0;
    if ((y1 + dx) % 2 != 0)
        return 0;
    int ax = a((x1 + dy) / 2, (y1 - dx) / 2, 0);
    int ay = a((x1 - dy) / 2, (y1 + dx) / 2, 0);
    ans += ax * ay;
    return 0;
}

int main() {
    while (~scanf("%d", &n)) {
        memset(aa, 0, sizeof(aa));
        for (i = 1; i <= n; ++i) {
            scanf("%d%d", &p[i].x, &p[i].y);
            a(p[i].x, p[i].y, 1);
        }

        ans = 0;
        for (i = 1; i <= n; ++i)
            for (j = 1; j <= n; ++j)
                if (i != j)
                    pan(i, j);

        ans /= 4;
        printf("%lld\n", ans);
    }
    return 0;
}