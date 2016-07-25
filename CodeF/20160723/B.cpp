#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

bool h[100010];
bool l[100010];
long long ans, n, m, a, b;
int x, y;

int main() {
    scanf("%I64d%I64d", &n, &m);
    ans = n * n;
    memset(h, 0, sizeof(h));
    memset(l, 0, sizeof(l));
    a = n;
    b = n;
    while (m--) {
        scanf("%d%d", &x, &y);
        if (h[x] == 0) {
            ans -= b;
            h[x] = 1;
            --a;
        }
        if (l[y] == 0) {
            ans -= a;
            l[y] = 1;
            --b;
        }
        if (m != 0)
            printf("%I64d ", ans);
        else
            printf("%I64d\n", ans);
    }
    return 0;
}