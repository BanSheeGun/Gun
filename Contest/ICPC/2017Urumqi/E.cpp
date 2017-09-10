#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

ll ans[30] = {1, 1,8,49,288,1681,9800,57121,332928,1940449,
          11309768,65918161,384199200,2239277041,13051463048,
          76069501249,443365544448,2584123765441,15061377048200,
          87784138523761,511643454094368,2982076586042449};

int cnt, T;
ll N, i;

int main() {
    cnt = 0;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld", &N);
        for (i = 1; i <= 30; ++i)
            if (ans[i] >= N) {
                printf("Case #%d: %lld\n", ++cnt, ans[i]);
                break;
            }
    }
    return 0;
}