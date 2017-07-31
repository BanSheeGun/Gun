#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

int T;
char a[1100100];
ll ans, i, n, top, t;
ll x[1100100];
ll y[1100100];
ll f[1100100];

int main() {
    scanf("%d", &T);
    while (T--) {
        ans = 0;
        scanf("%s", a);
        n = strlen(a);
        top = 0;
        t = 0;
        for (i = 0; i < n; ++i) {
            if (a[i] == ')') {
                bool cg = 0;
                if (t == 0) {
                    if (i > 0 && a[i-1] == '(') {
                        ++top;
                        ans++;
                        x[top] = i - 1;
                        y[top] = i;
                        f[top] = 1;
                        cg = 1;
                        t = 1;
                    } else {
                        t = 0;
                    }
                } else {
                    if (x[top] > 0 && a[x[top] - 1] == '(') {
                        ans++;
                        x[top]--;
                        y[top]++;
                        f[top] = 1;
                        cg = 1;
                        t = 1;
                    } else {
                        t = 0;
                    }
                }
                if (cg) {
                    if (top > 1 && x[top] - 1 == y[top-1]) {
                        y[top - 1] = y[top];
                        top--;
                        ans += f[top];
                        f[top]++;
                        t = 1;
                    }
                }
            } else {
                t = 0;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}