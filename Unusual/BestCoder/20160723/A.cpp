#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

int t, ans, n, m;

int main() {
    scanf("%d", &t);
    while (t--) {
        ans = 0;
        scanf("%d%d", &n, &m);
        while (m--) {
            ans += n % 2;
            n /= 2;
            if (n == 0)
                break;
        }
        ans += n;
        printf("%d\n", ans);
    }
    return 0;
}