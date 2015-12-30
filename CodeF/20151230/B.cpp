#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

long long a, b;
long long num[63];
long long nu[63];
int i;

long long q(long long n) {
    long long ans = 0;
    int i,j;
    for (i = 1;i <= 62;++i)
        for (j = 0;j < i;++j)
            if (nu[i] - num[j] <= n) ++ans;
    return ans;
}

int main()
{
    num[0] = 1;
    for (i = 1;i<63; ++i) {
        num[i] = num[i-1] * 2;
    }
    nu[0] = 1;
    for (i = 1;i< 63;++i) {
        nu[i] = num[i] + nu[i-1];
    }
    scanf("%I64d%I64d",&a,&b);
    printf("%I64d\n",q(b) - q(a - 1));
    return 0;
}
