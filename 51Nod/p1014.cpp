#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int p, a, i, t;
int ans[1000010];

int PowMod(int a, int b, int base) {
    int ans = 0;
    a %= base;
    b %= base;
    int now = b;
    while (a != 0) {
        ans += now * (a % 2);
        ans %= base;
        now *= 2;
        now %= base;
        a = a / 2;
    }
    return ans;
}

int main() {
    scanf("%d%d", &p, &a);
    t = 0;
    for (i = 0; i <= p; ++i) {
        if (PowMod(i, i, p) == a) {
            ++t;
            ans[t] = i;
        }
    }

    if (t == 0)
        printf("No Solution\n");
    else {
        for (i = 1; i < t; ++i)
            printf("%d ", ans[i]);
        printf("%d\n", ans[t]);
    }
    return 0;
}