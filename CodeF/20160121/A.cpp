#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int a,b,c,d,e,f;

int main()
{
    scanf("%d%d%d%d",&a,&b,&c,&d);
    e = abs(a - c);   
    f = abs(b - d);
    e = max(e, f);
    printf("%d\n",e);   
    return 0;
}
