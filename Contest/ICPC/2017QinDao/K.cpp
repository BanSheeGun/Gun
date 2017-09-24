#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

ll a[1000010];
ll i, n;
int T;

int main() {
    i = 1;
    memset(a, 0, sizeof(a));
    while ((3 * i * i + 3 * i + 1) <= 1e12) {
        a[i] = 3 * i * i + 3 * i + 1;
        i++;
    }
    i--;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld", &n);
        int tmp = lower_bound(a+1, a+1+i, n) - a;
        if (a[tmp] == n)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}