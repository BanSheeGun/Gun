#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>

using namespace std;

int f[1000010];
int i, j, top, l, r, ans1, ans2;

int main() {
    memset(f, 0, sizeof(f));
    f[1] = 1;
    for (i = 2; i < 1000000; ++i)
        if (f[i] == 0) {
            for (j = 2 * i; j < 1000000; j += i)
                f[j] = 1;
        }
    top = 0;
    for (i = 1; i < 1000000; ++i)
        if (f[i] == 0)
            f[++top] = i;

    scanf("%d%d", &l, &r);
    ans1 = 0;
    ans2 = 0;
    for (i = 1; i <= top; ++i) {
        int tmp1 = (l - 1) / f[i];
        int tmp2 = r / f[i];
        tmp2 -= tmp1;
        if (tmp2 > ans1) {
            ans1 = tmp2;
            ans2 = f[i];
        } 
    }

    if (ans1 != 0) {
        printf("%d\n", ans2);
        return 0;
    }

    for (i = l; i <= r; ++i) {
        int tmp1 = (l - 1) / i;
        int tmp2 = r / i;
        tmp2 -= tmp1;
        if (tmp2 > ans1) {
            ans1 = tmp2;
            ans2 = i;
        } 
    }

    printf("%d\n", ans2);
    return 0; 
}