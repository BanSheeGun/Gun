#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int l, i, TT, T, ans;
char a[10010];
int t[60];

int main() {
    scanf("%d", &T); TT = 0;
    while (T--) {
        TT++;
        scanf("%s", a);
        ans = 10000000; l = strlen(a);
        memset(t, 0, sizeof(t));
        for (i = 0; i < l; ++i) {
            if (t[a[i] - 'a'] != 0)
                ans = min(ans, i+1-t[a[i] - 'a']);
            t[a[i] - 'a'] = i+1;
        }
        if (ans == 10000000) ans = -1;
        printf("Case #%d: %d\n", TT, ans);
    }
    return 0;
}