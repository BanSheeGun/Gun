#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int base = 1000000007;

struct Martix
{
    long long a[100][100];
};

long long a[100];
long long ans[100];
int n,b,k,x,i,j,num;
Martix e;

Martix chen(Martix a,Martix b) {
    Martix c;
    memset(c.a,0,sizeof(c.a));
    int i,j,k;
    for (i = 0;i < x;++i)
        for (j = 0;j < x;++j)
            for (k = 0;k < x;++k) {
                c.a[i][j] += a.a[i][k] * b.a[k][j];
                c.a[i][j] %= base;
            }
    return c;
}

Martix Powa(int n) {
    if (n == 1)
        return e;
    Martix t = Powa(n/2);
    t = chen(t,t);
    if (n%2 == 1)
        t = chen(t,e);
    return t;
}

int main()
{
    scanf("%d%d%d%d",&n,&b,&k,&x);
    memset(a,0,sizeof(a));
    memset(e.a,0,sizeof(e.a));
    for (i = 1;i <= n; ++i) {
        scanf("%d",&num);
        ++a[num % x];
    }
    for (i = 0;i < x; ++i) {
        for (j = 0;j < x;++j)
            e.a[i][(i*10+j) % x] += a[j];
    }
    memset(ans,0,sizeof(ans));
    if (b>1) {
        Martix f = Powa(b-1);
        for (i = 0;i < x;++i)
            for (j = 0;j < x;++j) {
                ans[j] += a[i] * f.a[i][j];
                ans[j] %= base;
            }
        printf("%I64d\n",ans[k]);
    } else {
        printf("%I64d\n",a[k] & base);
    }
    return 0;
}
