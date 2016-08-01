#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

inline int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int a, b;
long long ans;

int main() {
    scanf("%d%d", &a, &b);
    ans = 1ll * a * b / gcd(a,b);
    printf("%lld\n", ans);
    return 0;
}