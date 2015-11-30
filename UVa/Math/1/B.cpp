#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

typedef long long ll;

ll n,i;
ll f[1000010];

int main() {
    scanf("%lld",&n);
    f[3] = 0;
    for (i = 4; i <= 1000000; ++i) {
        f[i] = f[i-1] + ((i - 1) * (i - 2) / 2 - (i - 1) / 2) / 2;
    }
    while (n >= 3) {
        printf("%lld\n",f[n]);
        scanf("%lld",&n);
    }
    return 0;
}
