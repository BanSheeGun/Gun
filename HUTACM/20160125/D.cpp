#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int a[500000];
int b[500000];
int n, i, j;

int p() {
    int i;
    printf("%d",a[a[0]]);
    for (i = a[0]-1;i > 0;--i) {
        printf("%d",a[i] / 10000 % 10);
        printf("%d",a[i] / 1000 % 10);
        printf("%d",a[i] / 100 % 10);
        printf("%d",a[i] / 10 % 10);
        printf("%d",a[i] % 10);
    }
    printf("\n");
}

int main()
{
    while (~scanf("%d",&n)) {
        memset(a, 0, sizeof(a));
        a[0] = 1;
        a[1] = 1;
        for (i = 2;i <= n; ++i) {
            b[0] = a[0];
            b[1] = 0;
            for (j = 1;j <= a[0]; ++j) {
                b[j] += a[j] * i;
                b[j+1] = b[j] / 100000;
                b[j] = b[j] % 100000;
                a[j] = b[j];
            }
            while (b[b[0] + 1] != 0) {
                ++b[0];
                b[b[0] + 1] = b[b[0]] / 100000;
                b[b[0]] = b[b[0]] % 100000;
                a[b[0]] = b[b[0]];
            }
            a[0] = b[0];
        }
        p();
    }
    return 0;
}
