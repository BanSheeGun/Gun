#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int N = 1e6 + 7;
int top, n, i, j;
int p[N + 10];
int f[N + 10];
int nxt[N + 10];
ll s[N + 10], ans;

inline void init() {
    top = 0;
    memset(f, 0, sizeof(f));
    for (i = 2; i <= N; ++i) {
        if (!f[i]) {
            p[++top] = i;
            nxt[i] = top;
        }
        for (j = 1; j <= top && i * p[j] <= N; ++j) {
            f[i * p[j]] = 1;
            nxt[i * p[j]] = j;
            if (i % p[j] == 0)
                break;
        } 
    }
    return;
}

inline void work(int n) {
    while (n != 1) {
        ++s[nxt[n]];
        n /= p[nxt[n]];
    }
    return;
}

int main() {
    memset(s, 0, sizeof(s));
    init();
    scanf("%d", &n);
    for (i = 1; i <= n; ++i)
        work(i);
    ans = 1;
    for (i = 1; i <= top; ++i)
        ans = ans * (s[i] * 2 + 1) % mod;
    printf("%lld\n", ans);
    return 0;
}