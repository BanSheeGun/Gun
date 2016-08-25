#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int a[100010];
int n, i, d, b, s, k, ans;

int main() {
    scanf("%d%d%d", &n, &b, &d);
    s = 0;
    for (i = 1; i <= n; ++i) {
        scanf("%d", &k);
        if (k > b) continue;
        s += k;
        if (s > d) {
            ++ans;
            s = 0;
        }
    }
    printf("%d\n", ans);
    return 0;
}