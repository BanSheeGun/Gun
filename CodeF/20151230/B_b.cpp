#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

long long q(long long n) {
    long long m = n;
    if (n == 0) return 0;
    long long ans = 0;
    long long t = 0;
    long long b = 0;
    while (m != 0) {
        if (m % 2 == 0) {
            b++;
            ans = t;
        }
        ++t;
        m = m / 2;
    }
    ans = t * (t - 1) / 2 -ans;
    if (b == 1) ++ans;
    return ans;
}

long long a, b;

int main()
{
    scanf("%lld%lld",&a,&b);
    printf("%lld\n",q(b) - q(a - 1));
    return 0;
}
