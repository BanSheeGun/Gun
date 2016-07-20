#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int f[100010];
int a, b, n, i;

int main() {
    scanf("%d%d", &a, &b);
    if (b < a) {
        printf("-1\n");
        return 0;
    }
    memset(f, 0, sizeof(f));
    f[b] = 1;
    for (n = b; n > a; --n) {
        for (i = 1; i <= sqrt(n); ++i)
            if (n % i == 0) {
                if (f[n-i] == 0)
                    f[n-i] = f[n]+1;
                else
                    f[n-i] = min(f[n-i], f[n]+1);
                if (f[n-n/i] == 0)
                    f[n-n/i] = f[n]+1;
                else
                    f[n-n/i] = min(f[n-n/i], f[n]+1);
            }
    }
    printf("%d\n", f[a]-1);
    return 0;
}