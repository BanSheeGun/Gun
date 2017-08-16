#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 5000000;
int prime[N + 10];
int mi[N + 10];
int p[N + 10];
int n, i, j, top;
int ans[2 * N + 10];
int tot;
ll l, r;
map<ll, int> hs;

inline ll find(ll n) {
    if (n <= N)
        return mi[n];
    if (hs[n] != 0)
        return ans[hs[n]];
    ll an = 1;
    for (ll l = 2, r; l <= n; l = r + 1) {
        r = n / (n / l);
        an -= find(n / l) * (r - l + 1); 
    }
    hs[n] = ++tot;
    ans[tot] = an;
    return an;
}

int main() {
    memset(p, 0, sizeof(p));
    tot = 0;
    hs.clear();
    mi[1] = 1;
    top = 0;
    for (i = 2; i <= N; ++i) {
        if (!p[i]) {
            prime[++top] = i;
            mi[i] = -1;
        }
        for (j = 1; j <= top; ++j) {
            if (i * prime[j] > N)
                break;
            p[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
            mi[i * prime[j]] = -mi[i];
        }
    }
    for (i = 2; i <= N; ++i)
        mi[i] += mi[i-1];
    scanf("%lld%lld", &l, &r);
    printf("%lld\n", find(r) - find(l-1));
    return 0;
}