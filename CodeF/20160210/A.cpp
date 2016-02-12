#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

long long n, x;

int main()
{
    scanf("%I64d",&x);
    n = 1 + 8 * x;
    n = (-1.0 + sqrt(n)) / 2.0;
    x -= (n + 1) * n / 2;
    if (x == 0)
        printf("%I64d\n",n);
    else
        printf("%I64d\n",x);
    return 0;
}
