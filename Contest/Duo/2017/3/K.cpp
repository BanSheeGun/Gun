#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

int ans, t, k;

int main() {
    ans = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &k);
        ans += (k <= 35);
    }
    printf("%d\n", ans);
    return 0;
}