#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int MOD = 1000000007;

long long n, t;

inline int f(int n) {
    long long t = 1;
    for (int i = 1; i <= n; ++i)
        t = t * 2 % MOD;
    return t;
}

int main() {
    scanf("%lld", &n);
    t = f(n - 2);
    t = t * (n+1) % MOD;
    if (t<0) t = t + MOD;
    printf("%lld\n", t);
    return 0;
}