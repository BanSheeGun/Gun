#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
struct Point {
    int l, r;
};

int a[100010];
int t[100010];
Point b[100010], c[100010];
int sum, i, n, r, top, l, OK, tmp;

inline void work() {
    if (l == 0 || r > n)
        return;
    if (i != 1 && l == c[i-1].r)
        return;
    if (i != top && r == c[i+1].l)
        return;
    if (a[l] > a[r]) {
        t[l] = 1;
        t[r] = 1;
        b[i].l = l;
        b[i].r = r;
        OK = 1;
    }
    return;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        memset(t, 0, sizeof(t));
        top = 0;
        for (i = 1; i <= n; i = r) {
            r = i+1;
            while (r <= n && a[r-1] > a[r]) {
                t[r] = 1;
                ++r;
            }
            if (r != i + 1) {
                t[i] = 1;
                ++top;
                b[top].l = i;
                b[top].r = r-1;
            }
        }

        OK = 1;
        while (OK) {
            OK = 0;
            tmp = 0;
            for (i = 1; i <= top; ++i)
                c[i] = b[i];
            for (i = 1; i <= top; ++i) {
                l = b[i].l - 1;
                r = b[i].r + 1;
                work();
                if (i != 1)
                    if (b[i].l <= b[tmp].r + 1) {
                        b[tmp].r = b[i].r;
                        OK = 1;
                        continue;
                    }
                b[++tmp] = b[i];
            }
            top = tmp;
        }

        sum = 0;
        for (i = 1; i <= n; ++i)
            if (t[i] == 0)
                sum++;
        printf("%d\n", sum);
        for (i = 1; i <= n; ++i)
            if (t[i] == 0)
                printf("%d ", a[i]);
        puts("");
    }
    return 0;
}