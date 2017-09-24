#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll x, y, a, b, c, num, d;

int main() {
    while (~scanf("%lld%lld", &x, &y)) {
        x -= 1;
        y -= 1;
        if (x < y)
            swap(x, y);
        num = x * y / gcd(x, y);
        a = num / y;
        b = num / x;
        if (b != 1) {
            c = (x + y - 1) / y;
            d = a - c - c + 1;
            if (b != 2) {
                num -= (d % (b-2)) * (b - 1);
                d /= (b - 2);
                num -= d * (b - 2) * (b - 1);
            }
            num -= (c-1) * (b - 1) * 2;
        }
        num++;
        printf("%lld\n", num);
    }
    return 0;
}