#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

inline bool cmp(const int & a, const int & b) {
    return a > b;
}

int a[1000000];
int T, n, ans, i, k;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);
        for (i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        sort(a+1, a+1+n, cmp);
        a[0] = a[1];
        ans = 0;
        i = 1;
        while (i <= n) {
            if (a[i-1] - a[i] <= k)
                ++ans;
            else
                break;
            ++i;
        }
        printf("%d\n", ans);
    }
    return 0;
}