#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;

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

ll exgcd(ll a,ll b,ll &x,ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll tmp = exgcd(b, a % b, y, x);
    y -= x * (a / b);
    return tmp;
}
struct re{
    ll x;
    int id;
    bool operator < (const re & b) const {
        if (x == b.x)
            return id > b.id;
        return x < b.x;
    }
    bool operator == (const re & b) const {
        return x == b.x;
    }
} rec[100100];

ll bsgs(ll a, ll b, ll p) {
    int i;
    a %= p;
    ll m = ceil(sqrt(p));
    ll tmp, ans = b % p;
    for (i = 0; i <= m; ++i) {
        rec[i].id = i;
        rec[i].x = ans;
        ans = ans * a % p;
    }
    sort(rec, rec+1+m);
    int top = -1;
    for (i = 0; i <= 1+m; ++i)
        if (i == 0 || !(rec[i] == rec[i-1])) {
            rec[++top] = rec[i]; 
        } else {
            rec[top].id = max(rec[top].id, rec[i].id);
        }
    tmp = qm(a, m, p);
    ans = 1;
    int j;
    re tmp1;
    for (i = 1; i <= m; ++i) {
        ans = ans * tmp % p;
        tmp1.id = m+2;
        tmp1.x = ans;
        j = lower_bound(rec, rec+top, tmp1) - rec;
        if (rec[j].x == ans)
            return i * m - rec[j].id;
    }
    return -1;
}
vector<ll> c;
inline bool pan_g(ll g, ll p) {
    for (int i = 0; i < c.size(); ++i)
        if (qm(g, c[i], p) == 1)
            return 0;
    return 1;
}

inline ll findg(ll p) {
    c.clear();
    ll tmp = p - 1;
    ll k = 2;
    while (k * k <= tmp) {
        if (tmp % k == 0) {
            c.push_back(k);
            while (tmp % k == 0)
                tmp /= k;
        }
        ++k;
    }
    if (tmp != 1)
        c.push_back(tmp);
    for (int i = 0; i < c.size(); ++i)
        c[i] = (p-1) / c[i];
    ll g = 1;
    while (true) {
        if (pan_g(g, p)) {
            return g;
        }
        ++g;
    }
    return 0;
}

ll p, a, b, T, ans;
ll aa[1000000];

inline bool cmp(const ll & a, const ll & b) {
    return a < b;
}

inline int work() {
    ll g = findg(p);
    ll t = bsgs(g, b, p);
    if (t == -1)
        return 0;
    ll A = a;
    ll B = p-1;
    ll x, y;
    ll gcd = exgcd(A, B, x, y);
    if (t % gcd != 0)
        return 0;
    x = x * (t / gcd) % B;
    y = B / gcd;
    for (int i = 0; i < gcd; ++i) {
        x = ((x + y) % B + B) % B;
        aa[++ans] = qm(g, x, p);
    }
    sort(aa+1, aa+1+ans, cmp);
    ll tmp = ans;
    aa[0] = -1;
    ans = 0;
    for (int i = 1; i <= tmp; ++i)
        if (aa[i] != aa[i-1])
            aa[++ans] = aa[i];
    return 0;
}

int main() {
    scanf("%lld", &T);
    while (T--) {
        ans = 0;
        scanf("%lld%lld%lld", &p, &a, &b);
        work();
        if (ans == 0)
            puts("No Solution");
        else {
            for (int i = 1; i < ans; ++i)
                printf("%lld ", aa[i]);
            printf("%lld\n", aa[ans]);
        }
    }
    return 0;
}