#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

int T, TT, s, i, n, f, p, ans;
int a[20];

int work() {
    f = 1; p = n;
    if (ans == s / 2) return 0;
    while (1) {
        ++ans;
        if (a[f] == 0)
            ++f;
        if (a[p] == 0)
            --p;
        if (ans % 2 == 1) {
            --a[f];
        } else {
            --a[p];
        }
        if (f == p) return 0;
        if (ans == s / 2) return 0;
    }
    return 0;
}

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    scanf("%d", &T);
    for (TT = 1; TT <= T; ++TT) {
        scanf("%d", &n); s = 0;
        for (i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            s += a[i];
        }
        sort(a+1, a+1+n, cmp);
        ans = 0;
        work();
        printf("Case #%d: %d\n", TT, ans);
    }     
    return 0;
}