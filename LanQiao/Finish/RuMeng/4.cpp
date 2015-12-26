#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int m = 10007;

int main() {
    int a, b ,c, i, n;
    a = 1;
    b = 0;
    scanf("%d",&n);
    for (i = 2;i <= n;++i) {
        c = a + b;
        b = a;
        a = c;
        a %= m;
        b %= m;
        c %= m;
    }
    printf("%d\n",a);
    return 0;
}
