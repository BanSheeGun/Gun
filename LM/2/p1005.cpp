#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<map>
using namespace std;

int T, TT, a, n, b, ans, i, m;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    scanf("%d", &T); TT = 0;
    while (T--) {
        ++TT;
        scanf("%d%d%d", &n, &a, &b);
        ans = n / gcd(a, b);
        if (ans % 2 == 1) 
            printf("Case #%d: Yuwgna\n", TT);
        else
            printf("Case #%d: Iaka\n", TT);
    }
    return 0;
}