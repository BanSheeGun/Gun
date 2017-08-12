#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
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

ll p;

vector<ll> a;
inline bool pan_g(int g, int p) {
    for (int i = 0; i < a.size(); ++i)
        if (qm(g, a[i], p) == 1)
            return 0;
    return 1;
}

inline ll findg(int p) {
    int tmp = p - 1;
    int k = 2;
    while (tmp != 1) {
        if (tmp % k == 0) {
            a.push_back(k);
            while (tmp % k == 0)
                tmp /= k;
        }
        ++k;
    }
    for (int i = 0; i < a.size(); ++i)
        a[i] = (p-1) / a[i];
    int g = 1;
    while (true) {
        if (pan_g(g, p)) {
            return g;
        }
        ++g;
    }
    return 0;
}

int main() {
    a.clear();
    scanf("%lld", &p);
    printf("%lld\n", findg(p));
    return 0;
}