#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

const int base = 1000000007;
int n, ans, i;
long long a, b;

int main() {
    scanf("%d", &n);
    a = 1;
    b = 1;
    for (i = 1; i <= n; ++i) {
        a = a * 27 % base;
        b = b * 7 % base;
    }
    ans = a - b;
    if (ans < 0)
        ans = ans + base;
    ans = ans % base;
    printf("%d\n", ans);
    return 0;
}
