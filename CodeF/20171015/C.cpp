#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int ans, x, n;

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        if ((x % 2 == 1 && x < 9) || x == 11 || x < 4) {
            printf("-1\n");
            continue;
        } else {
            ans = 0;
            if (x % 2 == 1) {
                x -= 9;
                ++ans;
            }
            x /= 2;
            ans += x / 2;
            printf("%d\n", ans);
        }
    }
    return 0;
}