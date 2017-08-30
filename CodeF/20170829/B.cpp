#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

ll r, d, n, sum, x, y, z, l;

int main() {
    scanf("%lld%lld", &r, &d);
    sum = 0;
    scanf("%lld", &n);
    while (n--) {
        scanf("%lld%lld%lld", &x, &y, &z);
        l = x * x + y * y;
        if ((r - d + z) * (r - d + z) <= l)
            if ((r >= z) && (r - z) * (r - z) >= l)
                ++sum;
    }
    printf("%lld\n", sum);
    return 0;
}