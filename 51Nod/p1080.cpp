#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;

int n, i, t, flag;

int main() {
    flag = 0;
    scanf("%d", &n);
    for (i = 0; i <= n; ++i) {
        if (2 * i * i > n)
            break;
        t = n - i * i;
        t = sqrt(t);
        if (t * t + i * i == n) {
            flag = 1;
            printf("%d %d\n", i, t);
        }
    }
    if (flag == 0)
        printf("No Solution\n");
    return 0;
}