#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>

using namespace std;

const int MOD = 1e9 + 7;

struct P {
    int x, y;

    inline bool operator == (const P b) const {
        return (x == b.x && y == b.y);
    }

    inline P operator - (const P b) const {
        P C;
        C.x = x - b.x;
        C.y = y - b.y;
        int g = __gcd(abs(C.x), abs(C.y));
        if (g == 0) return C;
        C.x /= g;
        C.y /= g;
        return C;
    }

    inline bool operator < (const P b) const {
        return x < b.x || (x == b.x && y < b.y);
    }

};

inline int upd(int &x, int y) {
    x = x + y;
    if (x >= MOD) x -= MOD;
    if (x < 0) x += MOD;
    return 0;
}

P a[1010];
P b[1010];
int z[1010];
int n, i, tt, l, j, m, tmp;
int ans;

int main() {
    z[0] = 1;
    for (i = 1; i < 1010; ++i)
        z[i] = z[i-1] * 2 % MOD;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d", &n);
        ans = 0;
        for (i = 0; i < n; ++i) {
            scanf("%d%d", &a[i].x, &a[i].y);
        }
        sort(a, a+n);
        for (i = 0; i < n; ++i) {
            m = 0;
            for (j = i+1; j < n; ++j) {
                ++m;
                b[m-1] = a[j] - a[i];
            }
            sort(b, b+m);
            l = 0;
            tmp = 0;
            for (j = 0; j < m; ++j)
                if (b[j].x == 0 && b[j].y == 0)
                    ++tmp;
            upd(ans, z[tmp] - 1);
            for (j = tmp; j < m; ++j) {
                if (j != tmp && b[j] == b[j-1]) {
                    ++l;
                } else {
                    upd(ans, 1ll * z[tmp] * (z[l] - 1) % MOD);
                    l = 1;
                }
            }
            upd(ans, 1ll * z[tmp] * (z[l] - 1) % MOD);
        }
        printf("%d\n", ans);
    }
    return 0;
}
