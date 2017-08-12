#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

int T, m, n, i, ans, sum, l, r, rm, lm, mid;
char a[6000];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &m);
        scanf("%s", a);
        n = strlen(a);
        ans = 0;
        for (mid = 0; mid < n; ++mid) {
            l = mid+1;
            r = mid;
            lm = mid;
            rm = mid+1;
            sum = 0;
            while (l != 0 && r != n-1) {
                --l;
                ++r;
                sum += abs(a[l] - a[r]);
                while (sum > m) {
                    sum -= abs(a[lm] - a[rm]);
                    --lm;
                    ++rm;
                }
                ans = max(ans, lm - l + 1);
            }

            l = mid+1;
            r = mid+1;
            lm = mid;
            rm = mid+2;
            sum = 0;
            while (l > 0 && r < n-1) {
                --l;
                ++r;
                sum += abs(a[l] - a[r]);
                while (sum > m) {
                    sum -= abs(a[lm] - a[rm]);
                    --lm;
                    ++rm;
                }
                ans = max(ans, lm - l + 1);
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}