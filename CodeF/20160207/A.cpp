#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

long long a,b,c,n;

int main()
{
    scanf("%I64d%I64d%I64d%I64d",&n,&a,&b,&c);
    if (n < a && n < b) {
        printf("0\n");
        return 0;
    }
    long long a1 = n / a;
    n -= c;
    long long a2 = n / (b - c);
    n -= a2 * (b - c);
    n += c;
    a2 += max(n/a, n/b); 
    a1 = (a1 > a2)? a1 : a2;
    printf("%I64d\n",a1);
    return 0;
}
