#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int T, n, i, b;
int c[10000];
int d[10000];
int s, OK;

int main() {
    scanf("%d", &T);
    while (T--) {
        OK = 1;
        scanf("%d%d", &n, &b);
        for (i = 1; i <= n; ++i)
            scanf("%d", &c[i]);
        for (i = 1; i < n; ++i)
            scanf("%d", &d[i]);

        s = 0;
        for (i = 1; i <= (n - 1); ++i) {
            s += c[i];
            if (s < d[i] * b) {
                OK = 0;
                break;
            }
            s -= d[i] * b;
        }
        if (OK)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}