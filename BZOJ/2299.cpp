/**************************************************************
    Problem: 2299
    User: Gunpowder
    Language: C++
    Result: Accepted
    Time:164 ms
    Memory:820 kb
****************************************************************/
 
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
 
ll t, a, b, x, y;
int T;
 
ll gcd(ll a, ll b) {
    return (b) ? gcd(b, a % b) : a;
}
 
inline bool p(ll a, ll b) {
    return (a % t == 0) && (b % t == 0);
}
 
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld%lld%lld", &a, &b, &x, &y);
        a = abs(a);
        b = abs(b);
        t = gcd(2 * a, 2 * b);
        if (p(x, y) || p(x + a, y + b) || p(x + b, y + a) || p(x + a + b, y + a + b))
            puts("Y");
        else
            puts("N");
    }
    return 0;
}