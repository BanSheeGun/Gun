#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

int T, n, a, b, c, d, e, f, g, ans;

inline int work() {
    scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
    int a1 = a - d - f + g;
    int b1 = b - d - e + g;
    int c1 = c - e - f + g;
    int d1 = d - g;
    int e1 = e - g;
    int f1 = f - g;
    if (a1 < 0 || b1 < 0 || c1 < 0 || d1 < 0 || e1 < 0 || f1 < 0)
        return 0;
    return a1 + b1 + c1 + d1 + e1 + f1 + g;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        ans = 0;
        while (n--) {
            ans = max(ans, work());
        }
        printf("%d\n", ans);
    }
    return 0;
}