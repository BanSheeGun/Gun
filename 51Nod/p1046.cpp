#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

ll a, b, c;

ll f(ll a, ll b, ll c) {
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    ll t = f(a, b / 2, c);
    t = t * t % c;
    if (b & 1)
        t = t * a % c;
    return t;
}

int main() {
    scanf("%lld%lld%lld", &a, &b, &c);
    printf("%lld\n", f(a, b, c));
	return 0;
}