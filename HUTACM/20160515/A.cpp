#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

int i, j, k, n, t;
int flag;
int a[200];

int main() {
    scanf("%d%d", &n, &t);
    a[1] = 1;
    k = 1;
    for (i = 2; i <= n; ++i) {
        a[i] = 0;
        k = k * 10 % t;
    }
    while (a[n] <= 9 && k % t != 0) {
        a[n]++;
        k++;
    }
    if (a[n] <= 9) {
        for (j = 1; j <=n; ++j)
            printf("%d",a[j]);
        printf("\n");
    } else {
        printf("-1\n");
    }
    return 0;
}
