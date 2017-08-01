#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

int s, k;
char a[1000010];
int b[30];
int i, l, de, ans;

int main() {
    scanf("%d", &k);
    scanf("%s", a);
    memset(b, 0, sizeof(b));
    l = strlen(a);
    s = 0;
    for (i = 0; i < l; ++i) {
        s += a[i] - '0';
        b[a[i] -'0']++;
    }
    ans = 0;
    i = 0;
    while (s < k && i != 9) {
        de = 9 - i;
        de = (k - s + de - 1) / de;
        de = min(de, b[i]);
        s += (9 - i) * de;
        ans += de;
        ++i;
    }
    printf("%d\n", ans);
    return 0;
}