#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

typedef long long LL;
const int N = 2005;
const long long MOD = 1000000007;

LL Inv[N];
LL c[N][N];
LL b[N];
LL m[N];
LL i, j ,n, ans;
int k, t;

LL solve() {
    LL ans = 0;
    for (int i = 1;i <= k+1; ++i) {
        ans += c[k+1][i] * b[k+1 -i] % MOD * m[i] % MOD;
        ans %= MOD;
    }
    ans = ans * Inv[k+1] % MOD;
    return ans;
}

int main() {
    //Init Inv
    Inv[1] = 1;
    for (i = 2;i < N; ++i)
        Inv[i] = (MOD - MOD / i) * Inv[MOD % i] % MOD;

    //Init C
    memset(c, 0, sizeof(c));
    c[0][0] = 1;
    for (i = 1;i < N; ++i) {
        c[i][0] = 1;
        for (j = 1;j <= i; ++j)
            c[i][j] = (c[i-1][j] + c[i-1][j-1]) % MOD;
    }

    //Init B
    memset(b, 0, sizeof(b));
    b[0] = 1;
    for (i = 1;i < N;++i) {
        for (j = 0;j < i; ++j) {
            b[i] += c[i+1][j] * b[j];
            b[i] %= MOD;
        }
        b[i] *= -1 * Inv[i + 1];
        b[i] %= MOD;
        b[i] = (b[i] + MOD) % MOD;
    }

    scanf("%d",&t);
    while (t--) {
        scanf("%lld %d",&n,&k);
        n %= MOD;

        //Init m
        m[0] = 1;
        for (i = 1;i <= N;++i)
            m[i] = m[i-1] * (n+1) % MOD;

        ans = solve();
        printf("%lld\n", ans);
    }
    return 0;
}
