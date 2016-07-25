#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

int k, n, ans, i;

int main() {
    ans = 0;
    scanf("%d%d", &n, &k);
    for (i = 2; i <= n; ++i) {
        ans = (ans + k) % i;
    }
    printf("%d\n", ans + 1);
    return 0;
}
