#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll x, y;
ll l, r, k, i;

int main() {
    scanf("%lld%lld%lld%lld%lld", &x, &y, &l, &r, &k);
    for (i = l; i <= r; ++i) {
        ll tmp = i * k;
        if (x <= tmp && tmp <= y) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}