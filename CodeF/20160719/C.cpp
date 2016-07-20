#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

int f[200];
int r[200];
int s[200];
int n, i, ans, now, la;

int main() {
    memset(r, 0 ,sizeof(r));
    scanf("%d", &n);
    for (i = 0; i <= n; ++i) f[i] = 1000;
    for (i = 0; i <= n; ++i) s[i] = 1000;
    la = 0;
    for (i = 1; i <= n; ++i) {
        scanf("%d", &now);
        if (now > 1) {
            s[i] = r[i-1];
            if (la % 2 == 1) {
                s[i] = min(s[i], f[i-1]);
            }
        }

        if (now % 2 == 1) {
            f[i] = r[i-1];
            if (la > 1) {
                f[i] = min(f[i], s[i-1]);
            }
        }

        r[i] = r[i-1];
        if (la % 2 == 1) r[i] = min(r[i], f[i-1]);
        if (la > 1) r[i] = min(r[i], s[i-1]);
        r[i]++;
        la = now;
    }
    ans = r[n];
    if (la % 2 == 1) ans = min(ans, f[n]);
    if (la > 1) ans = min(ans, s[n]);
    printf("%d\n", ans);
    return 0;
}