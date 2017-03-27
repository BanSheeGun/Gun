#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

ll ans, i, now, n, l;
ll t[300];
ll nxt[300];

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int make(ll a) {
    if (ans == 0) ans = 1;
    ll tmp = gcd(ans, a);
    ans = ans * a / tmp;
    return 0;
}

int main() {
    ans = 0;
    int flag = 1;
    scanf("%lld", &n);
    for (i = 1; i <= n; ++i)
        scanf("%lld", &nxt[i]);

    for (i = 1; i <= n; ++i) {
        l = 1;
        memset(t, 0, sizeof(t));
        t[i] = 1;
        for (now = i; t[nxt[now]] == 0; now = nxt[now], ++l) {
            t[nxt[now]] = t[now] + 1;
        }
        l = l - t[nxt[now]];
        if (nxt[now] != i) { flag = 0; continue;}
        l += 1;
        if (l % 2 == 0)
            make(l / 2);
        else
            make(l);
    }
    if (ans == 0 || !flag) ans = -1;
    printf("%lld\n", ans);
    return 0;
}