#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int a, b, d, t, te, ans, tmp, p;

int main() {
    scanf("%d", &te);
    while (te--) {
        scanf("%d%d", &a, &b);
        ans = 1000000000;
        if (a <= b) {
            printf("%d\n", b - a);
            continue;
        }
        d = 1; t = 0; tmp = 0;
        while (t < ans) {
            ++t;
            if (a <= b) {
                --t;
                if (a == b)
                    ans = min(ans, t);
                else {
                    p = b - max(0, a) - tmp;
                    if (p < 0) p = 0;
                    ans = min(ans, t + p);
                }
                d = d / 2;
                a = a + d;
                d = 1;
                ++tmp;
            } else {
                a = a - d;
                d = d * 2;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}