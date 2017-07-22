/**************************************************************
    Problem: 2186
    User: Gunpowder
    Language: C++
    Result: Accepted
    Time:10752 ms
    Memory:264492 kb
****************************************************************/
 
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll N = 10000000;
ll fac[N + 10];
ll Inv[N + 10];
ll ans[N + 10];
bool mark[N + 10];
int pri[5000000];
int T, i, top, j, n, m;
ll R;
 
inline int init() {
    memset(fac, 0, sizeof(fac));
    memset(Inv, 0, sizeof(Inv));
    memset(mark, 0, sizeof(mark));
    top = 0;
    Inv[1] = 1;
    for (i = 2; i <= min(N, R-1); ++i) {
        ll t = R / i;
        ll k = R % i;
        Inv[i] = (R - t) * Inv[k] % R;
    }
    fac[1] = 1;
    for (i = 2; i <= N; ++i)
        fac[i] = fac[i - 1] * i % R;
 
    for (i = 2; i <= N; ++i) {
        if (!mark[i]) {
            pri[++top] = i;
        }
        for (j = 1; j <= top; ++j) {
            if (i * pri[j] > N)
                break;
            mark[i * pri[j]] = 1;
            if (i % pri[j] == 0)
                break;
        }
    }
     
    ans[1] = 1;
    for (i = 2; i <= N; ++i) {
        ans[i] = ans[i - 1];
        if (!mark[i])
            ans[i] = ans[i] * (i - 1) % R * Inv[i % R] % R;
    }
    return 0;
}
 
int main() {
    scanf("%d%lld", &T, &R);
    init();
    while (T--) {
        scanf("%d%d", &n, &m);
        printf("%lld\n", ans[m] * fac[n] % R);
    }
    return 0;
}