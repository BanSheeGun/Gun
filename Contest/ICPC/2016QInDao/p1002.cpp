#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

double ans[1000000];
long long i;
int l, x;
char a[10000000];

int main() {
    ans[1] = 1;
    for (i = 2; i <= 999999; ++i)
        ans[i] = ans[i-1] + 1.0 / (i * i);
    while (~scanf("%s", a)) {
        x = 0;
        l = strlen(a);
        if (l > 7) x = 999999;
        else {
            for (i = 0; i < l; ++i)
                x = x * 10 + a[i] - '0';
        }
        printf("%.5lf\n", ans[x]);
    }
    return 0;
}