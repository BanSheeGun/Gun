#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

typedef long long ll;
const ll OO = 1e18;

ll a[10000000];
ll k;
int t, r;

inline bool cmp(ll a, ll b) {
    return a < b;
}

inline int f(ll i, ll now) {
    while (OO / i >= now) {
        now = now * i;
        ++r;
        a[r] = now;
        if (i == 2) {
            f(3, now);
            f(5, now);
        } else
            if (i == 3)
                f(5, now);
    }
    return 0;
}

inline ll find(int l, int r, ll k) {
    if (l == r) return a[l];
    int mid = (l+r) / 2;
    if (a[mid] >= k)
        return find(l, mid, k);
    return find(mid+1, r, k);
}

int main() {
    r = 0;
    f(2, 1);
    f(3, 1);
    f(5, 1);
    sort(a+1, a+r+1, cmp);
    scanf("%d", &t);
    while (t--) {
        scanf("%lld", &k);
        printf("%lld\n", find(1, r, k));
    }
    return 0;
}