#include<cstdio>
#include<algorithm>
#include<cstring> 
using namespace std;

long long f[51];
int n, i, j;

int main() {
    while(~scanf("%d", &n)) {
        f[1] = 1;
        f[2] = 2;
        for (i = 3; i <= n; ++i) {
            f[i] = f[i-1] + f[i-2];
        }
        printf("%I64d\n", f[n]);
    }
    return 0;
}
