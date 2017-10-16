#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int a[100];
int b[100];
int n, m, x, ma, mb, i;

int main() {
    scanf("%d%d", &n, &m);
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    ma = 10;
    mb = 10;
    while (n--) {
        scanf("%d", &x);
        a[x] = 1;
        ma = min(ma, x);
    }
    while (m--) {
        scanf("%d", &x);
        b[x] = 1;
        mb = min(mb, x);
    }
    for (i = 1; i <= 9; ++i)
        if (a[i] == 1 && b[i] == 1) {
            printf("%d\n", i);
            return 0;
        }
    if (ma < mb)
        printf("%d%d\n", ma, mb);
    else
        printf("%d%d\n", mb, ma);
    return 0;
}