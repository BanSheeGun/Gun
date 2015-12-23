#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int a[201000];
int b[201000];
int c[201000];
long long int ans;
int n,m,i;
char cc;

int main()
{
    n = 0;
    a[0] = 0;
    while ((cc = getchar()) != '\n') {
        ++n;
        a[n] = (int)cc - 48;
    }
    m = 0;
    b[0] = 0;
    c[0] = 0;
    while ((cc = getchar()) != '\n') {
        ++m;
        b[m] = b[m-1];
        c[m] = c[m-1];
        if (cc == '1') ++b[m];
            else ++c[m];
    }

    ans = 0;
    for (i = 1;i <= n;++i) {
        if (a[i] == 0)
            ans += b[m-n+i] - b[i-1];
        else
            ans += c[m-n+i] - c[i-1];
    }

    printf("%I64d\n",ans);
    return 0;
}
