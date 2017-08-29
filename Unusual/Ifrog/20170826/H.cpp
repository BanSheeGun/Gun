#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

int T;
ll a, b, l, r, x, de;

inline bool pan() {
    ll tmp = de, sum = -b;
    if (sum >= 0)
        return 1;
    while (a != 0) {
        if (a & 1)
            sum += tmp;
        if (sum >= 0)
            return 1;
        a /= 2;
        tmp *= 2;
    }
    return 0;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld%lld", &x, &l, &r);
        a = x / l;
        b = x % l;
        de = r - l;
        if (pan())
            puts("QWQ");
        else
            puts("TAT");
    }
    return 0;
}