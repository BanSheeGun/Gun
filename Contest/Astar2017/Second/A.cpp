#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

int T, n, k, sum, ans;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        n--;
        ans = 1;
        k = 2;
        while (n != 1 && k * k <= n) {
            if (n % k == 0) {
                sum = 0;
                while (n % k == 0) {
                    ++sum;
                    n /= k;
                }
                ans *= (sum + 1);
            }
            ++k;
        }
        if (n != 1)
            ans *= 2;
        printf("%d\n", ans);
    }
    return 0;
}