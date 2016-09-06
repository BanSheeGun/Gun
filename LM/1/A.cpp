#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int n;
long long x, y, x1, x2, y1, y2;

int main() {
    scanf("%d", &n);
    n--; scanf("%lld%lld", &x, &y);
    x1 = x; x2 = x; y1 = y; y2 = y;
    while (n--) {
        scanf("%lld%lld", &x, &y);
        x1 = max(x, x1);
        x2 = min(x, x2);
        y1 = max(y, y1);
        y2 = min(y, y2);
    }
    x = x1 - x2; y = y1 - y2;
    x = max(x, y);
    x = x * x;
    printf("%lld\n", x);
    return 0;
}