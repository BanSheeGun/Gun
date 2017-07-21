#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll a[2];
int n, i;
int main() {
    scanf("%d", &n);
    a[0] = 1;
    a[1] = 1;
    for (i = 2; i <= n; ++i) {
        a[i & 1] = (a[0] + a[1]) % mod;
    }
    printf("%lld\n", a[n & 1]);
    return 0;
}