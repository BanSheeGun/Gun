#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

int a[10000010];
const int N = 1e7;
int now, l, i, T, n;

int main() {
    a[1] = 1;
    a[2] = 2;
    a[3] = 2;
    l = 3;
    now = 2;
    for (i = 3; i <= N && l <= N; ++i) {
        now = 3 - now;
        if (a[i] == 1) {
            a[++l] = now;
        } else {
            a[++l] = now;
            a[++l] = now;
        }
    }

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("%d\n", a[n]);
    }
    return 0;
}