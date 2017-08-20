#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
inline ll qm(ll a, ll n, const ll & p) {
    ll ans = 1;
    ll tmp = a;
    while (n != 0) {
        if (n & 1)
            ans = ans * tmp % p;
        n = n >> 1;
        tmp = tmp * tmp % p;
    }
    return ans;
}

int T, i, l, top;
ll ans;
int len[1010];
char a[1010];
ll b[1010];

inline int work() {
    if (a[i] != '(') {
        b[++top] = a[i] - '0';
        len[top] = 1;
        return 0;
    }
    b[++top] = 0;
    len[top] = 0;
    ++i;
    while (a[i] != ')') {
        b[top] = b[top] * 10 + a[i] - '0';
        b[top] %= mod;
        ++len[top];
        ++i;
    }
    return 0;
}


inline int work2() {
    ++i;
    ll tmp = 0;
    if (a[i] != '(') {
        tmp = a[i] - '0';
        len[top] *= tmp;
        ll tmp1 = qm(10, len[top], mod) - 1;
        ll tmp2 = qm(10, tmp, mod) - 1;
        tmp2 = qm(tmp2, mod - 2, mod);
        b[top] = b[top] * tmp1 % mod * tmp2 % mod;
        b[top] = (b[top] % mod) + mod;
        return 0;
    }
    ++i;
    while (a[i] != ')') {
        tmp = tmp * 10 + a[i] - '0';
        ++i;
    } 
    ll tmp2 = qm(10, len[top], mod) - 1;
    len[top] *= tmp;
    ll tmp1 = qm(10, len[top], mod) - 1;
    tmp2 = qm(tmp2, mod - 2, mod);
    tmp1 = tmp1 * tmp2 % mod;
    b[top] = b[top] * tmp1 % mod;
    b[top] = (b[top] % mod + mod) % mod;
    return 0;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%s", a);
        ans = 0;
        l = strlen(a);
        top = 0;
        for (i = 0; i < l; ++i)
            if (a[i] != '#')
                work();
            else
                work2();
        for (i = 1; i <= top; ++i) {
            ans *= qm(10, len[i], mod);
            ans %= mod;
            ans = (ans + b[i])  % mod;
        }
        printf("%lld\n", ans);
    }    
    return 0;
}