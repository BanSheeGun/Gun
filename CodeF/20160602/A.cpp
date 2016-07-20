#include<cstdio>
#include<cstdlib>
#include<cstring> 
#include<string> 
#include<algorithm> 
using namespace std;

int ans, n, h, k;

int main() {
    scanf("%d%d", &n, &h);
    ans = 0;
    while (n--) {
        scanf("%d", &k);
        if (k <= h)
            ++ans;
        else
            ans = ans + 2;
    }
    printf("%d\n", ans);
    return 0;
}
