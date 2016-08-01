#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const long long MOD = 1000000007;

long long n;

struct Ma {
    long long a[101][101];

    Ma() {
        memset(a, 0, sizeof(a));
    }

    inline Ma operator * (const Ma b) const {
        Ma c;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                for (int k = 1; k <= n; ++k)
                    c.a[i][j] = (c.a[i][j] + a[i][k] * b.a[k][j]) % MOD;
        return c;
    }
};

Ma e, a, t;
long long b[110], ans, i, j, k;

inline Ma f(long long n) {
    if (n == 0)
        return e;
    if (n == 1)
        return a;
    Ma t = f(n/2);
    t = t * t;
    if (n % 2 == 1)
        t = t * a;
    return t;
}

bool can(long long x,long long y){
    long long r=x^y;
    int sum=0;
    while(r){
        sum+=r&1;
        r>>=1;
    }
    return sum%3==0;
}

int main() {
    scanf("%I64d%I64d", &n, &k);
    for (i = 1; i <= n; ++i) {
        scanf("%I64d", &b[i]);
        e.a[i][i] = 1ll;
    }
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; ++j)
            a.a[i][j] = can(b[i], b[j]);

    t = f(k - 1);
    ans = 0;
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; ++j)
            ans = (ans + t.a[i][j]) % MOD;
    if (ans < 0) ans += MOD;
    printf("%I64d\n", ans);
    return 0;
}