#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;

char a[10000];
long long n;
int ans, i,l;

int main() {
    while (~scanf("%s", a)) {
        l = strlen(a);
        if (l > 14)  {
            printf("TAT\n");
            continue;
        }
        n = 0;
        for (i = 0; i < l; ++i) {
            n = n * 10 + a[i] - 48;
        }
        if (n == 0) {
            printf("TAT\n");
            continue;
        }
        ans = 0;
        while (n != 1) {
            n = sqrt(n);
            ++ans;
        }
        if (ans > 5) {
            printf("TAT\n");
        } else {
            printf("%d\n", ans);
        }
    }
    return 0;
}