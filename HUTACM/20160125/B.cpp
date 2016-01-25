#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

long long n;

int main()
{
    while (~scanf("%I64d",&n))
        printf("%I64d\n\n",n * (n + 1) / 2);
    return 0;
}
