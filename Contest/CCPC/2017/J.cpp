#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 3e4;
int prime[N + 10];
int mi[N + 10];
int p[N + 10];
int i, j, top, n, T;
ll ans;
ll mod;
ll f[N + 10];
ll q[N + 10];

int main() {
    memset(p, 0, sizeof(p));
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

    int cnt = 0;
    for (scanf("%d", &T); T != 0; --T) {
        scanf("%d%lld", &n, &mod);
        memset(q, 0, sizeof(q));
        memset(f, 0, sizeof(f));
        ans = 0;
        q[0] = 1;
        q[1] = 1;
        
        for (i = 1; i <= n; ++i) {
            f[i] = (f[i] + 1) % mod;
            ans += f[i] * i % mod;
            ans = (ans % mod + mod) % mod;

            for (j = 2; j * i <= n; ++j) {
                f[j] += mi[j] * f[i] % mod;
                f[j] = (f[j] % mod + mod) % mod;
            }
        }
        printf("Case #%d: %lld\n", ++cnt, ans);
    }
    return 0;
}