#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

map<ll, int> v;
ll i;
char a[1000010];

int main() {
    v.clear();
    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", a);
        ll k = 0;
        int l = strlen(a);
        for (i = 1; i < l; ++i) {
            int tmp = (a[i] - a[i-1] + 26) % 26;
            k = (k * 26) + tmp % mod;
        }
        v[k] = 1;
    }
    int ans = 0;
    for (auto i : v) {
        ++ans;
    }
    printf("%d\n", ans);
    return 0;
}