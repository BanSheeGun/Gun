#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

long long  n,m;

int main()
{
    scanf("%I64d",&n);
    m = n / 2;
    if (n % 2 == 1)
        m = m - n;
    printf("%I64d\n",m);
    return 0;
}
