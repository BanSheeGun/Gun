#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

char s[100010];
int ans, i, l, tt, z;
int t[90];

int main() {
    scanf("%d", &tt);
    for (z = 1; z <= tt; ++z) {
        ans = 0;
        scanf("%s", s);
        memset(t, 0, sizeof(t));
        l = strlen(s);
        for (i = 0; i < l; ++i)
            if (t[s[i] - 'a'] == 0) {
                ++ans;
                t[s[i] - 'a'] = 1;
            }
        printf("Case #%d: %d\n", z, ans);
    }
    return 0;
}