#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

int a, la, n, aa, ans, i;

int main() {
    scanf("%d", &n);
    la = 0;
    ans = 0;
    aa = 0;
    for (i = 1; i <= n; ++i) {
        scanf("%d", &a);
        if (a > la) {
            ++ans;
        } else {
            ans = 1;
        }
        aa = max(ans, aa);
        la = a;
    }
    printf("%d\n", aa);
    return 0;
}