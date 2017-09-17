#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int i, T;
ll ans, p, q, k;

ll exgcd(ll a,ll b,ll &x,ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return 0;
    }
    exgcd(b, a % b, x, y);
    ll x1 = y;
    ll y1 = x - (a / b) * y;
    x = x1;
    y = y1;
    return 0;
}

inline ll inv(int n) {
    if (n == 0)
        return 1;
    ll x, y;
    exgcd(n, mod, x, y);
    x = x % mod;
    x = (x + mod) % mod;
    return x;
}

const ll MOD = 1e9+7;
 
struct Matrix
{
    ll m[2][2];
    Matrix () {
        memset(m, 0, sizeof(m));
    }
    Matrix (ll a,ll b,ll c,ll d) {
        m[0][0] = a;
        m[0][1] = b;
        m[1][0] = c;
        m[1][1] = d;
    }
    Matrix operator * (Matrix &B) {
        Matrix C;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                for (int k = 0; k < 2; ++k) {
                    C.m[i][j] += m[i][k] * B.m[k][j];
                    C.m[i][j] %= MOD;
                }
        return C;
    }
};

Matrix E(1, 0, 0, 1);
Matrix A(1, 0, 0, 1);

Matrix Pow(int n) {
    if (n == 0)
        return E;
    if (n == 1)
        return A;
    Matrix t;
    t = Pow(n / 2);
    t = t * t;
    if (n & 1)
        t = t * A;
    return t;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld%lld", &p, &q, &k);
        ll a = q * inv(p) % mod;
        ll b = (1 - a + mod) % mod;
        Matrix m(b, a, a, b);
        A = m;
        Matrix n = Pow(k - 1);
        printf("%lld\n", (n.m[0][0] * b +  n.m[0][1] * a) % mod);
    }
    return 0;
}