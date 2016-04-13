#include<cstdio>
#include<algorithm>
#include<cstring> 
using namespace std;

int a[102][102];
int n, i, j;

int main() {
    memset(a, 0, sizeof(a));
    scanf("%d", &n);
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= i; ++j)
            scanf("%d", &a[i][j]);
    for (i = n-1; i > 0; --i)
        for (j = 1; j <= i; ++j)
            a[i][j] = max(a[i+1][j], a[i+1][j+1]) + a[i][j];
    printf("%d\n",a[1][1]);
    return 0;
}
