#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int a[10];

int s(int n) {
    int sum = 0;
    int m = n;
    while (n != 0) {
        sum += a[n % 10];
        n = n / 10;
    }
    return sum;
}

int main()
{
    a[0] = 6;
    a[1] = 2;
    a[2] = 5;
    a[3] = 5;
    a[4] = 4;
    a[5] = 5;
    a[6] = 6;
    a[7] = 3;
    a[8] = 7;
    a[9] = 6;
    int n, m, i, ans = 0;
    scanf("%d%d",&n,&m);
    for (i = n;i <= m;++i) {
        ans += s(i);
    }
    printf("%d\n",ans);
    return 0;
}
