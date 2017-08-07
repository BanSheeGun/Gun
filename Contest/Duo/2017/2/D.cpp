#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

int T, ans, n, m, p, N, s;

int main() {
    scanf("%d", &T);
    while (T--) {
        ans = 0;
        scanf("%d%d%d", &n, &m, &p);
        int N = n * m - 1;
        while (N != 0) {
            s = 0;
            n = 1;
            while (n <= N) {
                ans += s * (p - 1);
                ans %= 2;
                s++;
                n = n + p;
            }
            N -= s;
        }
        if (ans % 2 == 0)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}