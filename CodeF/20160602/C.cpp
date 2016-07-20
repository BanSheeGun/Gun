#include<cstdio>
#include<cstdlib>
#include<cstring> 
#include<string> 
#include<algorithm> 
using namespace std;

const long long base = 1000000007;
char a[100010];
long long ans, l, i, n, j;

int main() {
    scanf("%s", a);
    l =strlen(a);
    ans = 1;
    for (i = 0; i < l; ++i) {
        if ('0' <= a[i] && a[i] <= '9')
            n = a[i] - 48;
        else
            if ('A' <= a[i] && a[i] <= 'Z')
                n = a[i] - 'A' + 10;
            else
                if ('a' <= a[i] && a[i] <= 'z')
                    n = a[i] - 'a' + 36;
                else 
                    if (a[i] == '-')
                        n = 62;
                    else
                        n = 63;
        for (j = 1; j <= 6; ++j) {
            if (n % 2 == 0) {
                ans *= 3;
                ans %= base;
            }
            n /= 2;
        }
    }
    printf("%I64d\n", ans);
    return 0;
}
