#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
int read_p,read_ca;
inline int read(){
    read_p=0;read_ca=getchar();
    while(read_ca<'0'||read_ca>'9') read_ca=getchar();
    while(read_ca>='0'&&read_ca<='9') read_p=read_p*10+read_ca-48,read_ca=getchar();
    return read_p;
}

inline ll qm(int a, int n, const int & p) {
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

const int M = 65535, A = 2939;
ll rx[M + 10];
int ls[M + 10], LS = 0;
int ry[M + 10];

inline void ins(int x, int i) {
    int now = x & M;
    while (ls[now] == LS && rx[now] != x)
        now = now + A & M;
    ls[now] = LS;
    rx[now] = x;
    ry[now] = i;
    return;
}

inline int find(int x) {
    int now = x & M;
    while (ls[now] == LS) {
        if (rx[now] == x)
            return ry[now];
        now = now + A & M;
    }
    return -1;
}

ll bsgs(ll a, ll b, ll p) {
    LS++;
    register int i;
    a %= p;
    ll m = ceil(sqrt(p));
    ll tmp, ans = b % p;
    for (i = 0; i <= m; ++i) {
        ins(ans, i);
        ans = ans * a % p;
    }
    tmp = qm(a, m, p);
    ans = 1;
    for (i = 1; i <= m; ++i) {
        ans = ans * tmp % p;
        int j = find(ans);
        if (j != -1)
            return i * m - j;
    }
    return -1;
}
ll c[1000];
inline bool pan_g(int g, int p) {
    for (int i = 1; i <= c[0]; ++i)
        if (qm(g, c[i], p) == 1)
            return 0;
    return 1;
}

inline ll findg(int p) {
    c[0] = 0;
    int tmp = p - 1;
    register int k = 2;
    while (k * k <= tmp && tmp != 1) {
        if (tmp % k == 0) {
            c[++c[0]] = k;
            while (tmp % k == 0)
                tmp /= k;
        }
        ++k;
    }
    if (tmp != 1)
        c[++c[0]] = tmp;
    for (int i = 1; i <= c[0]; ++i)
        c[i] = (p-1) / c[i];
    ll g = 2;
    while (true) {
        if (pan_g(g, p)) {
            return g;
        }
        ++g;
    }
    return 0;
}

ll T, ans;
int p, a, b;
int aa[1000000];

inline bool cmp(const int & a, const int & b) {
    return a < b;
}

inline int work() {
    ll g = findg(p);
    ll t = bsgs(g, b, p);
    if (t == -1)
        return 0;
    for (ll i = 0; i < 3; ++i)
        if ((t + i * (p - 1)) % 3 == 0) {
            aa[++ans] = qm(g, (t + i * (p - 1)) / 3, p);
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
    T = read();
    a = 3;
    while (T--) {
        ans = 0;
        p = read();
        b = read();     
        if (p % 6 == 5){
            if (qm(b, p >> 1, p) == 1)
                printf("%lld\n",qm(b,p/6+1,p));
            else
                printf("%lld\n",(p-qm(b,p/6+1,p))%p);
            continue;
        } else 
            if (p>3 && p%6==1)
                if (qm(b, p/3, p)!=1) {
                    printf("No Solution\n");
                    continue;
                }
        work();
        if (ans == 0)
            puts("No Solution");
        else {
            for (int i = 1; i < ans; ++i)
                printf("%d ", aa[i]);
            printf("%d\n", aa[ans]);
        }
    }
    return 0;
}