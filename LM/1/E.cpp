#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int op, n, k, t, now, i;

int main() {
    scanf("%d%d", &n, &k);
    for (i = 1; i <= n - k; ++i)
        printf("%d ", i);
    now = n - k; op = 1; t = k;
    while (t != 0) {
        now += op * t;
        printf("%d ", now);
        op = -op;
        t = t - 1;
    }
    printf("\n");
    return 0;
}